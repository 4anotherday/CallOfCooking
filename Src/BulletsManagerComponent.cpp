#include "BulletsManagerComponent.h"
#include "UserComponentIDs.h"
#include "EngineTime.h"
#include "includeLUA.h"

ADD_COMPONENT(BulletsManagerComponent);

BulletsManagerComponent::BulletsManagerComponent() : Component(UserComponentId::BulletsManagerComponent),
_engineTime(EngineTime::getInstance())
{
}

BulletsManagerComponent::~BulletsManagerComponent()
{
}

void BulletsManagerComponent::awake(luabridge::LuaRef& data)
{
}

void BulletsManagerComponent::update()
{
}

void BulletsManagerComponent::spawnPlayerBullet()
{
}

void BulletsManagerComponent::spawnEnemyBullet()
{
}