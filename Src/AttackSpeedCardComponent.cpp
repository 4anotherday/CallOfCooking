#include "AttackSpeedCardComponent.h"
#include "UserComponentIDs.h"
#include "PlayerAttackComponent.h"
#include "Engine.h"
#include "GameObject.h"

ADD_COMPONENT(AttackSpeedCardComponent);

float AttackSpeedCardComponent::_attackRate = 3;

AttackSpeedCardComponent::AttackSpeedCardComponent() : CardComponent(UserComponentId::UserComponentId::MovementSpeedCardComponent), _player(nullptr) {
}

AttackSpeedCardComponent::~AttackSpeedCardComponent()
{
}

void AttackSpeedCardComponent::start()
{
	//_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
	_player = static_cast<PlayerAttackComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerAttackComponent));
	setCallBackParam(_player);
	setCallBack(operate);
}

void AttackSpeedCardComponent::operate(void* player)
{
	static_cast<PlayerAttackComponent*>(player)->increaseAttackRate(_attackRate);
}