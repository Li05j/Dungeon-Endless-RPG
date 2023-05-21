#ifndef _COMBAT_UNITS_H_9db59aa3_17f4_43d8_aadd_4e69b02008b8_
#define _COMBAT_UNITS_H_9db59aa3_17f4_43d8_aadd_4e69b02008b8_

#include <string>
#include <vector>

class CombatUnits {
protected:
	int m_id;
	std::string m_name;
	std::vector<int> m_basicParams;

public:
	CombatUnits();
	virtual ~CombatUnits() = 0;

	int getId();
	std::string getName();
	int getOneBParam(int bParamType);
	std::vector<int>& getAllBParams();

	void setId(int id);
	void setName(std::string name);
	void setBParam(int bParamType, int param);

	virtual void printUnitInfo();
};

#endif
