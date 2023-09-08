#include "battleManager.h"

#include <random>

#include "./src/manager/allyManager.h"
#include "./src/manager/enemyManager.h"
#include "./src/manager/playerInfoManager.h"
#include "./src/manager/skillManager.h"

#include "./src/content/combatUnits/enemy/enemy.h"
#include "./src/content/combatUnits/ally/ally.h"

#include "./src/utils/playerUtils.h"
#include "./src/utils/debugUtils.h"

BattleManager::BattleManager(
    AllyManager& allyM,
    EnemyManager& enemyM,
    PlayerInfoManager& playerM,
    SkillManager& skillM) :
    m_allyM(allyM), m_enemyM(enemyM), m_playerM(playerM), m_skillM(skillM)
{}

BattleManager::~BattleManager() {}

BattleManager& BattleManager::getInstance(
    AllyManager& allyM,
    EnemyManager& enemyM,
    PlayerInfoManager& playerM,
    SkillManager& skillM)
{
    static BattleManager instance(allyM, enemyM, playerM, skillM);
    return instance;
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
    DEBUG(DB_GENERAL, "populateEnemyBattle... random enemy id is %d\n", random_enemy);

    m_enemyBattle.push_back(m_enemyM.getEnemy(random_enemy));
}

const std::vector<Ally>& BattleManager::getAllyBattle() const {
    return m_allyBattle;
}

const std::vector<Enemy>& BattleManager::getEnemyBattle() const {
    return m_enemyBattle;
}

void BattleManager::prepareBattle() {
    populateAllyBattle();
    populateEnemyBattle();
}

void BattleManager::endBattle() {
    m_allyBattle.clear();
    m_enemyBattle.clear();
}