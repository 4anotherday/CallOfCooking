#include "AttackSpeedCardComponent.h"
#include "UserComponentIDs.h"
#include "PlayerAttackComponent.h"
#include "Engine.h"
#include "GameObject.h"

AttackSpeedCardComponent::AttackSpeedCardComponent() : CardComponent(UserComponentId::UserComponentId::MovementSpeedCardComponent), _player(nullptr) {
}

AttackSpeedCardComponent::~AttackSpeedCardComponent()
{
}

void AttackSpeedCardComponent::start()
{
	//_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
	_player = static_cast<PlayerAttackComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerAttackComponent));
}

void AttackSpeedCardComponent::operate()
{
	//Do something with the players movementSpeed
}