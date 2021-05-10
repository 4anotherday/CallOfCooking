#include "LemonPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"

ADD_COMPONENT(LemonPoolComponent);

LemonPoolComponent::LemonPoolComponent() :EnemyPoolComponent(UserComponentId::LemonPoolComponent)
{

}

LemonPoolComponent::~LemonPoolComponent()
{

}

void LemonPoolComponent::awake(luabridge::LuaRef& data)
{
	int maxPoolItems = 0;
	if (LUAFIELDEXIST(MaxPool)) maxPoolItems =	GETLUAFIELD(MaxPool, int);

	//POSICIONES DE RESPAWN

	std::string path ="";
	if (LUAFIELDEXIST(Path)) path = GETLUAFIELD(Path, std::string);

	//#if (defined _DEBUG)
	//#pragma comment (lib, "liblua.a")
	//#endif
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

		std::string prefabName = "go_0";
		luabridge::LuaRef itemPool = luabridge::getGlobal(LuaVM, prefabName.c_str());

		std::string itemBaseName = itemPool[0]["Name"];

		int cont = 0;
		for (int x = 0; x < maxPoolItems; ++x) {
			GameObject* go = Engine::getInstance()->addGameObject();

			std::string goName = itemBaseName + std::to_string(cont);
			go->setName(goName);
			++cont;

			go->setEnabled(false);
			_mainPool.push_back(go);
			_inactivePool.push_back(go);
		}

		for (int x = 0; x < maxPoolItems; ++x) {
			for (int j = 0; j < itemPool.length(); ++j) {
				Component* co = ComponentsFactory::getInstance()->getComponentByName(itemPool[j]["Component"]);
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

void LemonPoolComponent::createGos(int howMany)
{
	
}