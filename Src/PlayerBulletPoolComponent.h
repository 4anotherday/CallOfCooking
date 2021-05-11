#pragma once
#ifndef PLAYERBULLETPOOLCOMPONENT_H
#define PLAYERBULLETPOOLCOMPONENT_H

#include "PoolComponent.h"

class PlayerBulletPoolComponent : public PoolComponent
{
public:
	/// <summary>
	/// Default component constructor
	/// </summary>
	PlayerBulletPoolComponent();

	/// <summary>
	/// Default component constructor
	/// </summary>
	virtual ~PlayerBulletPoolComponent();

	virtual void awake(luabridge::LuaRef& data) override;
};
#endif // !PLAYERBULLETPOOLCOMPONENT_H
