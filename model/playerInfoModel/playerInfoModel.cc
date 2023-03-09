#include "playerInfoModel.h"
#include "../gameObjects/combatUnits/units/player/player.h"
#include "../gameObjects/combatUnits/units/player/types/fighter.h"

PlayerInfoModel::PlayerInfoModel()
{
    m_party.push_back(std::make_unique<Fighter>());
}

PlayerInfoModel::~PlayerInfoModel() {}

void PlayerInfoModel::addMemberToParty(PlayerType player) 
{
    m_party[player]->addToParty();
}

void PlayerInfoModel::removeMemberFromParty(PlayerType player) 
{
    m_party[player]->removeFromParty();
}