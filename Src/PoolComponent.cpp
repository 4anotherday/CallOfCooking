#include "GameObject.h"
#include "Engine.h"
#include "includeLUA.h"
#include "PoolComponent.h"


PoolComponent::PoolComponent(UserComponentId::UserComponentId id): Component(id)
{
}

PoolComponent::~PoolComponent()
{
	for (auto go : _mainPool) {
		delete go;
		go = nullptr;
	}
	_mainPool.clear();
	_inactivePool.clear();
}

GameObject* PoolComponent::getInactiveGO()
{
	if (_inactivePool.empty()) {
		createGos(10);
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
