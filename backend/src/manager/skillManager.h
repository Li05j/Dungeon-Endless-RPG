#ifndef _SKILL_MANAGER_H_2f63c147_7720_41a1_ae50_138aedd09488_
#define _SKILL_MANAGER_H_2f63c147_7720_41a1_ae50_138aedd09488_

#include <vector>
#include <string>

class Skill;

class SkillManager {
private:
	SkillManager();
	virtual ~SkillManager();

	SkillManager(SkillManager const&) = delete; // private copy constructor
	SkillManager& operator=(SkillManager const&) = delete; // private assignment operator

	std::vector<Skill> m_skillData;
	std::string m_dataFileName;

	void populateSkillData();
public:
	static SkillManager& getInstance();

	Skill& getSkill(int skillId);
};

#endif
