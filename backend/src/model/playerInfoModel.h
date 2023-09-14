#ifndef _PLAYER_INFO_MODEL_H_0bb8ae3d_d03a_4c6b_9ad9_f36a3a6b95e1_
#define _PLAYER_INFO_MODEL_H_0bb8ae3d_d03a_4c6b_9ad9_f36a3a6b95e1_

#include <string>
#include <vector>
#include <memory>

class Ally;
class AllyModel;

class PlayerInfoModel
{
private:
    PlayerInfoModel(AllyModel& allyM);
    virtual ~PlayerInfoModel();

    PlayerInfoModel(PlayerInfoModel const&) = delete; // private copy constructor
    PlayerInfoModel& operator=(PlayerInfoModel const&) = delete; // private assignment operator

    AllyModel& m_allyM;

    std::vector<int> m_party; // 0 means not in party, 1 means in party
    int m_current_party_size;
    unsigned int gold;

public:
    static PlayerInfoModel& getInstance(AllyModel& allyM);

    void addMemberToParty(int allyId);
    void removeMemberFromParty(int allyId);

    const std::vector<int>& getPlayerParty() const;
    int getCurrentPartySize();

    // debug
    void debugPrintPartyInfo();
};

#endif
