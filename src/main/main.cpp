#include <iostream>
#include "./src/content/combatUnits/ally/ally.h"
#include "./src/content/combatUnits/enemy/enemy.h"
#include "./src/content/combatUnits/unitAttributes/skill.h"

#include "./src/manager/enemyManager.h"
#include "./src/manager/playerInfoManager.h"
#include "./src/manager/skillManager.h"

#include "./src/utils/debugUtils.h"

unsigned int dbflags = DB_GENERAL;

int main()
{
    std::cout << "compiled" << std::endl;
    EnemyManager& c1 = EnemyManager::getInstance();
    PlayerInfoManager& p1 = PlayerInfoManager::getInstance();
    SkillManager& s1 = SkillManager::getInstance();
    Enemy& them = c1.getEnemy(2);
    p1.addMemberToParty(0);
    // Ally me;
    p1.getAlly(1).printUnitInfo();
    them.printUnitInfo();
    s1.getSkill(2).debugPrintSkill();
    return 0;
}