#ifndef _COMBAT_UNITS_UTILS_H_
#define _COMBAT_UNITS_UTILS_H_

#define TOTAL_BASIC_PARAMS 3
#define TOTAL_SKILLS 0

#define ENEMY_DATA_LINES 5

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
    B_MAXHP,
    B_ATK,
    B_DEF
};

#endif