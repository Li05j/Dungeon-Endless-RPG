#ifndef _COMBAT_UNITS_UTILS_H_
#define _COMBAT_UNITS_UTILS_H_

#define TOTAL_BASIC_PARAMS 3
#define TOTAL_SKILLS 0

#define TOTAL_ALLY 3
#define TOTAL_ENEMY 3

#define ALLY_DATA_LINES 5
#define ENEMY_DATA_LINES 5
#define SKILL_DATA_LINES 4

#define DUMMY_DEFAULT -1

// enum AllyType
// {
//     Type_Fighter
// };

enum EnemyType
{
    ENEMY_TYPE_NONE,
    ENEMY_TYPE_MINION,
    ENEMY_TYPE_ELITE,
    ENEMY_TYPE_BOSS,
    ENEMY_TYPE_BIG_BOSS,
    ENEMY_TYPE_SPECIAL
};

enum BasicParamType
{
    B_MAXHP,
    B_ATK,
    B_DEF
};

enum SkillType
{
    SKILL_TYPE_PASSIVE,
    SKILL_TYPE_PHYSICAL,
    SKILL_TYPE_MAGIC,
    SKILL_TYPE_SUPPORT
};

enum SkillRange
{
    SKILL_RANGE_NOT_APPLICABLE = -1,
    SKILL_RANGE_SELF,

    SKILL_RANGE_E_FRONT_SINGLE,
    SKILL_RANGE_E_FRONT_ALL,
    SKILL_RANGE_E_PIERCE,
    SKILL_RANGE_E_BACK_SINGLE,
    SKILL_RANGE_E_BACK_ALL,
    SKILL_RANGE_E_CROSS,
    SKILL_RANGE_E_LOWEST_HP,

    SKILL_RANGE_A_FRONT_SINGLE,
    SKILL_RANGE_A_FRONT_ALL,
    SKILL_RANGE_A_BACK_SINGLE,
    SKILL_RANGE_A_BACK_ALL,
    SKILL_RANGE_A_LOWEST_HP,
};

// std::ostream& operator<<(std::ostream& os, TargetType t)
// {
//     switch (t)
//     {
//     case TARGET_TYPE_NONE: os << "None";      break;
//     case TARGET_TYPE_SELF: os << "Self";      break;
//         ...
//     default: os.setstate(std::ios_base::failbit);
//     }
//     return os;
// }

#endif