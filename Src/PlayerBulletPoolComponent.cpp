#include "PlayerBulletPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"

PlayerBulletPoolComponent::PlayerBulletPoolComponent() :PoolComponent(UserComponentId::PlayerBulletsManagerComponent)
{
}

PlayerBulletPoolComponent::~PlayerBulletPoolComponent()
{
}

void PlayerBulletPoolComponent::awake(luabridge::LuaRef& data)
{
}

void PlayerBulletPoolComponent::start()
{
}

void PlayerBulletPoolComponent::update()
{
}

GameObject* PlayerBulletPoolComponent::instantiate()
{
	return getInactiveGO();
}

void PlayerBulletPoolComponent::createGos(int howMany)
{
}