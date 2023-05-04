CXX=g++
CXXFLAGS=-std=c++14 -MMD -Werror=vla
OBJECTS=main.o ./BattleUnits/Params/stats.o ./BattleUnits/Params/BasicParams/basicParam.o ./BattleUnits/Params/BasicParams/hpParam.o ./BattleUnits/Params/BasicParams/atkParam.o ./BattleUnits/Params/BasicParams/defParam.o ./BattleUnits/Characters/character.o ./BattleUnits/Characters/level.o ./BattleUnits/Enemies/enemy.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=01RPG

${EXEC}: ${OBJECTS}
		${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
		rm ${OBJECTS} ${DEPENDS} ${EXEC}
