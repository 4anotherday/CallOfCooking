#include "GranadePoolComponent.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "PrefabLoader.h"
#include "Exceptions.h"


ADD_COMPONENT(GranadePoolComponent);

GranadePoolComponent::GranadePoolComponent() : EnemyPoolComponent(UserComponentId::GranadePoolComponent)
{
}

GranadePoolComponent::~GranadePoolComponent()
{
}

void GranadePoolComponent::awake(luabridge::LuaRef& data)
{
	int maxPoolItems = 0;
	if (LUAFIELDEXIST(MaxPool)) maxPoolItems = GETLUAFIELD(MaxPool, int);

	std::string path = "";
	if (LUAFIELDEXIST(Path)) path = GETLUAFIELD(Path, std::string);
	try {
		PrefabLoader::getInstance()->loadPoolPrefab(path, maxPoolItems, _mainPool, _inactivePool);
	}
	catch (...) {
		throw ExcepcionTAD("Error while loading prefab in GranadePoolComponent");
	}
}