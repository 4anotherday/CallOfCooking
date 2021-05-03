#include "GameObject.h"
#include "Engine.h"
#include "includeLUA.h"
#include "PoolComponent.h"
#include "LevelManagerComponent.h"

PoolComponent::PoolComponent(UserComponentId::UserComponentId id): Component(id), _lvlManager(), _mainPool(), _inactivePool()
{
}

PoolComponent::~PoolComponent()
{
	for (auto go : _mainPool) {
		delete go;
		go = nullptr;
		//PREGUNTAR SI HAY QUE CAMBIAR ESTO POR ALGUNA LLAMADA A LA LINEA DE ABAJO 
		//Engine::getInstance()->remGameObject(_gameObject);
	}
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