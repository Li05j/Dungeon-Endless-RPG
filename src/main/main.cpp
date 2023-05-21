#include <iostream>
#include "./src/data/combatUnits/ally/ally.h"
#include "./src/data/combatUnits/enemy/enemy.h"
#include "./src/manager/enemyManager.h"
#include "./src/manager/playerInfoManager.h"

#include "./src/utils/debugUtils.h"

unsigned int dbflags = DB_GENERAL;

int main()
{
    std::cout << "compiled" << std::endl;
    EnemyManager& c1 = EnemyManager::getInstance();
    PlayerInfoManager& p1 = PlayerInfoManager::getInstance();
    Enemy& them = c1.getEnemy(2);
    p1.addMemberToParty(0);
    // Ally me;
    p1.getAlly(1).printUnitInfo();
    them.printUnitInfo();
    return 0;
}