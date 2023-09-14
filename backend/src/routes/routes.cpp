#include "routes.h"

#include "./src/controller/battleControllerV2.h"
#include "./src/interface/battleResponseIface.h"

#include "./src/utils/debugUtils.h"

Routes::Routes(BattleControllerV2& battleC_V2) : m_battleC_V2(battleC_V2) {}

Routes::~Routes() {}

crow::response Routes::prepareResponse(BattleResponseIface data)
{
    crow::response response;
    response.set_header("Access-Control-Allow-Origin", "http://localhost:3000");
    response.set_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
    response.set_header("Access-Control-Allow-Headers", "Content-Type, Authorization");
    crow::json::wvalue x;
    x["turn"] = data.turn;
    x["allyName"] = data.allyName;
    x["allyCurrHp"] = data.allyCurrHp;
    x["allyMaxHp"] = data.allyMaxHp;
    x["enemyName"] = data.enemyName;
    x["enemyCurrHp"] = data.enemyCurrHp;
    x["enemyMaxHp"] = data.enemyMaxHp;
    x["battleLogs"] = data.battleLogs;

    auto json_str = x.dump();

    response.body = json_str;
    return response;
}

void Routes::run()
{
    crow::SimpleApp app; //define your crow application

    CROW_ROUTE(app, "/start")
        ([this]() {

        BattleResponseIface data = this->m_battleC_V2.prepareBattle();
        crow::response response = prepareResponse(data);
        return response;
            });

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
}
