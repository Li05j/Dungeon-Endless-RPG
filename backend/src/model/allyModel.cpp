#include "allyModel.h"

#include <fstream>

#include "./src/blueprint/combatUnits/ally/ally.h"
#include "./src/utils/combatUnitsUtils.h"
#include "./src/utils/debugUtils.h"

AllyModel::AllyModel() : m_dataFileName("./src/data/ally_data.txt") {
    populateAllyData();
}

AllyModel::~AllyModel() {}

AllyModel& AllyModel::getInstance() {
    static AllyModel instance;
    return instance;
}

void AllyModel::populateAllyData() {
    std::ifstream file(m_dataFileName);

    std::string line;
    Ally currentAlly(ALLY_UNIT);

    while (std::getline(file, line)) {
        // DEBUG(DB_GENERAL, "Ally Model populateAllyData(): %s\n", line.c_str());
        if (line.empty()) {
            m_allyData.push_back(currentAlly);
            continue;
        }

        // + 2 for strings to skip the space after the colon
        if (line.find("ID:") != std::string::npos) {
            currentAlly.setId(std::stoi(line.substr(line.find(":") + 1)));
        }
        else if (line.find("Name:") != std::string::npos) {
            currentAlly.setName(line.substr(line.find(":") + 2));
        }
        else if (line.find("HP:") != std::string::npos) {
            currentAlly.setBPGrowth(B_MAXHP, std::stoi(line.substr(line.find(":") + 1)));
        }
        else if (line.find("ATK:") != std::string::npos) {
            currentAlly.setBPGrowth(B_ATK, std::stoi(line.substr(line.find(":") + 1)));
        }
        else if (line.find("DEF:") != std::string::npos) {
            currentAlly.setBPGrowth(B_DEF, std::stoi(line.substr(line.find(":") + 1)));
        }
        else if (line.find("SPD:") != std::string::npos) {
            currentAlly.setBPGrowth(B_SPD, std::stoi(line.substr(line.find(":") + 1)));
        }
    }

    file.close();

    if (m_allyData.empty()) {
        DEBUG(DB_GENERAL, "ERROR -- populateAllyData(): No ally is popullated.\n");
    }
}

// int AllyModel::getTotalPlayableAllies() {
//     return m_allyData.size();
// }

Ally AllyModel::getAlly(int allyId) {
    // DEBUG(DB_GENERAL, "getAlly(), ally id is? %d...\n", allyId);
    if (allyId >= 0 && TOTAL_ALLY > allyId) {
        return m_allyData.at(allyId);
    }
    DEBUG(DB_GENERAL, "ERROR -- getAlly(): allyId OutOfRange. allyId = %d.\n", allyId);
    return m_allyData.at(0);
}

void AllyModel::debugPrintModelInfo() {
    DEBUG(DB_GENERAL, "Ally Model info...\n");
    for (auto& ally : m_allyData) {
        ally.debugPrintUnitInfo();
    }
    DEBUG(DB_GENERAL, "END\n");
}