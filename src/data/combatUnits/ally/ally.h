#ifndef _ALLY_H_e5962351_6ee8_4c29_a81a_28cd970591c7_
#define _ALLY_H_e5962351_6ee8_4c29_a81a_28cd970591c7_

#include "./src/data/combatUnits/combatUnits.h"

class Ally : public CombatUnits {
private:
	bool m_isPartyMember;

public:
	Ally();
	virtual ~Ally();

	void addToParty();
	void kickFromParty();

	virtual void printUnitInfo() override;
};

#endif
