#include "AttackSpeedCardComponent.h"
#include "PlayerAttackComponent.h"
#include "PlayerShootComponent.h"
#include "CardSystemComponent.h"
#include "UserComponentIDs.h"
#include "Exceptions.h"
#include "GameObject.h"
#include "Engine.h"

ADD_COMPONENT(AttackSpeedCardComponent);

float AttackSpeedCardComponent::_attackRate = 3;

AttackSpeedCardComponent::AttackSpeedCardComponent() : CardComponent(UserComponentId::UserComponentId::MovementSpeedCardComponent), 
_shootComponent(nullptr)
{
}

AttackSpeedCardComponent::~AttackSpeedCardComponent()
{
}

void AttackSpeedCardComponent::start()
{
	CardComponent::start();
	_shootComponent = static_cast<PlayerShootComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerShootComponent));
	setCallBackParam(_shootComponent);
	setCallBack(operate);
}

void AttackSpeedCardComponent::operate(void* player)
{
	static_cast<PlayerShootComponent*>(player)->increaseAttackSpeed();
	static_cast<CardSystemComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::CardSystemComponent))->setCardsUp(false);
}