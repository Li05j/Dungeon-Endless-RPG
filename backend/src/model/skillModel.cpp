#include "skillModel.h"

#include <fstream>

#include "./src/blueprint/combatUnits/unitAttributes/skill.h"
#include "./src/utils/debugUtils.h"

SkillModel::SkillModel() : m_dataFileName("./src/data/skill_data_test.txt") {
    populateSkillData();
}

SkillModel::~SkillModel() {}

SkillModel& SkillModel::getInstance() {
    static SkillModel instance;
    return instance;
}

Skill& SkillModel::getSkill(int skillId) {
    if (skillId >= 0 && m_skillData.size() > skillId) {
        return m_skillData.at(skillId);
    }
    DEBUG(DB_GENERAL, "ERROR -- getSkill(): allyId OutOfRange. skillId = %d.\n", skillId);
    return m_skillData.at(0);
}

void SkillModel::populateSkillData() {
    std::ifstream file(m_dataFileName);

    std::string line;
    Skill currentSkill;

    while (std::getline(file, line)) {
        // DEBUG(DB_GENERAL, "populateEnemyData(): %s\n", line.c_str());
        if (line.empty()) {
            m_skillData.push_back(currentSkill);
            continue;
        }

        // + 2 for strings to skip the space after the colon
        if (line.find("ID:") != std::string::npos) {
            currentSkill.setId(std::stoi(line.substr(line.find(":") + 1)));
        }
        else if (line.find("Name:") != std::string::npos) {
            currentSkill.setName(line.substr(line.find(":") + 2));
        }
        else if (line.find("Power:") != std::string::npos) {
            currentSkill.setPow(std::stoi(line.substr(line.find(":") + 1)));
        }
        // else if (line.find("Target:") != std::string::npos) {
        //     currentSkill.setTarget(line.substr(line.find(":") + 2));
        // }
    }

    file.close();

    if (m_skillData.empty()) {
        DEBUG(DB_GENERAL, "ERROR -- populateAllyData(): No ally is popullated.\n");
    }
}