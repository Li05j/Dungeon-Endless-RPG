#include "playerInfoModel.h"

#include <fstream>

#include "./src/blueprint/combatUnits/ally/ally.h"
#include "./src/model/allyModel.h"

#include "src/utils/playerUtils.h"
#include "src/utils/combatUnitsUtils.h"
#include "./src/utils/combatUnitsUtils.h"
#include "./src/utils/debugUtils.h"

PlayerInfoModel::PlayerInfoModel(AllyModel& allyM) : m_allyM(allyM), m_party(TOTAL_ALLY, 0), m_current_party_size(0) {}

PlayerInfoModel::~PlayerInfoModel() {}

PlayerInfoModel& PlayerInfoModel::getInstance(AllyModel& allyM) {
    static PlayerInfoModel instance(allyM);
    return instance;
}

void PlayerInfoModel::addMemberToParty(int allyId) {
    DEBUG(DB_GENERAL, "addMemberToParty() called\n");
    if (m_current_party_size == MAX_PARTY_SIZE) {
        DEBUG(DB_GENERAL, "ERROR -- addMemberToParty(): too many allies.\n");
        return;
    }
    if (allyId >= 0 && allyId < TOTAL_ALLY) {
        if (!m_party.at(allyId)) {
            m_party.at(allyId) = 1;
            m_current_party_size++;
        }
        return;
    }
    DEBUG(DB_GENERAL, "ERROR -- addMemberToParty(): allyId OutOfRange. allyId = %d.\n", allyId);
}

void PlayerInfoModel::removeMemberFromParty(int allyId) {
    if (m_current_party_size == 1) {
        DEBUG(DB_GENERAL, "ERROR -- removeMemberFromParty(): last ally, cannot remove.\n");
        return;
    }
    if (allyId >= 0 && allyId < TOTAL_ALLY) {
        if (m_party.at(allyId)) {
            m_party.at(allyId) = 0;
            m_current_party_size--;
        }
        return;
    }
    DEBUG(DB_GENERAL, "ERROR -- removeMemberFromParty(): allyId OutOfRange. allyId = %d.\n", allyId);
}

const std::vector<int>& PlayerInfoModel::getPlayerParty() const {
    return m_party;
}

int PlayerInfoModel::getCurrentPartySize() {
    return m_current_party_size;
}

void PlayerInfoModel::debugPrintPartyInfo() {
    DEBUG(DB_GENERAL, "Your party size %d...\n", getCurrentPartySize());
    for (int i = 0; i < TOTAL_ALLY; i++) {
        if (m_party.at(i)) {
            m_allyM.getAlly(i).debugPrintUnitInfo();
        }
    }
    DEBUG(DB_GENERAL, "END\n");
}