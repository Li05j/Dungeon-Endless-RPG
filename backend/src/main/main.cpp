#include <iostream>
#include "./src/blueprint/combatUnits/ally/ally.h"
#include "./src/blueprint/combatUnits/enemy/enemy.h"
#include "./src/blueprint/combatUnits/unitAttributes/skill.h"

#include "./src/controller/battleController.h"

#include "./src/model/allyModel.h"
#include "./src/model/enemyModel.h"
#include "./src/model/battleModel.h"
#include "./src/model/playerInfoModel.h"
#include "./src/model/skillModel.h"
#include "./src/model/battleLoggerModel.h"

#include "./src/view/battleView.h"

#include "./src/utils/debugUtils.h"

unsigned int dbflags = DB_GENERAL;

int main()
{
    std::cout << "compiled" << std::endl;

    BattleLoggerModel& l1 = BattleLoggerModel::getInstance();

    AllyModel& a1 = AllyModel::getInstance();
    EnemyModel& e1 = EnemyModel::getInstance();
    SkillModel& s1 = SkillModel::getInstance();

    PlayerInfoModel& p1 = PlayerInfoModel::getInstance(a1);
    BattleModel& b1 = BattleModel::getInstance();

    BattleController& c1 = BattleController::getInstance(b1, a1, e1, p1, l1);

    BattleView& v1 = BattleView::getInstance(b1, c1);

    a1.debugPrintModelInfo();

    Enemy& them = e1.getEnemy(2);
    p1.addMemberToParty(1);
    p1.debugPrintPartyInfo();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    v1.init();
    return 0;
}