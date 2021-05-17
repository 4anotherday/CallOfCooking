#include "PrefabLoader.h"
#include "Logger.h"
#include "GameObject.h"
#include "Engine.h"
#include "Component.h"

std::unique_ptr<PrefabLoader> PrefabLoader::instance = nullptr;

GameObject* PrefabLoader::loadPrefab(std::string path, int howMany)
{
	_filePath = path;
	GameObject* go = Engine::getInstance()->addGameObject();

	if (loadPrefabFile()) {
		std::string prefabLua = "prefab";
		luabridge::LuaRef dataRef = luabridge::getGlobal(_LuaVM, prefabLua.c_str());

		std::string goName = dataRef[0]["Name"];

		go->setName(goName);

		for (int x = 1; x <= dataRef.length(); ++x) {
			Component* co = ComponentsFactory::getInstance()->getComponentByName(dataRef[x]["Component"].cast<std::string>());
			co->setGameObject(go);

			luabridge::LuaRef componentData = dataRef[x];

			go->addComponent(co);
			co->awake(componentData);
		}
	}
	return go;
}

void PrefabLoader::loadPoolPrefab(std::string path, int howMany, std::vector<GameObject*>& mainPool, std::vector<GameObject*>& inactivePool)
{
	_filePath = path;

	if (loadPrefabFile()) {
		std::string prefabLua = "prefab";
		luabridge::LuaRef itemPool = luabridge::getGlobal(_LuaVM, prefabLua.c_str());

		std::string itemBaseName = itemPool[0]["Name"];

		int cont = 0;
		for (int x = 0; x < howMany; ++x) {
			GameObject* go = Engine::getInstance()->addGameObject();

			std::string goName = itemBaseName + std::to_string(cont);
			go->setName(goName);
			++cont;

			go->setEnabled(false);
			mainPool.push_back(go);
			inactivePool.push_back(go);
		}

		for (int x = 0; x < howMany; ++x) {
			for (int j = 1; j <= itemPool.length(); ++j) {
				Component* co = ComponentsFactory::getInstance()->getComponentByName(itemPool[j]["Component"].cast<std::string>());
				co->setGameObject(mainPool.at(x));

				luabridge::LuaRef componentData = itemPool[j];

				co->awake(componentData);
				mainPool.at(x)->addComponent(co);
				//co->setEnabled(false);
			}
		}
	}
}

luabridge::LuaRef PrefabLoader::getDataPrefab(std::string path)
{
	_filePath = path;

	if (loadPrefabFile()) {
		std::string prefabLua = "prefab";
		luabridge::LuaRef dataRef = luabridge::getGlobal(_LuaVM, prefabLua.c_str());

		return dataRef;
	}
}

bool PrefabLoader::loadPrefabFile()
{
	int r = luaL_dofile(_LuaVM, _filePath.c_str());

	if (r != LUA_OK) {
		std::cout << lua_tostring(_LuaVM, -1) << std::endl;
		//Excepción formal y salir de este método
		Logger::getInstance()->log("Archivo de carga de escena de lua no encontrado", Logger::Level::FATAL);
		return false;
	}
	else {
		luabridge::getGlobalNamespace(_LuaVM);

		Logger::getInstance()->log("Fichero de prefab en ruta " + _filePath + " correctamente inicializado");
		return true;
	}
}

PrefabLoader::PrefabLoader() {
	_LuaVM = luaL_newstate();
	luaL_openlibs(_LuaVM);
}

PrefabLoader::~PrefabLoader()
{
	lua_close(_LuaVM);
}

PrefabLoader* PrefabLoader::getInstance()
{
	return instance.get();
}

void PrefabLoader::CreateInstance()
{
	if (instance.get() == nullptr) {
		instance.reset(new PrefabLoader());
	}
	else {
		Logger::getInstance()->log("Trying to create PrefafLoader instance and it already exist", Logger::Level::WARN);
	}
}