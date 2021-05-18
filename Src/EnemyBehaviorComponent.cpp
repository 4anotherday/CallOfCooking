#include "EnemyBehaviorComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "Engine.h"
#include "includeLUA.h"

EnemyBehaviorComponent::EnemyBehaviorComponent(UserComponentId::UserComponentId id) : Component(id), _rigidbody(nullptr), _playerPos(nullptr),
_attackSpeed(), _isAttacking(), _damagePerSecond()
{
}

EnemyBehaviorComponent::~EnemyBehaviorComponent()
{
}

void EnemyBehaviorComponent::awake(luabridge::LuaRef& data)
{
	_attackSpeed = data["AttackSpeed"].cast<float>();
	_isAttacking = data["isAttacking"].cast<bool>();
	_damagePerSecond = data["DamagePerSecond"].cast<float>();
}

void EnemyBehaviorComponent::start()
{
	_playerPos = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}
