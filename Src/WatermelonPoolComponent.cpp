#include "WatermelonPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"
#include "PrefabLoader.h"

ADD_COMPONENT(WatermelonPoolComponent);

WatermelonPoolComponent::WatermelonPoolComponent() :EnemyPoolComponent(UserComponentId::WatermelonPoolComponent)
{
}

WatermelonPoolComponent::~WatermelonPoolComponent()
{
}

void WatermelonPoolComponent::awake(luabridge::LuaRef& data)
{
	int maxPoolItems = 0;
	if (LUAFIELDEXIST(MaxPool)) maxPoolItems = GETLUAFIELD(MaxPool, int);

	//POSICIONES DE RESPAWN

	std::string path = "";
	if (LUAFIELDEXIST(Path)) path = GETLUAFIELD(Path, std::string);

	PrefabLoader::getInstance()->loadPoolPrefab(path, maxPoolItems, _mainPool, _inactivePool);
}