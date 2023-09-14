#include "battleModel.h"

#include <algorithm>

#include "./src/blueprint/combatUnits/enemy/enemy.h"
#include "./src/blueprint/combatUnits/ally/ally.h"

#include "./src/utils/debugUtils.h"
#include "./src/utils/helperUtils.h"

BattleModel::BattleModel() : m_turn_counter(0), m_gameover(0), m_victory(0) {}

BattleModel::~BattleModel() {}

BattleModel& BattleModel::getInstance() {
    static BattleModel instance;
    return instance;
}

void BattleModel::addObserver(ObserverIface* observer) {
    m_observer = observer;
}

void BattleModel::removeObserver(ObserverIface* observer) {
    // shouldn't need this ever
    return;
}

void BattleModel::notifyObservers() {
    m_observer->update();
    wait(1);
}

const int BattleModel::getTurn() const
{
    return m_turn_counter;
}

const std::vector<Ally>& BattleModel::getAllyBattle() const {
    return m_allyBattle;
}

const std::vector<Enemy>& BattleModel::getEnemyBattle() const {
    return m_enemyBattle;
}

std::vector<CombatUnits*>& BattleModel::getMoveOrder()
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
    return m_move_order;
}

const bool BattleModel::isBattleEnd() const
{
    if (m_gameover || m_victory) {
        return true;
    }
    return false;
}

void BattleModel::resetAllyBattle()
{
    m_allyBattle.clear();
}

void BattleModel::resetEnemyBattle()
{
    m_enemyBattle.clear();
}

void BattleModel::resetMoveOrder()
{
    m_move_order.clear();
}

void BattleModel::pushAllyForBattle(Ally ally) {
    m_allyBattle.push_back(ally);
}

void BattleModel::pushEnemyForBattle(Enemy enemy) {
    m_enemyBattle.push_back(enemy);
}

// void BattleModel::pushUnitsForMoveOrder(CombatUnits* unit) {
//     m_move_order.push_back(unit);
// }

void BattleModel::incrementTurnCounter() {
    m_turn_counter++;
    notifyObservers();
}

void BattleModel::resetTurnCounter() {
    m_turn_counter = 0;
}

void BattleModel::gameOver() {
    m_gameover = true;
}

void BattleModel::battleVictory() {
    m_victory = true;
}

void BattleModel::resetbattleVictory() {
    m_victory = false;
}

void BattleModel::changeUnitParam(UnitType type, int which, int change)
{
    if (type == ALLY_UNIT) {
        auto& unit = m_allyBattle.at(which);
        int unitCurrHp = unit.getOneBParam(B_CURRHP);
        unit.setBParam(B_CURRHP, unitCurrHp + change);
    }
    else if (type == ENEMY_UNIT) {
        auto& unit = m_enemyBattle.at(which);
        int unitCurrHp = unit.getOneBParam(B_CURRHP);
        unit.setBParam(B_CURRHP, unitCurrHp + change);
    }
    else {
        // should'nt end up here
        DEBUG(DB_GENERAL, "ERROR - invalid type in BattleModel::setUnitParam().\n");
    }
    notifyObservers();
}

// void BattleModel::pushLog(std::string log)
// {
//     m_battleLogM.pushBattleLog(log);
// }
