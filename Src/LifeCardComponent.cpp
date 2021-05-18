#include "PlayerHealthComponent.h"
#include "CardSystemComponent.h"
#include "LifeCardComponent.h"
#include "UserComponentIDs.h"
#include "includeLUA.h"
#include "GameObject.h"
#include "Engine.h"

ADD_COMPONENT(LifeCardComponent);

int LifeCardComponent::_extraLife = 3;

LifeCardComponent::LifeCardComponent() : CardComponent(UserComponentId::UserComponentId::LifeCardComponent), _player(nullptr) {
}

LifeCardComponent::~LifeCardComponent()
{
}

void LifeCardComponent::start()
{
	CardComponent::start();

	_player = static_cast<PlayerHealthComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::PlayerHealthComponent));
	setCallBackParam(_player);
	setCallBack(operate);
}

void LifeCardComponent::operate(void* player)
{
	//Do something with the player life
	static_cast<PlayerHealthComponent*>(player)->addLife(_extraLife);
	static_cast<CardSystemComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::CardSystemComponent))->setCardsUp(false);
}