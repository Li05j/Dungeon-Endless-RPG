#include <iostream>
#include "debugUtils.h"
#include "../back/combatUnits/ally/ally.h"

int main()
{
    std::cout << "compiled" << std::endl;
    Ally me;
    me.printUnitInfo();
    return 0;
}