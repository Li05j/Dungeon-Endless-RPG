#include "battleLoggerModel.h"

#include "./src/utils/debugUtils.h"

BattleLoggerModel::BattleLoggerModel() : m_max_log_size(5), m_log_size(0) {}

BattleLoggerModel::~BattleLoggerModel() {}

BattleLoggerModel& BattleLoggerModel::getInstance() {
    static BattleLoggerModel instance;
    return instance;
}

std::deque<std::string>& BattleLoggerModel::getBattleLogs()
{
    return m_battle_logs;
}

void BattleLoggerModel::pushBattleLog(std::string log)
{
    if (m_log_size == m_max_log_size) {
        m_battle_logs.pop_front();
    }
    else {
        m_log_size++;
    }
    m_battle_logs.push_back(log);
}

void BattleLoggerModel::setMaxLogDisplayCount(int count)
{
    m_max_log_size = count;
}

