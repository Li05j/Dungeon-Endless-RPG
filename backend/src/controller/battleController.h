#ifndef _BATTLE_CONTROLLER_H_6f3d21b4_f829_4298_8780_ba7aeed06fb9_
#define _BATTLE_CONTROLLER_H_6f3d21b4_f829_4298_8780_ba7aeed06fb9_

#include <deque>
#include <string>

#include "./src/utils/combatUnitsUtils.h"

class BattleModel;

class AllyModel;
class EnemyModel;
class PlayerInfoModel;
class BattleLoggerModel;

class CombatUnits;

class BattleController {
private:
	BattleController(BattleModel& battleM, AllyModel& allyM, EnemyModel& enemyM, PlayerInfoModel& playerM, BattleLoggerModel& battleLogM);
	virtual ~BattleController();

	BattleController(BattleController const&) = delete; // private copy constructor
	BattleController& operator=(BattleController const&) = delete; // private assignment operator

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

	// void determineMoveOrder();

	// during turn.. damage calc
	void useDefaultAttack(std::string subjectName, std::string targetName, UnitType targetUnitType, int targetIdx, int damage);

	// logging
	std::string damageLog(std::string subject, std::string object, int damage, bool crit = false);

public:
	static BattleController& getInstance(BattleModel& battleM, AllyModel& allyM, EnemyModel& enemyM, PlayerInfoModel& playerM, BattleLoggerModel& battleLogM);

	void prepareBattle();
	// const int getTurn() const;
	// const std::vector<Ally>& getAllyBattle() const;
	// const std::vector<Enemy>& getEnemyBattle() const;
	const std::deque<std::string>& getBattleLogs() const;
};

#endif
