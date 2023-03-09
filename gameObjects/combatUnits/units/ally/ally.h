#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "../combatUnits.h"

class Ally : public CombatUnits
{
    bool m_isPartyMember;
public:
    Ally();
    virtual ~Ally() = 0;

    // void addToParty();
    // void removeFromParty();
};

#endif