#include "PlayerBulletPoolComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "Engine.h"
#include "includeLUA.h"

ADD_COMPONENT(PlayerBulletPoolComponent);

PlayerBulletPoolComponent::PlayerBulletPoolComponent() :PoolComponent(UserComponentId::PlayerBulletPoolComponent)
{
}

PlayerBulletPoolComponent::~PlayerBulletPoolComponent()
{
}

void PlayerBulletPoolComponent::awake(luabridge::LuaRef& data)
{
	int maxPoolItems = 0;
	if (LUAFIELDEXIST(MaxPool)) maxPoolItems = GETLUAFIELD(MaxPool, int);
	//POSICIONES DE RESPAWN

	std::string path = "";
	if (LUAFIELDEXIST(Path)) path = GETLUAFIELD(Path, std::string);

	loadPrefab(path, maxPoolItems);
}