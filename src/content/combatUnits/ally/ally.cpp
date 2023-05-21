#include "ally.h"

#include "./src/utils/debugUtils.h"

Ally::Ally() : m_isPartyMember(false), CombatUnits() {}

Ally::~Ally() {}

void Ally::addToParty() {
    m_isPartyMember = true;
}

void Ally::kickFromParty() {
    m_isPartyMember = false;
}

void Ally::debugPrintUnitInfo() {
    DEBUG(DB_GENERAL, "Unit info...\n");
    DEBUG(DB_GENERAL, "id: %d\n", m_id);
    DEBUG(DB_GENERAL, "name: %s\n", m_name.c_str());
    DEBUG(DB_GENERAL, "is party?: %d\n", m_isPartyMember);
    DEBUG(DB_GENERAL, "basic params... \n");
    for (auto param : m_basicParams) {
        DEBUG(DB_GENERAL, "%d, \n", param);
    }
    DEBUG(DB_GENERAL, "END\n");
}