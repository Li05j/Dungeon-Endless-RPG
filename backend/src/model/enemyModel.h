#ifndef _ENEMY_MODEL_H_b4eeb4a2_0212_4da4_9c08_8b5bf1793a67_
#define _ENEMY_MODEL_H_b4eeb4a2_0212_4da4_9c08_8b5bf1793a67_

#include <memory>
#include <string>
#include <vector>
// #include <unordered_map>

class Enemy;

class EnemyModel {
private:
	EnemyModel();
	virtual ~EnemyModel();

	EnemyModel(EnemyModel const&) = delete; // private copy constructor
	EnemyModel& operator=(EnemyModel const&) = delete; // private assignment operator

	// std::unordered_map<int, std::shared_ptr<Enemy>> m_enemyData; // for lazy loading

	std::string m_dataFileName;
	std::vector<Enemy> m_enemyData;

	void populateEnemyData();

public:
	static EnemyModel& getInstance();

	// std::shared_ptr<Enemy> getEnemyData(int enemyId); // load enemy on demand (lazy loading)
	Enemy& getEnemy(int enemyId);
};

#endif
