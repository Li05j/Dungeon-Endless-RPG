#ifndef _SKILL_MODEL_H_2f63c147_7720_41a1_ae50_138aedd09488_
#define _SKILL_MODEL_H_2f63c147_7720_41a1_ae50_138aedd09488_

#include <vector>
#include <string>

class Skill;

class SkillModel {
private:
	SkillModel();
	virtual ~SkillModel();

	SkillModel(SkillModel const&) = delete; // private copy constructor
	SkillModel& operator=(SkillModel const&) = delete; // private assignment operator

	std::vector<Skill> m_skillData;
	std::string m_dataFileName;

	void populateSkillData();
public:
	static SkillModel& getInstance();

	Skill& getSkill(int skillId);
};

#endif
