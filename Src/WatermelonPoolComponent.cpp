#include "WatermelonPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"

ADD_COMPONENT(WatermelonPoolComponent);

WatermelonPoolComponent::WatermelonPoolComponent() :EnemyPoolComponent(UserComponentId::WatermelonPoolComponent)
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