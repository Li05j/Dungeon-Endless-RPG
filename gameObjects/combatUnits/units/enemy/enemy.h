#ifndef __ENEMY_H_
#define __ENEMY_H_

#include "../combatUnits.h"

class Enemy : public CombatUnits
{
public:
    Enemy();
    virtual ~Enemy() = 0;
};

#endif