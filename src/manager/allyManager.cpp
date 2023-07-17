#include "allyManager.h"

#include <fstream>

#include "./src/content/combatUnits/ally/ally.h"
#include "./src/utils/combatUnitsUtils.h"
#include "./src/utils/debugUtils.h"

AllyManager::AllyManager() : m_dataFileName("./src/data/ally_data.txt") {
    populateAllyData();
}

AllyManager::~AllyManager() {}

AllyManager& AllyManager::getInstance() {
    static AllyManager instance;
    return instance;
}

void AllyManager::populateAllyData() {
    std::ifstream file(m_dataFileName);

    std::string line;
    std::shared_ptr<Ally> currentAlly = std::make_shared<Ally>();

    while (std::getline(file, line)) {
        DEBUG(DB_GENERAL, "populateAllyData(): %s\n", line.c_str());
        if (line.empty()) {
            m_allyData.push_back(currentAlly);
            continue;
        }

        // + 2 for strings to skip the space after the colon
        if (line.find("ID:") != std::string::npos) {
            currentAlly->setId(std::stoi(line.substr(line.find(":") + 1)));
        }
        else if (line.find("Name:") != std::string::npos) {
            currentAlly->setName(line.substr(line.find(":") + 2));
        }
        else if (line.find("HP:") != std::string::npos) {
            currentAlly->setBParam(B_MAXHP, std::stoi(line.substr(line.find(":") + 1)));
        }
        else if (line.find("ATK:") != std::string::npos) {
            currentAlly->setBParam(B_ATK, std::stoi(line.substr(line.find(":") + 1)));
        }
        else if (line.find("DEF:") != std::string::npos) {
            currentAlly->setBParam(B_DEF, std::stoi(line.substr(line.find(":") + 1)));
        }
    }

    file.close();

    if (m_allyData.empty()) {
        DEBUG(DB_GENERAL, "ERROR -- populateAllyData(): No ally is popullated.\n");
    }
}

int AllyManager::getTotalPlayableAllies() {
    return m_allyData.size();
}

std::shared_ptr<Ally> AllyManager::getAlly(int allyId) {
    if (allyId >= 0 && m_allyData.size() > allyId) {
        return m_allyData.at(allyId);
    }
    DEBUG(DB_GENERAL, "ERROR -- getAlly(): allyId OutOfRange. allyId = %d.\n", allyId);
    return m_allyData.at(0);
}