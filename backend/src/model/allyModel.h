#ifndef _ALLY_MODEL_H_25817df0_2132_4471_b3a4_76bfbe096c27_
#define _ALLY_MODEL_H_25817df0_2132_4471_b3a4_76bfbe096c27_

#include <string>
#include <vector>

class Ally;

class AllyModel {
private:
	AllyModel();
	virtual ~AllyModel();

	AllyModel(AllyModel const&) = delete; // private copy constructor
	AllyModel& operator=(AllyModel const&) = delete; // private assignment operator

	std::vector<Ally> m_allyData;
	std::string m_dataFileName;

	void populateAllyData();

public:
	static AllyModel& getInstance();

	// int getTotalPlayableAllies();
	Ally getAlly(int allyId);

	// debug use
	virtual void debugPrintModelInfo();
};

#endif
