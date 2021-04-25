#include "PlayerAttackComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "MouseInput.h"
#include "EngineTime.h"
#include "Transform.h"
#include "RigidBodyComponent.h"

PlayerAttackComponent::PlayerAttackComponent() : Component(UserComponentId::PlayerAttackComponent),
_tr(nullptr), _rb(nullptr), _attackKey(KeyCode::KEYCODE_P), _damage(5),
_mouse(MouseInput::getInstance()),_engineTime(EngineTime::getInstance()), _attackRate(0.5),_lastAttack(_engineTime->deltaTime())
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_mouse->setMouseRelativeMode(false);
}

PlayerAttackComponent::PlayerAttackComponent(GameObject* gameObject) : Component(UserComponentId::PlayerAttackComponent, gameObject),
_tr(nullptr), _rb(nullptr), _attackKey(KeyCode::KEYCODE_P), _damage(5),
_mouse(MouseInput::getInstance()), _engineTime(EngineTime::getInstance()), _attackRate(0.5), _lastAttack(_engineTime->deltaTime())
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_mouse->setMouseRelativeMode(false);
}

PlayerAttackComponent::~PlayerAttackComponent()
{
	delete _tr; _tr = nullptr;
	delete _rb; _rb = nullptr;
}

void PlayerAttackComponent::awake(luabridge::LuaRef& data)
{

}

void PlayerAttackComponent::start()
{
	//Here we should take a gameobject child which contains a collider (attack hitbox)

}

void PlayerAttackComponent::update()
{	
	float currentDeltaTime = _engineTime->deltaTime();

	rotateAttackHitBox(currentDeltaTime);
	attack(currentDeltaTime);
}

void PlayerAttackComponent::rotateAttackHitBox(float deltaTime)
{


}

void PlayerAttackComponent::attack(float deltaTime)
{
	if (_mouse->isMouseButtonJustDown(MouseButton::LEFT) && _engineTime->deltaTime() > _lastAttack + _attackRate)
	{
		_lastAttack = _engineTime->deltaTime();



	}
}
