#ifndef _BATTLE_VIEW_H_c6abec50_0011_46ed_8bfb_cc6a4c2b12d9_
#define _BATTLE_VIEW_H_c6abec50_0011_46ed_8bfb_cc6a4c2b12d9_

#include "./src/interface/observerIface.h"

class BattleModel;
class BattleController;
class CombatUnits;

class BattleView : ObserverIface {
	BattleView(BattleModel& battleM, BattleController& battleC);
	virtual ~BattleView();

	BattleView(BattleView const&) = delete; // private copy constructor
	BattleView& operator=(BattleView const&) = delete; // private assignment operator

	BattleModel& m_battleM;
	BattleController& m_battleC;

	const void displayCombatUnitBasicStats(const CombatUnits& unit) const;
	const void displayCombatUnitDetailedStats() const;

	void displayBattleLogs();

public:
	static BattleView& getInstance(BattleModel& battleM, BattleController& battleC);

	void init();
	void show();
	virtual void update() override;
};

#endif
