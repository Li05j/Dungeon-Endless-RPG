#include "skill.h"

#include "./src/utils/combatUnitsUtils.h"
#include "./src/utils/debugUtils.h"

Skill::Skill() :
    m_id(DUMMY_DEFAULT),
    m_name("skill fuck!"),
    // m_type(SKILL_TYPE_PASSIVE),
    m_pow(DUMMY_DEFAULT),
    m_target(TARGET_TYPE_NONE)
    // m_range(SKILL_RANGE_NOT_APPLICABLE),
    // m_fHpCost(DUMMY_DEFAULT),
    // m_pHpCost(DUMMY_DEFAULT),
    // m_fMpCost(DUMMY_DEFAULT),
    // m_pMpCost(DUMMY_DEFAULT),
    // m_buff(DUMMY_DEFAULT),
    // m_debuff(DUMMY_DEFAULT),
    // m_cd(DUMMY_DEFAULT)
{}

Skill::~Skill() {}

void Skill::setId(int id) {
    m_id = id;
}

void Skill::setName(std::string name) {
    m_name = name;
}

void Skill::setPow(int pow) {
    m_pow = pow;
}

void Skill::setTarget(std::string target) {
    int t = DUMMY_DEFAULT;
    if (target == "Self") {
        t = TARGET_TYPE_SELF;
    }
    else if (target == "Ally") {
        t = TARGET_TYPE_ALLY;
    }
    else if (target == "Enemy") {
        t = TARGET_TYPE_ENEMY;
    }
    else if (target == "Both") {
        t = TARGET_TYPE_BOTH;
    }
    m_target = t;
}

void Skill::debugPrintSkill() {
    DEBUG(DB_GENERAL, "Skill info...\n");
    DEBUG(DB_GENERAL, "id: %d\n", m_id);
    DEBUG(DB_GENERAL, "name: %s\n", m_name.c_str());
    DEBUG(DB_GENERAL, "pow: %d, ", m_pow);
    DEBUG(DB_GENERAL, "target: %d\n", m_target);
    // DEBUG(DB_GENERAL, "others... \n");
    // DEBUG(DB_GENERAL, "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",
    //     m_type, m_pow, m_target, m_range, m_fHpCost, m_pHpCost, m_fMpCost, m_pMpCost, m_buff, m_debuff, m_cd);

    DEBUG(DB_GENERAL, "END\n");
}
