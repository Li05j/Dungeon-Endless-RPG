#include "enemyController.h"

#include "./src/utils/debugUtils.h"
#include "./src/data/combatUnits/enemy/enemy.h"

EnemyController::EnemyController() {}

EnemyController::~EnemyController() {}

EnemyController& EnemyController::getInstance() {
    static EnemyController instance;
    return instance;
}


std::shared_ptr<Enemy> EnemyController::getEnemyData(int enemyId) {
    DEBUG(DB_GENERAL, "getEnemyData() called %d\n", enemyId);
    return std::make_shared<Enemy>();
}