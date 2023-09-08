#ifndef _PLAYER_INFO_MANAGER_H_0bb8ae3d_d03a_4c6b_9ad9_f36a3a6b95e1_
#define _PLAYER_INFO_MANAGER_H_0bb8ae3d_d03a_4c6b_9ad9_f36a3a6b95e1_

#include <string>
#include <vector>
#include <memory>

class Ally;
class AllyManager;

class PlayerInfoManager
{
private:
    PlayerInfoManager(AllyManager& allyM);
    virtual ~PlayerInfoManager();

    PlayerInfoManager(PlayerInfoManager const&) = delete; // private copy constructor
    PlayerInfoManager& operator=(PlayerInfoManager const&) = delete; // private assignment operator

    AllyManager& m_allyM;

    std::vector<int> m_party; // 0 means not in party, 1 means in party
    int m_current_party_size;
    unsigned int gold;

public:
    static PlayerInfoManager& getInstance(AllyManager& allyM);

    void addMemberToParty(int allyId);
    void removeMemberFromParty(int allyId);
    int getCurrentPartySize();

    // debug
    void debugPrintPartyInfo();
};

#endif
