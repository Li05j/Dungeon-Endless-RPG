#ifndef _COMBAT_UNITS_H_9db59aa3_17f4_43d8_aadd_4e69b02008b8_
#define _COMBAT_UNITS_H_9db59aa3_17f4_43d8_aadd_4e69b02008b8_

#include <string>
#include <vector>

#include "./src/utils/combatUnitsUtils.h"

class CombatUnits {
protected:
	int m_id = DUMMY_DEFAULT;
	std::string m_name = "combat unit default name fuck! something is probably wrong";
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

	// debug use
	virtual void debugPrintUnitInfo();
};

#endif
