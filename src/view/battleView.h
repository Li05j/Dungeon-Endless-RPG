#ifndef _BATTLE_VIEW_H_c6abec50_0011_46ed_8bfb_cc6a4c2b12d9_
#define _BATTLE_VIEW_H_c6abec50_0011_46ed_8bfb_cc6a4c2b12d9_

#include "./src/interface/observerIface.h"

class BattleManager;

class BattleView : ObserverIface {
	BattleView();
	virtual ~BattleView();

	BattleView(BattleView const&) = delete; // private copy constructor
	BattleView& operator=(BattleView const&) = delete; // private assignment operator

	BattleManager& m_battleM;

public:
	static BattleView& getInstance();

	void show();
	virtual void update() override;
};

#endif
