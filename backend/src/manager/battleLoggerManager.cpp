#include "battleLoggerManager.h"

#include "./src/utils/debugUtils.h"

BattleLoggerManager::BattleLoggerManager() : m_max_log_size(5), m_log_size(0) {}

BattleLoggerManager::~BattleLoggerManager() {}

BattleLoggerManager& BattleLoggerManager::getInstance() {
    static BattleLoggerManager instance;
    return instance;
}

std::deque<std::string>& BattleLoggerManager::getBattleLogs()
{
    return m_battle_logs;
}

void BattleLoggerManager::pushBattleLog(std::string log)
{
    if (m_log_size == m_max_log_size) {
        m_battle_logs.pop_front();
    }
    else {
        m_log_size++;
    }
    m_battle_logs.push_back(log);
}

void BattleLoggerManager::setMaxLogDisplayCount(int count)
{
    m_max_log_size = count;
}

