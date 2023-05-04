#ifndef _PLAYER_INFO_H_0bb8ae3d_d03a_4c6b_9ad9_f36a3a6b95e1_
#define _PLAYER_INFO_H_0bb8ae3d_d03a_4c6b_9ad9_f36a3a6b95e1_

#include <vector>
#include <memory>

class Ally;

class PlayerInfo
{
    std::vector<std::unique_ptr<Ally>> m_party;
    unsigned int gold;

public:
    PlayerInfo();
    virtual ~PlayerInfo();

    void addMemberToParty(Ally player);
    void removeMemberFromParty(Ally player);
};

#endif
