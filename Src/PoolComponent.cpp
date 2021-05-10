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
		//EXCEPCIÓN
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

void PoolComponent::loadPrefab(std::string path, int howMany)
{
	lua_State* LuaVM;
	LuaVM = luaL_newstate();
	luaL_openlibs(LuaVM);
	int r = luaL_dofile(LuaVM, path.c_str());

	if (r != LUA_OK) {
		std::cout << lua_tostring(LuaVM, -1) << std::endl;
		//Excepción formal y salir de este método
		Logger::getInstance()->log("Archivo de carga de escena de lua no encontrado", Logger::Level::FATAL);
	}
	else {
		luabridge::getGlobalNamespace(LuaVM);

		std::string prefabLua = "prefab";
		luabridge::LuaRef itemPool = luabridge::getGlobal(LuaVM, prefabLua.c_str());

		std::string itemBaseName = itemPool[0]["Name"];

		int cont = 0;
		for (int x = 0; x < howMany; ++x) {
			GameObject* go = Engine::getInstance()->addGameObject();

			std::string goName = itemBaseName + std::to_string(cont);
			go->setName(goName);
			++cont;

			go->setEnabled(false);
			_mainPool.push_back(go);
			_inactivePool.push_back(go);
		}

		for (int x = 0; x < howMany; ++x) {
			for (int j = 1; j < itemPool.length(); ++j) {
				Component* co = ComponentsFactory::getInstance()->getComponentByName(itemPool[j]["Component"].cast<std::string>());
				co->setGameObject(_mainPool.at(x));

				luabridge::LuaRef componentData = itemPool[j];

				co->awake(componentData);
				_mainPool.at(x)->addComponent(co);
			}
		}

		Logger::getInstance()->log("Archivo de carga de prefab de Lemons correctamente inicializado");
		lua_close(LuaVM);
	}
}
