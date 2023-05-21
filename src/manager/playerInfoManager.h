#ifndef _PLAYER_INFO_MANAGER_H_0bb8ae3d_d03a_4c6b_9ad9_f36a3a6b95e1_
#define _PLAYER_INFO_MANAGER_H_0bb8ae3d_d03a_4c6b_9ad9_f36a3a6b95e1_

#include <string>
#include <vector>

class Ally;

class PlayerInfoManager
{
private:
    PlayerInfoManager();
    virtual ~PlayerInfoManager();

    PlayerInfoManager(PlayerInfoManager const&) = delete; // private copy constructor
    PlayerInfoManager& operator=(PlayerInfoManager const&) = delete; // private assignment operator

    std::vector<Ally> m_allyData;
    std::string m_dataFileName;

    unsigned int gold;

    void populateAllyData();

public:
    static PlayerInfoManager& getInstance();

    Ally& getAlly(int allyId);
    void addMemberToParty(int allyId);
    void removeMemberFromParty(int allyId);
};

#endif
