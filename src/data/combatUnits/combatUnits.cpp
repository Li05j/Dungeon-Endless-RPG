#include "combatUnits.h"
#include "./src/utils/combatUnitsUtils.h"
#include "./src/utils/debugUtils.h"

unsigned int dbflags = DB_GENERAL;

CombatUnits::CombatUnits() : m_id(-1), m_name("fuck!") {
    for (int i = 0; i < TOTAL_BASIC_PARAMS; i++) {
        m_basicParams.push_back(i);
    }
}

CombatUnits::~CombatUnits() {}

void CombatUnits::printUnitInfo() {
    DEBUG(DB_GENERAL, "Unit info...\n");
    DEBUG(DB_GENERAL, "id: %d\n", m_id);
    DEBUG(DB_GENERAL, "name: %s\n", m_name.c_str());
    DEBUG(DB_GENERAL, "basic params: \n");
    for (auto param : m_basicParams) {
        DEBUG(DB_GENERAL, "%d, \n", param);
    }
}