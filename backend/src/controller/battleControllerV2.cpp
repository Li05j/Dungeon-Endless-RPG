///////////////////////////// THIS IS FOR REACT /////////////////////////////

#include "./battleControllerV2.h"

#include <algorithm>
// #include "./include/crow.h"

#include "./src/blueprint/combatUnits/enemy/enemy.h"
#include "./src/blueprint/combatUnits/ally/ally.h"

#include "./src/interface/battleResponseIface.h"

#include "./src/model/allyModel.h"
#include "./src/model/battleModel.h"
#include "./src/model/battleLoggerModel.h"
#include "./src/model/enemyModel.h"
#include "./src/model/playerInfoModel.h"

#include "./src/utils/debugUtils.h"
#include "./src/utils/helperUtils.h"
#include "./src/utils/playerUtils.h"
#include "battleControllerV2.h"

BattleControllerV2::BattleControllerV2(
	BattleModel& battleM,
	AllyModel& allyM,
	EnemyModel& enemyM,
	PlayerInfoModel& playerM,
	BattleLoggerModel& battleLogM) :
	m_battleM(battleM), m_allyM(allyM), m_enemyM(enemyM), m_playerM(playerM), m_battleLogM(battleLogM)
{}

BattleControllerV2::~BattleControllerV2() {}

BattleControllerV2& BattleControllerV2::getInstance(
	BattleModel& battleM,
	AllyModel& allyM,
	EnemyModel& enemyM,
	PlayerInfoModel& playerM,
	BattleLoggerModel& battleLogM)
{
	static BattleControllerV2 instance(battleM, allyM, enemyM, playerM, battleLogM);
	return instance;
}

BattleResponseIface BattleControllerV2::prepareBattle() {
	populateAllyBattle();
	DEBUG(DB_GENERAL, "prepareBattle() above is prep battle populate ally.\n");
	populateEnemyBattle();
	m_battleM.resetbattleVictory();
	m_battleM.resetMoveOrder();
	m_battleM.resetTurnCounter();
	// startBattle();
	return fetchData();
}

BattleResponseIface BattleControllerV2::nextTurn()
{
	if (!m_battleM.isBattleEnd()) {
		m_battleM.incrementTurnCounter();
		preTurn();
		// DEBUG(DB_GENERAL, "preturn owo\n");
		duringTurn();
		// DEBUG(DB_GENERAL, "duringturn owo\n");
		postTurn();
		// DEBUG(DB_GENERAL, "postturn owo\n");
	}
	else {
		endBattle();
	}
	return fetchData();
}

void BattleControllerV2::startBattle()
{
	while (!m_battleM.isBattleEnd()) {
		m_battleM.incrementTurnCounter();
		preTurn();
		// DEBUG(DB_GENERAL, "preturn owo\n");
		duringTurn();
		// DEBUG(DB_GENERAL, "duringturn owo\n");
		postTurn();
		// DEBUG(DB_GENERAL, "postturn owo\n");
	}
	endBattle();
}

void BattleControllerV2::populateAllyBattle() {
	// test if non empty - this is assuming only one ally can exist.
	if (m_battleM.getAllyBattle().size() > 0) {
		return;
	}
	const std::vector<int>& playerParty = m_playerM.getPlayerParty();
	int allyCount = 0;
	for (int i = 0; i < TOTAL_ALLY; i++) {
		if (playerParty.at(i)) {
			m_battleM.pushAllyForBattle(m_allyM.getAlly(i));
			allyCount++;
		}
	}

	if (allyCount > MAX_PARTY_SIZE) {
		DEBUG(DB_GENERAL, "ERROR -- populateEnemyBattle(): too many allies, ally count: %d", allyCount);
	}
}

void BattleControllerV2::populateEnemyBattle() {
	// TODO: random multiple enemies
	// TODO: will need to check level/location etc to get appropriate enemies

	// test if non empty - this is assuming only one ally can exist.
	if (m_battleM.getEnemyBattle().size() > 0) {
		return;
	}

	int randomEnemy = generateRandomNumber(1, 2);
	m_battleM.pushEnemyForBattle(m_enemyM.getEnemy(randomEnemy));
}

void BattleControllerV2::preTurn()
{
	m_battleM.resetMoveOrder();
	// determineMoveOrder();
	// wait(1);
}

