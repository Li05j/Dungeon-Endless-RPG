#include "battleView.h"

#include "./src/manager/battleManager.h"
#include "./src/utils/debugUtils.h"

BattleView::BattleView() {}

BattleView::~BattleView() {}

BattleView& BattleView::getInstance() {
    static BattleView instance;
    return instance;
}

void BattleView::show() {
    const std::vector<Ally>& allyBattle = m_battleM.getAllyBattle();
    const std::vector<Enemy>& enemyBattle = m_battleM.getEnemyBattle();

    // TODO: get data for the ally/enemy and somehow print it on the screen.
}

void BattleView::update() {

}