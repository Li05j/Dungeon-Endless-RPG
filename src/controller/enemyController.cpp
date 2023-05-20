#include "enemyController.h"

#include <fstream>
#include <limits>
#include <string>

#include "./src/data/combatUnits/enemy/enemy.h"
#include "./src/utils/combatUnitsUtils.h"
#include "./src/utils/debugUtils.h"

EnemyController::EnemyController() {}

EnemyController::~EnemyController() {}

EnemyController& EnemyController::getInstance() {
    static EnemyController instance;
    return instance;
}

std::shared_ptr<Enemy> EnemyController::getEnemyData(int enemyId) {
    DEBUG(DB_GENERAL, "getEnemyData() called %d\n", enemyId);
    if (m_enemyData.find(enemyId) == m_enemyData.end()) {
        // Enemy data not loaded, load from file
        std::ifstream file("./src/data/combatUnits/enemy/enemy_data1.txt");
        std::string line;
        Enemy currentEnemy;

        int skip = enemyId * (ENEMY_DATA_LINES + 1);

        // skip lines
        for (int i = 0; i < skip; i++) {
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for (int i = 0; i < ENEMY_DATA_LINES; i++) {
            std::getline(file, line);
            DEBUG(DB_GENERAL, "getEnemyData(): %s.\n", line.c_str());

            if (line.find("ID:") != std::string::npos) {
                currentEnemy.setId(std::stoi(line.substr(line.find(":") + 1)));
            }
            else if (line.find("Name:") != std::string::npos) {
                currentEnemy.setName(line.substr(line.find(":") + 1));
            }
            else if (line.find("HP:") != std::string::npos) {
                int hp = std::stoi(line.substr(line.find(":") + 1));
                currentEnemy.setBasicParam(B_MAXHP, hp);
                currentEnemy.setBasicParam(B_CURRHP, hp);
            }
            else if (line.find("ATK:") != std::string::npos) {
                currentEnemy.setBasicParam(B_ATK, std::stoi(line.substr(line.find(":") + 1)));
            }
            else if (line.find("DEF:") != std::string::npos) {
                currentEnemy.setBasicParam(B_DEF, std::stoi(line.substr(line.find(":") + 1)));
            }
        }

        if (currentEnemy.getId() == enemyId) {
            m_enemyData[enemyId] = std::make_shared<Enemy>(currentEnemy);
        }
        else {
            // should not reach;
            DEBUG(DB_GENERAL, "Wrong enemy created! expected id: %d, actual id: %d.\n", enemyId, currentEnemy.getId());
        }

        file.close();
    }

    return m_enemyData[enemyId];
}