#include "AttackSpeedCardComponent.h"
#include "PlayerAttackComponent.h"
#include "CardSystemComponent.h"
#include "UserComponentIDs.h"
#include "GameObject.h"
#include "Engine.h"

ADD_COMPONENT(AttackSpeedCardComponent);

float AttackSpeedCardComponent::_attackRate = 3;

AttackSpeedCardComponent::AttackSpeedCardComponent() : CardComponent(UserComponentId::UserComponentId::MovementSpeedCardComponent), _player(nullptr) {
}

AttackSpeedCardComponent::~AttackSpeedCardComponent()
{
}

void AttackSpeedCardComponent::start()
{
	CardComponent::start();
	//_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
	_player = static_cast<PlayerAttackComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerAttackComponent));
	setCallBackParam(_player);
	setCallBack(operate);
}

void AttackSpeedCardComponent::operate(void* player)
{
	static_cast<PlayerAttackComponent*>(player)->increaseAttackRate(_attackRate);
	static_cast<CardSystemComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::CardSystemComponent))->setCardsUp(false);
}