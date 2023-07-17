#include <iostream>
#include "./src/content/combatUnits/ally/ally.h"
#include "./src/content/combatUnits/enemy/enemy.h"
#include "./src/content/combatUnits/unitAttributes/skill.h"

#include "./src/manager/allyManager.h"
#include "./src/manager/enemyManager.h"
#include "./src/manager/playerInfoManager.h"
#include "./src/manager/skillManager.h"

#include "./src/utils/debugUtils.h"

unsigned int dbflags = DB_GENERAL;

int main()
{
    std::cout << "compiled" << std::endl;
    EnemyManager& c1 = EnemyManager::getInstance();
    AllyManager& a1 = AllyManager::getInstance();
    SkillManager& s1 = SkillManager::getInstance();

    PlayerInfoManager& p1 = PlayerInfoManager::getInstance(a1);

    Enemy& them = c1.getEnemy(2);

    std::cout << a1.getTotalPlayableAllies() << std::endl;
    p1.addMemberToParty(0);
    p1.addMemberToParty(1);
    p1.debugPrintPartyInfo();
    // them.debugPrintUnitInfo();
    // s1.getSkill(2).debugPrintSkill();
    return 0;
}