#ifndef _BATTLE_VIEW_H_c6abec50_0011_46ed_8bfb_cc6a4c2b12d9_
#define _BATTLE_VIEW_H_c6abec50_0011_46ed_8bfb_cc6a4c2b12d9_

#include "./src/interface/observerIface.h"

class BattleManager;
class CombatUnits;

class BattleView : ObserverIface {
	BattleView(BattleManager& battleM);
	virtual ~BattleView();

	BattleView(BattleView const&) = delete; // private copy constructor
	BattleView& operator=(BattleView const&) = delete; // private assignment operator

	BattleManager& m_battleM;

	void displayCombatUnitBasicStats(CombatUnits& unit);
	void displayCombatUnitDetailedStats();

	void displayBattleLogs();

public:
	static BattleView& getInstance(BattleManager& battleM);

	void init();
	void show();
	virtual void update() override;
};

#endif
