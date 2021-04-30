#include "PlayerShootComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "MouseInput.h"
#include "EngineTime.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "includeLUA.h"


PlayerShootComponent::PlayerShootComponent() : Component(UserComponentId::PlayerShootComponent),
_tr(nullptr), _rb(nullptr), _damage(5),
_mouse(MouseInput::getInstance()), _engineTime(EngineTime::getInstance()), _shotRate(0.5), _lastShot(_engineTime->deltaTime())
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}

PlayerShootComponent::~PlayerShootComponent()
{
}

void PlayerShootComponent::awake(luabridge::LuaRef& data)
{
	_damage = data["Damage"].cast<float>();
	_shotRate = data["Damage"].cast<float>();
}

void PlayerShootComponent::start()
{
}

void PlayerShootComponent::update()
{
	float currentDeltaTime = _engineTime->deltaTime();
	if (currentDeltaTime > _lastShot + _shotRate && _mouse->isMouseButtonJustDown(MouseButton::RIGHT))
	{
		_lastShot = currentDeltaTime;
		shoot();
	}
}

void PlayerShootComponent::onTrigger(GameObject* other)
{
	//The enemy is in player range
	//static_cast<Enemy*>(other)->setInPlayerRange(true);
}

void PlayerShootComponent::shoot()
{
	//Me quedo con la dirección a la que dispara el player
	Vector3 direction = _tr->getForward();
	Vector3 position = _tr->getPosition() + direction.normalize() * 5; //Me coloco un poco más alante que el player

	//Instanciar la bala
}