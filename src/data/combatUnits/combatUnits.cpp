#include "combatUnits.h"
#include "./src/utils/combatUnitsUtils.h"
#include "./src/utils/debugUtils.h"

unsigned int dbflags = DB_GENERAL;

CombatUnits::CombatUnits() : m_id(-1), m_name("fuck!") {
    m_basicParams.reserve(TOTAL_BASIC_PARAMS);
    for (int i = 0; i < TOTAL_BASIC_PARAMS; i++) {
        m_basicParams.push_back(-i);
    }
}

CombatUnits::~CombatUnits() {}

int CombatUnits::getId() {
    return m_id;
}

std::string CombatUnits::getName() {
    return m_name;
}

std::vector<int>& CombatUnits::getBasicParams() {
    return m_basicParams;
}

void CombatUnits::setId(int id) {
    m_id = id;
}

void CombatUnits::setName(std::string name) {
    m_name = name;
}

void CombatUnits::setBasicParam(int type, int param) {
    m_basicParams.at(type) = param;
}

void CombatUnits::printUnitInfo() {
    DEBUG(DB_GENERAL, "Unit info...\n");
    DEBUG(DB_GENERAL, "id: %d\n", m_id);
    DEBUG(DB_GENERAL, "name: %s\n", m_name.c_str());
    DEBUG(DB_GENERAL, "basic params: \n");
    for (auto param : m_basicParams) {
        DEBUG(DB_GENERAL, "%d, \n", param);
    }
}