void BattleControllerV2::duringTurn()
{
	// attack
	auto& moveOrder = m_battleM.getMoveOrder();
	for (auto unit : moveOrder) {
		auto& allyBattleUnits = m_battleM.getAllyBattle();
		auto& enemyBattleUnits = m_battleM.getEnemyBattle();

		DEBUG(DB_GENERAL, "duringTurn() ally battle units? %ld\n", allyBattleUnits.size());

		// since there is only one ally and one enemy, subject and target are all 0.
		int subjectIdx = 0;
		int targetIdx = 0;

		auto& ally = allyBattleUnits.at(subjectIdx);
		auto& enemy = enemyBattleUnits.at(targetIdx);

		if (unit->getUnitType() == ALLY_UNIT) {
			// TODO: below is dummy damage calculation. need to replace it to a meaningful one.
			useDefaultAttack(ally.getName(), enemy.getName(), enemy.getUnitType(), targetIdx, 20);
		}
		else if (unit->getUnitType() == ENEMY_UNIT) {
			// TODO: below is dummy damage calculation. need to replace it to a meaningful one.
			useDefaultAttack(enemy.getName(), ally.getName(), ally.getUnitType(), targetIdx, 20);
		}
		else {
			// should'nt end up here
			DEBUG(DB_GENERAL, "ERROR - duringTurn(): unknown unit type: %d.\n", unit->getId());
		}
		checkEnemyPartyWipe();
		checkAllyPartyWipe();
	}
}

void BattleControllerV2::postTurn()
{
	// do nothing for now;
	// wait(1);
}

void BattleControllerV2::checkAllyPartyWipe()
{
	auto& allyBattle = m_battleM.getAllyBattle();
	for (auto& unit : allyBattle) {
		if (unit.getOneBParam(B_CURRHP) > 0) {
			return;
		}
	}
	m_battleM.gameOver();
	m_battleM.resetMoveOrder();
}

void BattleControllerV2::checkEnemyPartyWipe()
{
	auto& m_enemyBattle = m_battleM.getEnemyBattle();
	for (auto& unit : m_enemyBattle) {
		if (unit.getOneBParam(B_CURRHP) > 0) {
			return;
		}
	}
	m_battleM.battleVictory();
	m_battleM.resetMoveOrder();
}

void BattleControllerV2::useDefaultAttack(std::string subjectName, std::string targetName, UnitType targetUnitType, int targetIdx, int damage)
{
	m_battleLogM.pushBattleLog(damageLog(subjectName, targetName, 20)); // dummy damage number
	m_battleM.changeUnitParam(targetUnitType, targetIdx, -damage);
}

void BattleControllerV2::endBattle() {
	m_battleM.resetTurnCounter();
	m_battleM.resetMoveOrder();

	m_battleM.resetAllyBattle();
	m_battleM.resetEnemyBattle();
}

BattleResponseIface BattleControllerV2::fetchData()
{
	std::vector<std::string> battleLogs;

	for (auto& log : m_battleLogM.getBattleLogs()) {
		battleLogs.push_back(log);
	}

	bool battleEnd = m_battleM.isBattleEnd();

	if (m_battleM.isBattleEnd()) {
		BattleResponseIface response = BattleResponseIface(battleLogs, battleEnd);
		return response;
	}

	auto& ally = m_battleM.getAllyBattle().at(0); // 0 because there is only 1 ally/enemy
	auto& enemy = m_battleM.getEnemyBattle().at(0);

	int turn = m_battleM.getTurn();
	std::string allyName = ally.getName();
	int allyCurrHp = ally.getOneBParam(B_CURRHP);
	int allyMaxHp = ally.getOneBParam(B_MAXHP);
	std::string enemyName = enemy.getName();
	int enemyCurrHp = enemy.getOneBParam(B_CURRHP);
	int enemyMaxHp = enemy.getOneBParam(B_MAXHP);

	BattleResponseIface response = BattleResponseIface(turn, allyName, allyCurrHp, allyMaxHp, enemyName, enemyCurrHp, enemyMaxHp, battleLogs, battleEnd);

	return response;
}

std::string BattleControllerV2::damageLog(std::string subject, std::string object, int damage, bool crit)
{
	std::string log = std::string();
	if (!crit) {
		log = subject + " dealt " + std::to_string(damage) + " damage to " + object + " !";
	}
	return log;
}

const std::deque<std::string>& BattleControllerV2::getBattleLogs() const
{
	return m_battleLogM.getBattleLogs();
}