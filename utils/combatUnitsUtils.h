#ifndef _COMBAT_UNITS_UTILS_H_
#define _COMBAT_UNITS_UTILS_H_

#define TOTAL_BASIC_PARAMS 4;
#define TOTAL_SKILLS 0;

enum AllyType
{
    Type_Fighter
};

enum EnemyType
{
    Type_MINION,
    Type_ELITE,
    Type_BOSS,
    Type_BIG_BOSS,
    Type_SPECIAL
};

enum BasicParamType
{
    B_MaxHP,
    B_CurrHP,
    B_ATK,
    B_DEF
};

#endif