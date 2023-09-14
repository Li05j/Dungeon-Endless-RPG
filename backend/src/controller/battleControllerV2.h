#ifndef _BATTLE_CONTROLLER_V2_H_6f3d21b4_f829_4298_8780_ba7aeed06fb9_
#define _BATTLE_CONTROLLER_V2_H_6f3d21b4_f829_4298_8780_ba7aeed06fb9_

///////////////////////////// THIS IS FOR REACT /////////////////////////////

#include <deque>
#include <string>

#include "./src/utils/combatUnitsUtils.h"

class BattleModel;

class AllyModel;
class EnemyModel;
class PlayerInfoModel;
class BattleLoggerModel;

class CombatUnits;

class BattleResponseIface;

class BattleControllerV2 {
private:
	BattleControllerV2(BattleModel& battleM, AllyModel& allyM, EnemyModel& enemyM, PlayerInfoModel& playerM, BattleLoggerModel& battleLogM);
	virtual ~BattleControllerV2();

	BattleControllerV2(BattleControllerV2 const&) = delete; // private copy constructor
	BattleControllerV2& operator=(BattleControllerV2 const&) = delete; // private assignment operator

	BattleModel& m_battleM;

	AllyModel& m_allyM;
	EnemyModel& m_enemyM;
	PlayerInfoModel& m_playerM;

	BattleLoggerModel& m_battleLogM;

	// init
	void populateAllyBattle();
	void populateEnemyBattle();

	// flow
	void startBattle();
	void preTurn();
	void duringTurn();
	void postTurn();
	void checkAllyPartyWipe();
	void checkEnemyPartyWipe();
	// bool isEndBattle();
	void endBattle();

	// request/response
	BattleResponseIface fetchData();

	// void determineMoveOrder();

	// during turn.. damage calc
	void useDefaultAttack(std::string subjectName, std::string targetName, UnitType targetUnitType, int targetIdx, int damage);

	// logging
	std::string damageLog(std::string subject, std::string object, int damage, bool crit = false);

public:
	static BattleControllerV2& getInstance(BattleModel& battleM, AllyModel& allyM, EnemyModel& enemyM, PlayerInfoModel& playerM, BattleLoggerModel& battleLogM);

	BattleResponseIface prepareBattle();
	// const int getTurn() const;
	// const std::vector<Ally>& getAllyBattle() const;
	// const std::vector<Enemy>& getEnemyBattle() const;
	const std::deque<std::string>& getBattleLogs() const;
};

#endif
