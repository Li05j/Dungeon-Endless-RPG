#ifndef _BATTLE_RESPONSE_IFACE_H_d71dab45_63fb_494e_994f_0a21b6689c9e_
#define _BATTLE_RESPONSE_IFACE_H_d71dab45_63fb_494e_994f_0a21b6689c9e_

#include <string>

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

	BattleResponseIface(int _turn, const std::string& _allyName, int _allyCurrHp, int _allyMaxHp,
		const std::string& _enemyName, int _enemyCurrHp, int _enemyMaxHp)
		: turn(_turn), allyName(_allyName), allyCurrHp(_allyCurrHp), allyMaxHp(_allyMaxHp),
		enemyName(_enemyName), enemyCurrHp(_enemyCurrHp), enemyMaxHp(_enemyMaxHp) {}
	virtual ~BattleResponseIface() {};
};

#endif
