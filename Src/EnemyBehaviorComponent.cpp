#include "EnemyBehaviorComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "Engine.h"
#include "includeLUA.h"
#include "Exceptions.h"

EnemyBehaviorComponent::EnemyBehaviorComponent(UserComponentId::UserComponentId id) : Component(id), _rigidbody(nullptr), _playerPos(nullptr),
_attackSpeed(2.0f), _isAttacking(), _damagePerSecond(1.0f),_movementSpeed(1.0f),_range(1.0f)
{
}

EnemyBehaviorComponent::~EnemyBehaviorComponent()
{
}

void EnemyBehaviorComponent::awake(luabridge::LuaRef& data)
{
	if (LUAFIELDEXIST(AttackSpeed)) _attackSpeed = data["AttackSpeed"].cast<float>();
	if (LUAFIELDEXIST(IsAttacking)) _isAttacking = data["isAttacking"].cast<bool>();
	if (LUAFIELDEXIST(DamagePerSecond)) _damagePerSecond = data["DamagePerSecond"].cast<float>();
}

void EnemyBehaviorComponent::start()
{
	_playerPos = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	_rigidbody = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}
