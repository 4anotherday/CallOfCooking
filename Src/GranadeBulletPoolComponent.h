#pragma once
#ifndef GRANADEBULLETPOOLCOMPONENT_H
#define GRANADEBULLETPOOLCOMPONENT_H

#include "PoolComponent.h"

class GranadeBulletPoolComponent : public PoolComponent
{
public:
	/// <summary>
	/// Default component constructor
	/// </summary>
	GranadeBulletPoolComponent();

	/// <summary>
	/// Default component constructor
	/// </summary>
	virtual ~GranadeBulletPoolComponent();

	virtual void awake(luabridge::LuaRef& data) override;
};
#endif // !GRANADEBULLETPOOLCOMPONENT_H
