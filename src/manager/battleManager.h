#ifndef _BATTLE_MANAGER_H_4237411b_e33b_4826_9fae_d8c016ea000c_
#define _BATTLE_MANAGER_H_4237411b_e33b_4826_9fae_d8c016ea000c_

#include <memory>
#include <vector>

#include "./src/interface/observerIface.h"
#include "./src/interface/subjectIface.h"

class AllyManager;
class EnemyManager;
class PlayerInfoManager;
class SkillManager;

class Ally;
class Enemy;

class BattleManager : public SubjectIface {
private:
	BattleManager(AllyManager& allyM, EnemyManager& enemyM, PlayerInfoManager& playerM, SkillManager& skillM);
	virtual ~BattleManager();

	BattleManager(BattleManager const&) = delete; // private copy constructor
	BattleManager& operator=(BattleManager const&) = delete; // private assignment operator

	AllyManager& m_allyM;
	EnemyManager& m_enemyM;
	PlayerInfoManager& m_playerM;
	SkillManager& m_skillM;

	std::vector<Ally> m_allyBattle;
	std::vector<Enemy> m_enemyBattle;

	ObserverIface& m_observer;

	void populateAllyBattle();
	void populateEnemyBattle();
public:
	static BattleManager& getInstance(AllyManager& allyM, EnemyManager& enemyM, PlayerInfoManager& playerM, SkillManager& skillM);

	const std::vector<Ally>& getAllyBattle() const;
	const std::vector<Enemy>& getEnemyBattle() const;

	virtual void addObserver(ObserverIface& observer) override;
	virtual void removeObserver(ObserverIface& observer) override;
	virtual void notifyObservers() override;

	void prepareBattle();
	void endBattle();
};

#endif
