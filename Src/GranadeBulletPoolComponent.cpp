#include "GranadeBulletPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "PrefabLoader.h"
#include "Exceptions.h"

ADD_COMPONENT(GranadeBulletPoolComponent);

GranadeBulletPoolComponent::GranadeBulletPoolComponent() :PoolComponent(UserComponentId::GranadeBulletPoolComponent)
{
}

GranadeBulletPoolComponent::~GranadeBulletPoolComponent()
{
}

void GranadeBulletPoolComponent::awake(luabridge::LuaRef& data)
{
	int maxPoolItems = 0;
	if (LUAFIELDEXIST(MaxPool)) maxPoolItems = GETLUAFIELD(MaxPool, int);

	std::string path = "";
	if (LUAFIELDEXIST(Path)) path = GETLUAFIELD(Path, std::string);

	try {
		PrefabLoader::getInstance()->loadPoolPrefab(path, maxPoolItems, _mainPool, _inactivePool);
	}
	catch (...) {
		throw ExcepcionTAD("Error while loading prefab in GranadeBulletPoolComponent");
	}
}