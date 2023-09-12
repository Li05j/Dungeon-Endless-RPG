#include "battleManager.h"

#include <algorithm>
#include <random>

#include "./src/manager/allyManager.h"
#include "./src/manager/enemyManager.h"
#include "./src/manager/playerInfoManager.h"
#include "./src/manager/skillManager.h"
#include "./src/manager/battleLoggerManager.h"

#include "./src/content/combatUnits/enemy/enemy.h"
#include "./src/content/combatUnits/ally/ally.h"

#include "./src/utils/debugUtils.h"
#include "./src/utils/helperUtils.h"
#include "./src/utils/playerUtils.h"

BattleManager::BattleManager(
    AllyManager& allyM,
    EnemyManager& enemyM,
    PlayerInfoManager& playerM,
    SkillManager& skillM,
    BattleLoggerManager& battleLogM) :
    m_allyM(allyM), m_enemyM(enemyM), m_playerM(playerM), m_skillM(skillM), m_battleLogM(battleLogM), m_turn_counter(0), m_gameover(0), m_victory(0)
{}

BattleManager::~BattleManager() {}

BattleManager& BattleManager::getInstance(
    AllyManager& allyM,
    EnemyManager& enemyM,
    PlayerInfoManager& playerM,
    SkillManager& skillM,
    BattleLoggerManager& battleLogM)
{
    static BattleManager instance(allyM, enemyM, playerM, skillM, battleLogM);
    return instance;
}

std::string BattleManager::damageLog(std::string subject, std::string object, int damage, bool crit)
{
    std::string log = std::string();
    if (!crit) {
        log = subject + " dealt " + std::to_string(damage) + " damage to " + object + " !";
    }
    return log;
}

void BattleManager::addObserver(ObserverIface* observer) {
    m_observer = observer;
}

void BattleManager::removeObserver(ObserverIface* observer) {
    // shouldn't need this ever
    return;
}

void BattleManager::notifyObservers() {
    m_observer->update();
    wait(1);
}

void BattleManager::populateAllyBattle() {
    const std::vector<int>& playerParty = m_playerM.getPlayerParty();
    int allyCount = 0;
    for (int i = 0; i < TOTAL_ALLY; i++) {
        if (playerParty.at(i)) {
            m_allyBattle.push_back(m_allyM.getAlly(i));
            allyCount++;
        }
    }

    if (allyCount > MAX_PARTY_SIZE) {
        DEBUG(DB_GENERAL, "ERROR -- populateEnemyBattle(): too many allies, ally count: %d", allyCount);
    }
}

void BattleManager::populateEnemyBattle() {
    // TODO: random multiple enemies
    // TODO: will need to check level/location etc to get appropriate enemies

    // Seed the random number generator with a random device
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the range for your random number
    std::uniform_int_distribution<int> distribution(1, 2);

    // Generate a random number
    int random_enemy = distribution(gen);
    // DEBUG(DB_GENERAL, "populateEnemyBattle... random enemy id is %d\n", random_enemy);

    m_enemyBattle.push_back(m_enemyM.getEnemy(random_enemy));
}

const int BattleManager::getTurn() const
{
    return m_turn_counter;
}

const std::vector<Ally>& BattleManager::getAllyBattle() const {
    return m_allyBattle;
}

const std::vector<Enemy>& BattleManager::getEnemyBattle() const {
    return m_enemyBattle;
}

const std::deque<std::string>& BattleManager::getBattleLogs() const
{
    return m_battleLogM.getBattleLogs();
}

// void BattleManager::pushLog(std::string log)
// {
//     m_battleLogM.pushBattleLog(log);
// }

void BattleManager::prepareBattle() {
    m_turn_counter = 0;
    populateAllyBattle();
    populateEnemyBattle();
    notifyObservers();
    startBattle();
}

void BattleManager::startBattle()
{
    while (!isEndBattle()) {
        incrementTurn();
        preTurn();
        duringTurn();
        postTurn();
    }
    endBattle();
}

void BattleManager::preTurn()
{
    m_move_order.clear();
    determineMoveOrder();
    // wait(1);
}

void BattleManager::duringTurn()
{
    // attack
    for (auto& unit : m_move_order) {
        // TODO: below is dummy damage calculation. need to replace it to a meaningful one.
        auto& ally = m_allyBattle.at(0);
        auto& enemy = m_enemyBattle.at(0);

        if (unit->getUnitType() == ALLY_UNIT) {
            useDefaultAttack(ally, enemy, 20);
        }
        else if (unit->getUnitType() == ENEMY_UNIT) {
            useDefaultAttack(enemy, ally, 20);
        }
        else {
            // should'nt end up here
            DEBUG(DB_GENERAL, "ERROR - unknown unit... name: %s\n", unit->getName().c_str());
        }
        notifyObservers();
        checkEnemyPartyWipe();
        checkAllyPartyWipe();
    }
}

void BattleManager::postTurn()
{
    // do nothing for now;
    // wait(1);
}

void BattleManager::checkAllyPartyWipe()
{
    for (auto& unit : m_allyBattle) {
        if (unit.getOneBParam(B_CURRHP) > 0) {
            return;
        }
    }
    m_gameover = 1;
    m_move_order.clear();
}

void BattleManager::checkEnemyPartyWipe()
{
    for (auto& unit : m_enemyBattle) {
        if (unit.getOneBParam(B_CURRHP) > 0) {
            return;
        }
    }
    m_victory = 1;
    m_move_order.clear();
}

bool BattleManager::isEndBattle()
{
    // DEBUG(DB_GENERAL, "Note -- isEndBattle(): gameover?: %d, victory?: %d\n", m_gameover, m_victory);
    if (m_gameover || m_victory) {
        return true;
    }
    return false;
}

void BattleManager::determineMoveOrder()
{
    for (auto& unit : m_allyBattle) {
        m_move_order.push_back(&unit);
    }
    for (auto& unit : m_enemyBattle) {
        m_move_order.push_back(&unit);
    }

    std::sort(m_move_order.begin(), m_move_order.end(), [](CombatUnits* a, CombatUnits* b) {
        return a->getOneBParam(BasicParamType::B_SPD) > b->getOneBParam(BasicParamType::B_SPD);
        });
}

void BattleManager::incrementTurn()
{
    m_turn_counter++;
    notifyObservers();
}

void BattleManager::useDefaultAttack(CombatUnits& subject, CombatUnits& object, int damage)
{
    int objectCurrHp = object.getOneBParam(B_CURRHP);
    object.setBParam(B_CURRHP, objectCurrHp - 20);
    m_battleLogM.pushBattleLog(damageLog(subject.getName(), object.getName(), 20)); // dummy damage number
}

void BattleManager::endBattle() {
    m_allyBattle.clear();
    m_enemyBattle.clear();
}