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
}

void GranadeBulletPoolComponent::start()
{
}

void GranadeBulletPoolComponent::update()
{
}