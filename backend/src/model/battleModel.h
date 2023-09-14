#ifndef _BATTLE_MODEL_H_4237411b_e33b_4826_9fae_d8c016ea000c_
#define _BATTLE_MODEL_H_4237411b_e33b_4826_9fae_d8c016ea000c_

#include <deque>
#include <vector>

#include "./src/interface/observerIface.h"
#include "./src/interface/subjectIface.h"

#include "./src/utils/combatUnitsUtils.h"

class Ally;
class Enemy;
class CombatUnits;

class BattleModel : public SubjectIface {
private:
	BattleModel();
	virtual ~BattleModel();

	BattleModel(BattleModel const&) = delete; // private copy constructor
	BattleModel& operator=(BattleModel const&) = delete; // private assignment operator

	std::vector<Ally> m_allyBattle;
	std::vector<Enemy> m_enemyBattle;

	std::vector<CombatUnits*> m_move_order;

	int m_turn_counter;

	int m_gameover;
	int m_victory;

	ObserverIface* m_observer;

public:
	static BattleModel& getInstance();

	const int getTurn() const;
	const std::vector<Ally>& getAllyBattle() const;
	const std::vector<Enemy>& getEnemyBattle() const;
	std::vector<CombatUnits*>& getMoveOrder();

	const bool isBattleEnd() const;

	void resetAllyBattle();
	void resetEnemyBattle();
	void resetMoveOrder();
	void resetTurnCounter();
	void resetbattleVictory();

	void pushAllyForBattle(Ally ally);
	void pushEnemyForBattle(Enemy enemy);
	// void pushUnitsForMoveOrder(CombatUnits* unit);

	void incrementTurnCounter();

	void gameOver();
	void battleVictory();

	void changeUnitParam(UnitType type, int which, int change);

	// void pushLog(std::string log);

	virtual void addObserver(ObserverIface* observer) override;
	virtual void removeObserver(ObserverIface* observer) override;
	virtual void notifyObservers() override;
};

#endif
