#ifndef _ALLY_MANAGER_H_25817df0_2132_4471_b3a4_76bfbe096c27_
#define _ALLY_MANAGER_H_25817df0_2132_4471_b3a4_76bfbe096c27_

#include <string>
#include <vector>

class Ally;

class AllyManager {
private:
	AllyManager();
	virtual ~AllyManager();

	AllyManager(AllyManager const&) = delete; // private copy constructor
	AllyManager& operator=(AllyManager const&) = delete; // private assignment operator

	std::vector<Ally> m_allyData;
	std::string m_dataFileName;

	void populateAllyData();

public:
	static AllyManager& getInstance();

	// int getTotalPlayableAllies();
	Ally getAlly(int allyId);

	// debug use
	virtual void debugPrintManagerInfo();
};

#endif
