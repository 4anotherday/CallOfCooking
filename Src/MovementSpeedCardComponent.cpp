#include "MovementSpeedCardComponent.h"
#include "PlayerMovementComponent.h"
#include "CardSystemComponent.h"
#include "UserComponentIDs.h"
#include "ButtonComponent.h"
#include "GameObject.h"
#include "Exceptions.h"
#include "Engine.h"

int MovementSpeedCardComponent::_extraMovementSpeed = 30;

ADD_COMPONENT(MovementSpeedCardComponent);

MovementSpeedCardComponent::MovementSpeedCardComponent() : CardComponent(UserComponentId::UserComponentId::MovementSpeedCardComponent), _player(nullptr) {
}

MovementSpeedCardComponent::~MovementSpeedCardComponent()
{
}

void MovementSpeedCardComponent::start()
{
	try {
		CardComponent::start();
		_player = static_cast<PlayerMovementComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerMovementComponent));
		setCallBackParam(_player);
		setCallBack(operate);
	}
	catch (...) {
		throw ExcepcionTAD("Error in gameobject " + _gameObject->getName() + " :the name of the player was wrong, Component: MovementSpeedCardComponent");
	}
}

void MovementSpeedCardComponent::operate(void* player)
{
	//Do something with the players movementSpeed
	static_cast<PlayerMovementComponent*>(player)->increaseSpeed(_extraMovementSpeed);
	static_cast<CardSystemComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::CardSystemComponent))->setCardsUp(false);
}