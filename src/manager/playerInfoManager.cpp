#include "playerInfoManager.h"

#include <fstream>

#include "./src/content/combatUnits/ally/ally.h"
#include "./src/manager/allyManager.h"

#include "src/utils/playerUtils.h"
#include "src/utils/combatUnitsUtils.h"
#include "./src/utils/combatUnitsUtils.h"
#include "./src/utils/debugUtils.h"

PlayerInfoManager::PlayerInfoManager(AllyManager& allyM) : m_allyM(allyM), m_party(TOTAL_ALLY, 0), m_current_party_size(0) {}

PlayerInfoManager::~PlayerInfoManager() {}

PlayerInfoManager& PlayerInfoManager::getInstance(AllyManager& allyM) {
    static PlayerInfoManager instance(allyM);
    return instance;
}

void PlayerInfoManager::addMemberToParty(int allyId) {
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

void PlayerInfoManager::removeMemberFromParty(int allyId) {
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

const std::vector<int>& PlayerInfoManager::getPlayerParty() const {
    return m_party;
}

int PlayerInfoManager::getCurrentPartySize() {
    return m_current_party_size;
}

void PlayerInfoManager::debugPrintPartyInfo() {
    DEBUG(DB_GENERAL, "Your party size %d...\n", getCurrentPartySize());
    for (int i = 0; i < TOTAL_ALLY; i++) {
        if (m_party.at(i)) {
            m_allyM.getAlly(i).debugPrintUnitInfo();
        }
    }
    DEBUG(DB_GENERAL, "END\n");
}