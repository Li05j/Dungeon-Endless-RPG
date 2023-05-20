#ifndef _ENEMY_CONTROLLER_H_b4eeb4a2_0212_4da4_9c08_8b5bf1793a67_
#define _ENEMY_CONTROLLER_H_b4eeb4a2_0212_4da4_9c08_8b5bf1793a67_

#include <unordered_map>
#include <memory>

class Enemy;

class EnemyController {
private:
	// static Enemy instance;

	EnemyController();
	virtual ~EnemyController();

	EnemyController(EnemyController const&) = delete; // private copy constructor
	EnemyController& operator=(EnemyController const&) = delete; // private assignment operator

	std::unordered_map<int, std::shared_ptr<Enemy>> m_enemyData;

public:
	static EnemyController& getInstance();

	// load enemy on demand (lazy loading)
	std::shared_ptr<Enemy> getEnemyData(int enemyId);
};

#endif
