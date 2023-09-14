#ifndef _BATTLE_LOGGER_MODEL_H_832e5996_d10a_472e_9e82_4868c3ee594f_
#define _BATTLE_LOGGER_MODEL_H_832e5996_d10a_472e_9e82_4868c3ee594f_

#include <string>
#include <deque>

class BattleLoggerModel {
private:
	BattleLoggerModel();
	virtual ~BattleLoggerModel();

	BattleLoggerModel(BattleLoggerModel const&) = delete; // private copy constructor
	BattleLoggerModel& operator=(BattleLoggerModel const&) = delete; // private assignment operator

	int m_max_log_size;
	int m_log_size;
	std::deque<std::string> m_battle_logs;

public:
	static BattleLoggerModel& getInstance();

	std::deque<std::string>& getBattleLogs();

	void pushBattleLog(std::string log);
	void setMaxLogDisplayCount(int count);
};

#endif
