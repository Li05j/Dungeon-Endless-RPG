#include "basicParam.h"

BasicParam::BasicParam() : m_curr_hp{50}, m_atk{9} {}
BasicParam::~BasicParam() {}

void BasicParam::setParams(int curr_hp, int atk)
{
    m_curr_hp = curr_hp;
    m_atk = atk;
}