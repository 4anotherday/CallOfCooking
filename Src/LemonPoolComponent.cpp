#include "LemonPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"

ADD_COMPONENT(LemonPoolComponent);

LemonPoolComponent::LemonPoolComponent() :PoolComponent(UserComponentId::LemonPoolComponent)
{
}

LemonPoolComponent::~LemonPoolComponent()
{
}

void LemonPoolComponent::awake(luabridge::LuaRef& data)
{
	//TODO: PEDIR A FACTORIA
	// TR
	// Rigidbody
	// EnemyHealth
	// Beahviour
}

void LemonPoolComponent::start()
{
}

void LemonPoolComponent::update()
{
}

void LemonPoolComponent::createGos(int howMany)
{
}