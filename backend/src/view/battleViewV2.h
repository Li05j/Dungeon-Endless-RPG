#ifndef _BATTLE_VIEW_V2_H_c6abec50_0011_46ed_8bfb_cc6a4c2b12d9_
#define _BATTLE_VIEW_V2_H_c6abec50_0011_46ed_8bfb_cc6a4c2b12d9_

///////////////////////////// THIS IS FOR REACT /////////////////////////////

#include "./src/interface/observerIface.h"

class BattleModel;
class BattleControllerV2;

class CombatUnits;

class BattleViewV2 : ObserverIface {
	BattleViewV2(BattleModel& battleM, BattleControllerV2& battleC);
	virtual ~BattleViewV2();

	BattleViewV2(BattleViewV2 const&) = delete; // private copy constructor
	BattleViewV2& operator=(BattleViewV2 const&) = delete; // private assignment operator

	BattleModel& m_battleM;
	BattleControllerV2& m_battleC;

	const void displayCombatUnitBasicStats(const CombatUnits& unit) const;
	const void displayCombatUnitDetailedStats() const;

	void displayBattleLogs();

public:
	static BattleViewV2& getInstance(BattleModel& battleM, BattleControllerV2& battleC);

	void init();
	void show();
	virtual void update() override;
};

#endif
