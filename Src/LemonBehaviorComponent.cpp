#include "LemonBehaviorComponent.h"
#include "ParticleSystemComponent.h"
#include "UserComponentIDs.h"
#include "PlayerHealthComponent.h"
#include "GameObject.h"
#include "Transform.h"
#include "Engine.h"

LemonBehaviorComponent::LemonBehaviorComponent() : EnemyBehaviorComponent(), _pSystem(nullptr), _range()
{
}

LemonBehaviorComponent::~LemonBehaviorComponent()
{
}

void LemonBehaviorComponent::awake(luabridge::LuaRef& data)
{
	_range = data["Range"].cast<float>();
}

void LemonBehaviorComponent::start()
{
	_pSystem = static_cast<ParticleSystemComponent*>(_gameObject->getComponent(ComponentId::ParticleSystem));
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_healthPlayer = static_cast<PlayerHealthComponent*>(_gameObject->getComponent(UserComponentId::Health));
}

void LemonBehaviorComponent::update()
{
	double distance = (_playerPos->getPosition() - _tr->getPosition()).magnitude();
	(distance <= _range) ? _isAttacking = true : _isAttacking = false;
}

void LemonBehaviorComponent::attack()
{
	_pSystem->setEnabled(true);
	_healthPlayer->loseLife(_damagePerSecond);
}
