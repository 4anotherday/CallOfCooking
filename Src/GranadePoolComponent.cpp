#include "GranadePoolComponent.h"
#include "UserComponentIDs.h"
#include "GameObject.h"
#include "Engine.h"
#include "EnemyHealthComponent.h"
#include "GrenadeBehaviorComponent.h"
#include "RenderObjectComponent.h"
#include "Transform.h"
#include "includeLUA.h"

ADD_COMPONENT(GranadePoolComponent);

GranadePoolComponent::GranadePoolComponent() : PoolComponent(UserComponentId::GranadePoolComponent)
{
}

GranadePoolComponent::~GranadePoolComponent()
{
}

void GranadePoolComponent::awake(luabridge::LuaRef& data)
{
	int cuantos = data["HowMany"]["Round1"].cast<int>();
	float width = data["Width"].cast<int>();
	float heigh = data["Height"].cast<int>();
	float healthPoint = data["HpPoints"].cast<int>();
	float movementSpeed = data["MovementSpeed"].cast<int>();

	GameObject* nuevo;
	for (int i = 0; i < cuantos; i++) {
		nuevo = Engine::getInstance()->addGameObject();

		GrenadeBehaviorComponent* behaviour = new GrenadeBehaviorComponent();
		EnemyHealthComponent* health = new EnemyHealthComponent();

		nuevo->addComponent(behaviour);
		nuevo->addComponent(health);
		nuevo->addComponent(behaviour);
	}

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

void GranadePoolComponent::wakeUpInactiveGroup(int howMany)
{
}

void GranadePoolComponent::createGos(int howMany)
{
}