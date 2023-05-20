#include <iostream>
#include "./src/data/combatUnits/ally/ally.h"
#include "./src/data/combatUnits/enemy/enemy.h"
#include "./src/controller/enemyController.h"

int main()
{
    std::cout << "compiled" << std::endl;
    EnemyController& c1 = EnemyController::getInstance();
    std::shared_ptr<Enemy> them = c1.getEnemyData(1);
    Ally me;
    me.printUnitInfo();
    them->printUnitInfo();
    return 0;
}