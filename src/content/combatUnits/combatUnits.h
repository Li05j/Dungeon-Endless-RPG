#ifndef _COMBAT_UNITS_H_9db59aa3_17f4_43d8_aadd_4e69b02008b8_
#define _COMBAT_UNITS_H_9db59aa3_17f4_43d8_aadd_4e69b02008b8_

#include <string>
#include <vector>

#include "./src/utils/combatUnitsUtils.h"

class CombatUnits {
protected:
	int m_id = DUMMY_DEFAULT;
	UnitType m_unit_type;
	std::string m_name = "combat unit default name fuck! something is probably wrong";
	std::vector<int> m_bp_growth;
	std::vector<int> m_basic_params;

public:
	CombatUnits(UnitType type);
	virtual ~CombatUnits() = 0;

	int getId();
	UnitType getUnitType();
	std::string getName();
	int getOneBParam(int bParamType);
	const std::vector<int>& getAllBParams() const;

	void setId(int id);
	// void setUnitType(UnitType type);
	void setName(std::string name);
	void setBPGrowth(int bParamType, int value);
	void setBParam(int bParamType, int value); // need another for reducing/gaining hp/mp

	// debug use
	virtual void debugPrintUnitInfo();
};

#endif
