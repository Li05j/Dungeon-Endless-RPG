#ifndef _ENEMY_CONTROLLER_H_b4eeb4a2_0212_4da4_9c08_8b5bf1793a67_
#define _ENEMY_CONTROLLER_H_b4eeb4a2_0212_4da4_9c08_8b5bf1793a67_

#include <memory>
#include <string>
#include <vector>
// #include <unordered_map>

class Enemy;

class EnemyController {
private:
	EnemyController();
	virtual ~EnemyController();

	EnemyController(EnemyController const&) = delete; // private copy constructor
	EnemyController& operator=(EnemyController const&) = delete; // private assignment operator

	// std::unordered_map<int, std::shared_ptr<Enemy>> m_enemyData; // for lazy loading

	std::string m_dataFileName;
	std::vector<Enemy> m_enemyData;

public:
	static EnemyController& getInstance();

	// std::shared_ptr<Enemy> getEnemyData(int enemyId); // load enemy on demand (lazy loading)
	void populateEnemyData();
	Enemy& getEnemy(int id);
};

#endif
