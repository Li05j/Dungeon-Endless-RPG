#include "combatUnits.h"
#include "./src/utils/debugUtils.h"

CombatUnits::CombatUnits() {
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

int CombatUnits::getOneBParam(int bParamType) {
    if (m_basicParams.size() > bParamType) {
        return m_basicParams[bParamType];
    }
    DEBUG(DB_GENERAL, "Error -- getOneBParam(): bParamType OutOfRange. bParamType = %d.\n", bParamType);
    return -1;
}

std::vector<int>& CombatUnits::getAllBParams() {
    return m_basicParams;
}

void CombatUnits::setId(int id) {
    m_id = id;
}

void CombatUnits::setName(std::string name) {
    m_name = name;
}

void CombatUnits::setBParam(int bParamType, int param) {
    m_basicParams.at(bParamType) = param;
}

void CombatUnits::debugPrintUnitInfo() {
    DEBUG(DB_GENERAL, "Unit info...\n");
    DEBUG(DB_GENERAL, "id: %d\n", m_id);
    DEBUG(DB_GENERAL, "name: %s\n", m_name.c_str());
    DEBUG(DB_GENERAL, "basic params... \n");
    for (auto param : m_basicParams) {
        DEBUG(DB_GENERAL, "%d, \n", param);
    }
    DEBUG(DB_GENERAL, "END\n");
}