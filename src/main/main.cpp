#include <iostream>
#include "./src/content/combatUnits/ally/ally.h"
#include "./src/content/combatUnits/enemy/enemy.h"
#include "./src/content/combatUnits/unitAttributes/skill.h"

#include "./src/manager/allyManager.h"
#include "./src/manager/enemyManager.h"
#include "./src/manager/battleManager.h"
#include "./src/manager/playerInfoManager.h"
#include "./src/manager/skillManager.h"

#include "./src/view/battleView.h"

#include "./src/utils/debugUtils.h"

unsigned int dbflags = DB_GENERAL;

int main()
{
    std::cout << "compiled" << std::endl;
    AllyManager& a1 = AllyManager::getInstance();
    EnemyManager& e1 = EnemyManager::getInstance();
    SkillManager& s1 = SkillManager::getInstance();

    PlayerInfoManager& p1 = PlayerInfoManager::getInstance(a1);
    BattleManager& b1 = BattleManager::getInstance(a1, e1, p1, s1);

    BattleView& v1 = BattleView::getInstance(b1);

    // a1.debugPrintManagerInfo();

    Enemy& them = e1.getEnemy(2);

    // std::cout << a1.getTotalPlayableAllies() << std::endl;
    p1.addMemberToParty(1);
    // p1.addMemberToParty(0);
    p1.debugPrintPartyInfo();
    // them.debugPrintUnitInfo();
    // s1.getSkill(2).debugPrintSkill();

    b1.prepareBattle();
    auto allyBattle = b1.getAllyBattle();
    auto enemyBattle = b1.getEnemyBattle();

    std::cout << "Battle Starts!" << std::endl;
    std::cout << "Your party..." << std::endl;
    for (auto ally : allyBattle) {
        ally.debugPrintUnitInfo();
    }
    std::cout << "Enemey's party..." << std::endl;
    for (auto enemy : enemyBattle) {
        enemy.debugPrintUnitInfo();
    }
    std::cout << "Battle Ends!" << std::endl;
    b1.endBattle();


    allyBattle = b1.getAllyBattle();
    enemyBattle = b1.getEnemyBattle();
    std::cout << "Checking if battle ended or not..." << std::endl;
    for (auto ally : allyBattle) {
        ally.debugPrintUnitInfo();
    }
    std::cout << "Enemey's party..." << std::endl;
    for (auto enemy : enemyBattle) {
        enemy.debugPrintUnitInfo();
    }
    std::cout << "Battle ended succesfully!" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    v1.init();
    return 0;
}