#include "GranadeBulletPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"

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

	//POSICIONES DE RESPAWN

	std::string path = "";
	if (LUAFIELDEXIST(Path)) path = GETLUAFIELD(Path, std::string);

	loadPrefab(path, maxPoolItems);
}