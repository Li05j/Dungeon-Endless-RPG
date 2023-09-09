#include "ally.h"

#include "./src/utils/debugUtils.h"

Ally::Ally() : CombatUnits() {}

Ally::~Ally() {}

void Ally::debugPrintUnitInfo() {
    DEBUG(DB_GENERAL, "Unit info...\n");
    DEBUG(DB_GENERAL, "id: %d\n", m_id);
    DEBUG(DB_GENERAL, "name: %s\n", m_name.c_str());
    DEBUG(DB_GENERAL, "basic params... \n");
    for (auto param : m_basic_params) {
        DEBUG(DB_GENERAL, "%d, \n", param);
    }
    DEBUG(DB_GENERAL, "END\n");
}