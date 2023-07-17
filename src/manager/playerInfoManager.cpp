#include "playerInfoManager.h"

#include <fstream>

#include "./src/content/combatUnits/ally/ally.h"
#include "./src/manager/allyManager.h"
#include "./src/utils/combatUnitsUtils.h"
#include "./src/utils/debugUtils.h"

PlayerInfoManager::PlayerInfoManager(AllyManager& allyM) : m_allyM(allyM) {}

PlayerInfoManager::~PlayerInfoManager() {}

PlayerInfoManager& PlayerInfoManager::getInstance(AllyManager& allyM) {
    static PlayerInfoManager instance(allyM);
    return instance;
}

void PlayerInfoManager::addMemberToParty(int allyId) {
    if (allyId > 0 && m_allyM.getTotalPlayableAllies() > allyId) {
        m_party.push_back(m_allyM.getAlly(allyId));
        return;
    }
    DEBUG(DB_GENERAL, "ERROR -- addMemberToParty(): allyId OutOfRange. allyId = %d.\n", allyId);
}

void PlayerInfoManager::removeMemberFromParty(int allyId) {
    if (allyId > 0 && m_allyM.getTotalPlayableAllies() > allyId) {
        m_party.erase(m_party.begin() + allyId);
        return;
    }
    DEBUG(DB_GENERAL, "ERROR -- removeMemberFromParty(): allyId OutOfRange. allyId = %d.\n", allyId);
}

void PlayerInfoManager::debugPrintPartyInfo() {
    DEBUG(DB_GENERAL, "Your party size %ld...\n", m_party.size());
    for (auto ally : m_party) {
        ally->debugPrintUnitInfo();
    }
    DEBUG(DB_GENERAL, "END\n");
}