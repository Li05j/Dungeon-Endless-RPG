#include "battleView.h"

#include <iostream>

#include "./src/blueprint/combatUnits/combatUnits.h"
#include "./src/blueprint/combatUnits/enemy/enemy.h"
#include "./src/blueprint/combatUnits/ally/ally.h"
#include "./src/controller/battleController.h"
#include "./src/model/battleModel.h"

#include "./src/utils/debugUtils.h"
#include "./src/utils/helperUtils.h"

BattleView::BattleView(BattleModel& battleM, BattleController& battleC) : m_battleM(battleM), m_battleC(battleC) {
    m_battleM.addObserver(this);
}

BattleView::~BattleView() {}

BattleView& BattleView::getInstance(BattleModel& battleM, BattleController& battleC) {
    static BattleView instance(battleM, battleC);
    return instance;
}

const void BattleView::displayCombatUnitBasicStats(const CombatUnits& unit)const {
    std::string name = unit.getName();
    int maxhp = unit.getOneBParam(B_MAXHP);
    int currhp = unit.getOneBParam(B_CURRHP);

    std::cout << name << " " << currhp << "/" << maxhp;
    std::cout << std::endl << std::endl;
}

const void BattleView::displayCombatUnitDetailedStats() const {
    // TODO
}

void BattleView::displayBattleLogs()
{
    auto& logs = m_battleC.getBattleLogs();
    std::cout << "Battle Logs:" << std::endl;
    for (auto& log : logs) {
        std::cout << log << std::endl;
    }
    std::cout << std::endl;
}

void BattleView::init() {
    m_battleC.prepareBattle();
    // show();
}

void BattleView::show() {
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

void BattleView::update() {
    clearScreen();
    show();
}