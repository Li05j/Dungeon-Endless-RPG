#include <iostream>

// #include "./include/crow.h"

#include "./src/blueprint/combatUnits/ally/ally.h"
#include "./src/blueprint/combatUnits/enemy/enemy.h"
#include "./src/blueprint/combatUnits/unitAttributes/skill.h"

#include "./src/controller/battleController.h"
#include "./src/controller/battleControllerV2.h"

#include "./src/interface/battleResponseIface.h"

#include "./src/model/allyModel.h"
#include "./src/model/enemyModel.h"
#include "./src/model/battleModel.h"
#include "./src/model/playerInfoModel.h"
#include "./src/model/skillModel.h"
#include "./src/model/battleLoggerModel.h"

#include "./src/routes/routes.h"

#include "./src/view/battleView.h"
#include "./src/view/battleViewV2.h"

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

    BattleControllerV2& c2 = BattleControllerV2::getInstance(b1, a1, e1, p1, l1);
    BattleViewV2& v2 = BattleViewV2::getInstance(b1, c2);

    Routes routes = Routes(c2); // singleton?

    // a1.debugPrintModelInfo();

    // Enemy& them = e1.getEnemy(2);
    p1.addMemberToParty(1);
    // p1.debugPrintPartyInfo();

    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;

    // v1.init();

    ///////////////////////////////////

    // crow::SimpleApp app; //define your crow application

    // CROW_ROUTE(app, "/start")
    //     ([&c2]() {

    //     auto data = c2.prepareBattle();
    //     crow::response response;
    //     response.set_header("Access-Control-Allow-Origin", "http://localhost:3000");
    //     response.set_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
    //     response.set_header("Access-Control-Allow-Headers", "Content-Type, Authorization");
    //     crow::json::wvalue x;
    //     x["turn"] = 324;
    //     x["allyName"] = "Second message";
    //     x["allyName"] = "Second message";
    //     x["allyName"] = "Second message";
    //     x["allyName"] = "Second message";
    //     x["allyName"] = "Second message";
    //     x["allyName"] = "Second message";
    //     x["allyName"] = "Second message";

    //     auto json_str = x.dump();

    //     response.body = json_str;
    //     return response;
    //         });

    // //set the port, set the app to run on multiple threads, and run the app
    // app.port(18080).multithreaded().run();

    routes.run();

    return 0;
}