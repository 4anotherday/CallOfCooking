#include "GameObject.h"
#include "Engine.h"
#include "PoolComponent.h"
#include "LevelManagerComponent.h"
#include "Exceptions.h"

PoolComponent::PoolComponent(UserComponentId::UserComponentId id) : Component(id), _lvlManager(), _mainPool(), _inactivePool()
{
}

PoolComponent::~PoolComponent()
{
	//TODO: MIRAR CON CHECKHML MÁS ADELANTE SI SE ESTÁ DEJANDO BASURA
	_mainPool.clear();
	_inactivePool.clear();
}

void PoolComponent::start()
{
	_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
}

GameObject* PoolComponent::getInactiveGO()
{
	if (_inactivePool.empty()) {
		return nullptr;
	}
	GameObject* go = _inactivePool.back();
	_inactivePool.pop_back();
	go->setEnabled(true);
	return go;
}

void PoolComponent::setInactiveGO(GameObject* go)
{
	go->setEnabled(false);
	_inactivePool.push_back(go);
}