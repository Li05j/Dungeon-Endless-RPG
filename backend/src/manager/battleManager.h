#ifndef _BATTLE_MANAGER_H_4237411b_e33b_4826_9fae_d8c016ea000c_
#define _BATTLE_MANAGER_H_4237411b_e33b_4826_9fae_d8c016ea000c_

#include <memory>
#include <vector>
#include <deque>

#include "./src/interface/observerIface.h"
#include "./src/interface/subjectIface.h"

#include "./src/utils/combatUnitsUtils.h"

class AllyManager;
class EnemyManager;
class PlayerInfoManager;
class SkillManager;

class BattleLoggerManager;

class Ally;
class Enemy;
class CombatUnits;

enum UnitType;

class BattleManager : public SubjectIface {
private:
	BattleManager(AllyManager& allyM, EnemyManager& enemyM, PlayerInfoManager& playerM, SkillManager& skillM, BattleLoggerManager& battleLogM);
	virtual ~BattleManager();

	BattleManager(BattleManager const&) = delete; // private copy constructor
	BattleManager& operator=(BattleManager const&) = delete; // private assignment operator

	AllyManager& m_allyM;
	EnemyManager& m_enemyM;
	PlayerInfoManager& m_playerM;
	SkillManager& m_skillM;

	BattleLoggerManager& m_battleLogM;

	std::vector<Ally> m_allyBattle;
	std::vector<Enemy> m_enemyBattle;

	std::vector<CombatUnits*> m_move_order;

	int m_turn_counter;

	int m_gameover;
	int m_victory;

	ObserverIface* m_observer;

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
	bool isEndBattle();
	void endBattle();

	void determineMoveOrder();
	void incrementTurn();

	// during turn.. damage calc
	void useDefaultAttack(CombatUnits& subject, CombatUnits& object, int damage);

	// logging
	std::string damageLog(std::string subject, std::string object, int damage, bool crit = false);

public:
	static BattleManager& getInstance(AllyManager& allyM, EnemyManager& enemyM, PlayerInfoManager& playerM, SkillManager& skillM, BattleLoggerManager& battleLogM);

	const int getTurn() const;
	const std::vector<Ally>& getAllyBattle() const;
	const std::vector<Enemy>& getEnemyBattle() const;
	const std::deque<std::string>& getBattleLogs() const;

	// void pushLog(std::string log);

	virtual void addObserver(ObserverIface* observer) override;
	virtual void removeObserver(ObserverIface* observer) override;
	virtual void notifyObservers() override;

	void prepareBattle();
};

#endif
