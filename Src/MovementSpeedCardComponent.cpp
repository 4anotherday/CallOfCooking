#include "MovementSpeedCardComponent.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "GameObject.h"
#include "ButtonComponent.h"
#include "PlayerMovementComponent.h"

int MovementSpeedCardComponent::_extraMovementSpeed = 3;

ADD_COMPONENT(MovementSpeedCardComponent);

MovementSpeedCardComponent::MovementSpeedCardComponent() : CardComponent(UserComponentId::UserComponentId::MovementSpeedCardComponent), _player(nullptr) {
}

MovementSpeedCardComponent::~MovementSpeedCardComponent()
{
}

void MovementSpeedCardComponent::start()
{
	_player = static_cast<PlayerMovementComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerMovementComponent));
	setCallBackParam(_player);
	setCallBack(operate);
}

void MovementSpeedCardComponent::operate(void* player)
{
	//Do something with the players movementSpeed
	static_cast<PlayerMovementComponent*>(player)->increaseSpeed(_extraMovementSpeed);
}