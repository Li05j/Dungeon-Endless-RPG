#ifndef _COMBAT_UNITS_H_9db59aa3_17f4_43d8_aadd_4e69b02008b8_
#define _COMBAT_UNITS_H_9db59aa3_17f4_43d8_aadd_4e69b02008b8_

#include <string>
#include <vector>

class CombatUnits {
private:
	int m_id;
	std::string m_name;
	std::vector<int> m_basicParams;

public:
	// since we will be doing lazy loading, we will not init right now, but instead read from file.
	CombatUnits();
	virtual ~CombatUnits() = 0;

	int getId();
	std::string getName();
	std::vector<int>& getBasicParams();

	void setId(int id);
	void setName(std::string name);
	void setBasicParam(int type, int param);

	virtual void printUnitInfo();
};

#endif
