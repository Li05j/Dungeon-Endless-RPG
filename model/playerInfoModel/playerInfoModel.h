#ifndef __PLAYER_INFO_MODEL_H_
#define __PLAYER_INFO_MODEL_H_

#include <memory>
#include <vector>
#include "utils/combatUnitsUtils.h"
#include "model.h"

class Player;

class PlayerInfoModel : public Model
{
    std::vector<std::unique_ptr<Player>> m_party;
public:
    PlayerInfoModel();
    virtual ~PlayerInfoModel();

    void addMemberToParty(PlayerType player);
    void removeMemberFromParty(PlayerType player);
};

#endif