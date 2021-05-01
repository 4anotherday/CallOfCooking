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
	virtual void start() override;
	virtual void update() override;

private:
	/// <summary>
	///	Creates a specified number of inactive game objects and includes them in both groups
	/// </summary>		
	virtual void createGos(int howMany);

};
#endif // !GRANADEBULLETPOOLCOMPONENT_H
