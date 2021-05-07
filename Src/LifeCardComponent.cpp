#include "LifeCardComponent.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "GameObject.h"
#include "PlayerHealthComponent.h"
#include "includeLUA.h"

int LifeCardComponent::_extraLife = 3;

LifeCardComponent::LifeCardComponent() : CardComponent(UserComponentId::UserComponentId::LifeCardComponent), _player(nullptr) {
}

LifeCardComponent::~LifeCardComponent()
{
}

void LifeCardComponent::start()
{
	_player = static_cast<PlayerHealthComponent*>(Engine::getInstance()->findGameObject("Player")->getComponent(UserComponentId::Health));
}

void LifeCardComponent::awake(luabridge::LuaRef& data)
{
	setCallBack(operate);
	setCallBackParam(_player);
}

void LifeCardComponent::operate(void* player)
{
	//Do something with the player life
	static_cast<PlayerHealthComponent*>(player)->addLife(_extraLife);
}