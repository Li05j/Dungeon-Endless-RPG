#include "combatUnits.h"
#include "utils/funny.h"

CombatUnits::CombatUnits() {}

void CombatUnits::setBasicParams(int curr_hp, int atk)
{
    m_basic_param->setParams(curr_hp, atk);
}