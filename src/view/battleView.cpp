#include "battleView.h"

#include <iostream>

#include "./src/content/combatUnits/combatUnits.h"
#include "./src/content/combatUnits/enemy/enemy.h"
#include "./src/content/combatUnits/ally/ally.h"
#include "./src/manager/battleManager.h"
#include "./src/utils/debugUtils.h"

BattleView::BattleView(BattleManager& battleM) : m_battleM(battleM) {
    m_battleM.addObserver(this);
}

BattleView::~BattleView() {}

BattleView& BattleView::getInstance(BattleManager& battleM) {
    static BattleView instance(battleM);
    return instance;
}

void BattleView::displayCombatUnitBasicStats(CombatUnits& unit) {
    std::string name = unit.getName();
    int maxhp = unit.getOneBParam(B_MAXHP);
    int currhp = unit.getOneBParam(B_CURRHP);

    std::cout << name << " " << currhp << "/" << maxhp;
}

void BattleView::displayCombatUnitDetailedStats() {
    // TODO
}

void BattleView::init() {
    m_battleM.prepareBattle();
    show();
}

void BattleView::show() {
    const std::vector<Ally>& allyBattle = m_battleM.getAllyBattle();
    const std::vector<Enemy>& enemyBattle = m_battleM.getEnemyBattle();

    // TODO: get data for the ally/enemy and somehow print it on the screen.

    for (auto enemy : enemyBattle) {
        displayCombatUnitBasicStats(enemy);
    }

    std::cout << std::endl << std::endl;

    for (auto ally : allyBattle) {
        displayCombatUnitBasicStats(ally);
    }
    std::cout << std::endl << std::endl;
}

void BattleView::update() {
    show();
}