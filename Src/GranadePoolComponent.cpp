#include "GranadePoolComponent.h"
#include "UserComponentIDs.h"

GranadePoolComponent::GranadePoolComponent() : PoolComponent(UserComponentId::GrenadePoolComponent)
{
}

GranadePoolComponent::~GranadePoolComponent()
{
}

void GranadePoolComponent::awake(luabridge::LuaRef& data)
{
	//TODO: PEDIR A FACTORIA
	// TR
	// Rigidbody
	// EnemyHealth
	// Beahviour
}

void GranadePoolComponent::start()
{
}

void GranadePoolComponent::update()
{
}

void GranadePoolComponent::createGos(int howMany)
{
}