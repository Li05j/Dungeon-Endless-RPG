#ifndef _ROUTES_H_73fccf24_278d_4ab0_8558_110cb28af372_
#define _ROUTES_H_73fccf24_278d_4ab0_8558_110cb28af372_

#include "./include/crow.h"

class BattleControllerV2;
class BattleResponseIface;

class Routes {
private:
	BattleControllerV2& m_battleC_V2;
	crow::response prepareResponse(BattleResponseIface data);

public:
	Routes(BattleControllerV2& battleC_V2);
	virtual ~Routes();

	void run();
};

#endif
