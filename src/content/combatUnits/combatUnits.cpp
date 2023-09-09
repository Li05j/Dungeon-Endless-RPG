#include "combatUnits.h"
#include "./src/utils/debugUtils.h"

CombatUnits::CombatUnits() : m_bp_growth(TOTAL_BASIC_PARAMS, -1), m_basic_params(TOTAL_BASIC_PARAMS, -1) {}

CombatUnits::~CombatUnits() {}

int CombatUnits::getId() {
    return m_id;
}

std::string CombatUnits::getName() {
    return m_name;
}

int CombatUnits::getOneBParam(int bParamType) {
    if (TOTAL_BASIC_PARAMS > bParamType) {
        return m_basic_params[bParamType];
    }
    DEBUG(DB_GENERAL, "Error -- getOneBParam(): bParamType OutOfRange. bParamType = %d.\n", bParamType);
    return -1;
}

const std::vector<int>& CombatUnits::getAllBParams() const {
    return m_basic_params;
}

void CombatUnits::setId(int id) {
    m_id = id;
}

void CombatUnits::setName(std::string name) {
    m_name = name;
}

void CombatUnits::setBPGrowth(int bParamType, int param) {
    m_bp_growth.at(bParamType) = param;
    // initialize params
    if (bParamType == B_MAXHP) {
        setBParam(B_CURRHP, param);
    }
    setBParam(bParamType, param);
}

void CombatUnits::setBParam(int bParamType, int param) {
    m_basic_params.at(bParamType) = param;
}

void CombatUnits::debugPrintUnitInfo() {
    DEBUG(DB_GENERAL, "Unit info...\n");
    DEBUG(DB_GENERAL, "id: %d\n", m_id);
    DEBUG(DB_GENERAL, "name: %s\n", m_name.c_str());
    DEBUG(DB_GENERAL, "basic params... \n");
    for (auto param : m_basic_params) {
        DEBUG(DB_GENERAL, "%d, \n", param);
    }
    DEBUG(DB_GENERAL, "END\n");
}