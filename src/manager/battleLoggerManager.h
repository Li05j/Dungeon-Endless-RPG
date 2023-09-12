#ifndef _BATTLE_LOGGER_MANAGER_H_832e5996_d10a_472e_9e82_4868c3ee594f_
#define _BATTLE_LOGGER_MANAGER_H_832e5996_d10a_472e_9e82_4868c3ee594f_

#include <string>
#include <deque>

class BattleLoggerManager {
private:
	BattleLoggerManager();
	virtual ~BattleLoggerManager();

	BattleLoggerManager(BattleLoggerManager const&) = delete; // private copy constructor
	BattleLoggerManager& operator=(BattleLoggerManager const&) = delete; // private assignment operator

	int m_max_log_size;
	int m_log_size;
	std::deque<std::string> m_battle_logs;

public:
	static BattleLoggerManager& getInstance();

	std::deque<std::string>& getBattleLogs();

	void pushBattleLog(std::string log);
	void setMaxLogDisplayCount(int count);
};

#endif
