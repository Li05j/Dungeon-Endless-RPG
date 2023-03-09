#ifndef __GENERIC_BATTLE_CONTROLLER_H_
#define __GENERIC_BATTLE_CONTROLLER_H_

#include "../controller.h"

class GenericBattleController : public Controller
{
    virtual int beforeBattle() = 0;
    virtual int beforeTurn() = 0;
    virtual int duringTurn() = 0;
    virtual int afterTurn() = 0;
    virtual int afterBattle() = 0;
    
public:
    GenericBattleController();
    virtual ~GenericBattleController() = 0;
};


#endif