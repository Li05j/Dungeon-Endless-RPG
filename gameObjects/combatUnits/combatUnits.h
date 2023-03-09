#ifndef __COMBAT_UNITS_H_
#define __COMBAT_UNITS_H_

#include <memory>
#include "params/basicParam.h"

class CombatUnits
{
    std::unique_ptr<BasicParam> m_basic_param;
public:
    CombatUnits();
    virtual ~CombatUnits() = 0;

    void setBasicParams(int, int);
};

#endif