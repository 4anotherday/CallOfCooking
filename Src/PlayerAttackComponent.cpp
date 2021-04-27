#include "PlayerAttackComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "MouseInput.h"
#include "EngineTime.h"
#include "Transform.h"
#include "RigidBodyComponent.h"

PlayerAttackComponent::PlayerAttackComponent() : Component(UserComponentId::PlayerAttackComponent),
_tr(nullptr), _rb(nullptr), _damage(5),
_mouse(MouseInput::getInstance()), _engineTime(EngineTime::getInstance()), _attackRate(0.5), _lastAttack(_engineTime->deltaTime())
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_mouse->setMouseRelativeMode(false);
}

PlayerAttackComponent::PlayerAttackComponent(GameObject* gameObject) : Component(UserComponentId::PlayerAttackComponent, gameObject),
_tr(nullptr), _rb(nullptr), _damage(5),
_mouse(MouseInput::getInstance()), _engineTime(EngineTime::getInstance()), _attackRate(0.5), _lastAttack(_engineTime->deltaTime())
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_mouse->setMouseRelativeMode(false);
}

PlayerAttackComponent::~PlayerAttackComponent()
{
}

void PlayerAttackComponent::awake(luabridge::LuaRef& data)
{
	_damage = data["Damage"].cast<float>();
	_lastAttack = data["Damage"].cast<float>();
	_attackRate = data["Damage"].cast<float>();
	_attackHitBoxDistance = data["Damage"].cast<float>();
}

void PlayerAttackComponent::start()
{
	_parent = _gameObject->getParent();
}

void PlayerAttackComponent::update()
{
	float currentDeltaTime = _engineTime->deltaTime();

	rotateAttackHitBox();
	attack(currentDeltaTime);
}

void PlayerAttackComponent::onTrigger(GameObject* other)
{
	//The enemy is in player range
	//static_cast<Enemy*>(other)->setInPlayerRange(true);
}

void PlayerAttackComponent::rotateAttackHitBox()
{
	Vector3 attackDir = Vector3(_mouse->getMousePos().at(0) - _tr->getPosition().getX(), _mouse->getMousePos().at(1) - _tr->getPosition().getY(), 0.0f).normalize();
	_tr->setPosition(static_cast<Transform*>(_parent->getComponent(ComponentId::Transform))->getPosition() + attackDir * _attackHitBoxDistance);
}

void PlayerAttackComponent::attack(float deltaTime)
{
	//Enemies are not in player range
	/*for (auto& e : enemiesPool)
	{
		Transform* enemyTr = static_cast<Transform*>(e->getComponent(ComponentId::Transform));

		float distance = (_tr->getPosition() - enemyTr->getPosition()).magnitude();

		if (distance > _attackHitBoxDistance)
		{
			e->setInPlayerRange(true);
		}
	}*/

	//Here we attack
	if (_mouse->isMouseButtonJustDown(MouseButton::LEFT) && deltaTime > _lastAttack + _attackRate)
	{
		_lastAttack = deltaTime;

		/*for (auto& e : enemiesPool)
		{
			if (e->inPlayerRange())
			{
				e->recieveDamage(_damage);
			}
		}*/
	}
}