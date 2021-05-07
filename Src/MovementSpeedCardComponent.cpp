#include "MovementSpeedCardComponent.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "GameObject.h"
#include "ButtonComponent.h"
#include "PlayerMovementComponent.h"

int MovementSpeedCardComponent::_extraMovementSpeed = 3;

MovementSpeedCardComponent::MovementSpeedCardComponent() : CardComponent(UserComponentId::UserComponentId::MovementSpeedCardComponent), _player(nullptr) {
}

MovementSpeedCardComponent::~MovementSpeedCardComponent()
{
}

void MovementSpeedCardComponent::start()
{
	_player = static_cast<PlayerMovementComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerMovementComponent));
}

void MovementSpeedCardComponent::operate()
{
	//Do something with the players movementSpeed
	_player->increaseSpeed(_extraMovementSpeed);
}