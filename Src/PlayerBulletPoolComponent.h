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
	virtual void start() override;
	virtual void update() override;

private:
	/// <summary>
	///	Creates a specified number of inactive game objects and includes them in both groups
	/// </summary>		
	virtual void createGos(int howMany);

};
#endif // !PLAYERBULLETPOOLCOMPONENT_H
