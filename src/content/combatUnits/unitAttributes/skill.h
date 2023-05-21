#ifndef _SKILL_H_a907d908_a437_47fa_a80b_5565cf6ef632_
#define _SKILL_H_a907d908_a437_47fa_a80b_5565cf6ef632_

#include <string>
#include <vector>

class Skill {
private:
	int m_id;
	std::string m_name;
	// int m_type;
	int m_pow;
	int m_target; // TargetType, when SELF, range is ignored
	// int m_range; // special values: SKILL_RANGE_NOT_APPLICABLE and SKILL_RANGE_ALL
	// int m_fHpCost;
	// int m_pHpCost;
	// int m_fMpCost;
	// int m_pMpCost;
	// int m_buff; // TODO: buff array in future
	// int m_debuff; // TODO: debuff array in future
	// int m_cd;
public:
	Skill();
	virtual ~Skill();

	void setId(int id);
	void setName(std::string name);

	void setPow(int pow);
	void setTarget(std::string target);

	// debug use
	void debugPrintSkill();
};

#endif
