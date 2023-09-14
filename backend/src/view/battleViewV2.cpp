///////////////////////////// THIS IS FOR REACT /////////////////////////////

#include "battleViewV2.h"

#include <iostream>

#include "./src/blueprint/combatUnits/combatUnits.h"
#include "./src/blueprint/combatUnits/enemy/enemy.h"
#include "./src/blueprint/combatUnits/ally/ally.h"
#include "./src/controller/battleControllerV2.h"
#include "./src/model/battleModel.h"

#include "./src/utils/debugUtils.h"
#include "./src/utils/helperUtils.h"

BattleViewV2::BattleViewV2(BattleModel& battleM, BattleControllerV2& battleC) : m_battleM(battleM), m_battleC(battleC) {
    m_battleM.addObserver(this);
}

BattleViewV2::~BattleViewV2() {}

BattleViewV2& BattleViewV2::getInstance(BattleModel& battleM, BattleControllerV2& battleC) {
    static BattleViewV2 instance(battleM, battleC);
    return instance;
}

const void BattleViewV2::displayCombatUnitBasicStats(const CombatUnits& unit)const {
    std::string name = unit.getName();
    int maxhp = unit.getOneBParam(B_MAXHP);
    int currhp = unit.getOneBParam(B_CURRHP);

    std::cout << name << " " << currhp << "/" << maxhp;
    std::cout << std::endl << std::endl;
}

const void BattleViewV2::displayCombatUnitDetailedStats() const {
    // TODO
}

void BattleViewV2::displayBattleLogs()
{
    auto& logs = m_battleC.getBattleLogs();
    std::cout << "Battle Logs:" << std::endl;
    for (auto& log : logs) {
        std::cout << log << std::endl;
    }
    std::cout << std::endl;
}

void BattleViewV2::init() {
    // m_battleC.prepareBattle();
}

void BattleViewV2::show() {
    const int turn = m_battleM.getTurn();
    const std::vector<Ally>& allyBattle = m_battleM.getAllyBattle();
    const std::vector<Enemy>& enemyBattle = m_battleM.getEnemyBattle();

    // TODO: get data for the ally/enemy and somehow print it on the screen.

    std::cout << "Current Turn: " << turn << std::endl << std::endl;

    for (auto& enemy : enemyBattle) {
        displayCombatUnitBasicStats(enemy);
    }

    for (auto& ally : allyBattle) {
        displayCombatUnitBasicStats(ally);
    }
    displayBattleLogs();
}

void BattleViewV2::update() {
    clearScreen();
    show();
}