#include "WatermelonPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"

WatermelonPoolComponent::WatermelonPoolComponent():PoolComponent(UserComponentId::WatermelonPoolComponent)
{
}

WatermelonPoolComponent::~WatermelonPoolComponent()
{
}

void WatermelonPoolComponent::awake(luabridge::LuaRef& data)
{
	//TODO: PEDIR A FACTORIA
	// TR
	// Rigidbody
	// EnemyHealth
	// Beahviour
}

void WatermelonPoolComponent::start()
{
}

void WatermelonPoolComponent::update()
{
}

void WatermelonPoolComponent::createGos(int howMany)
{
}