#ifndef _BATTLE_RESPONSE_IFACE_H_d71dab45_63fb_494e_994f_0a21b6689c9e_
#define _BATTLE_RESPONSE_IFACE_H_d71dab45_63fb_494e_994f_0a21b6689c9e_

#include <string>
#include <vector>

class BattleResponseIface {
private:

public:
	int turn;
	std::string allyName;
	int allyCurrHp;
	int allyMaxHp;
	std::string enemyName;
	int enemyCurrHp;
	int enemyMaxHp;
	std::vector<std::string> battleLogs;

	BattleResponseIface(int _turn, const std::string& _allyName, int _allyCurrHp, int _allyMaxHp,
		const std::string& _enemyName, int _enemyCurrHp, int _enemyMaxHp, std::vector<std::string> _battleLogs)
		: turn(_turn), allyName(_allyName), allyCurrHp(_allyCurrHp), allyMaxHp(_allyMaxHp),
		enemyName(_enemyName), enemyCurrHp(_enemyCurrHp), enemyMaxHp(_enemyMaxHp), battleLogs(_battleLogs) {}
	virtual ~BattleResponseIface() {};
};

#endif
