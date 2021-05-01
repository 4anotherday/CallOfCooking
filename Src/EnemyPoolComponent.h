#pragma once
#ifndef ENEMYPOOLCOMPONENT_H
#define ENEMYPOOLCOMPONENT_H

#include "PoolComponent.h"

class EnemyPoolComponent : public PoolComponent	
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	EnemyPoolComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~EnemyPoolComponent();

	virtual void awake(luabridge::LuaRef& data) override;
	virtual void start() override;
	virtual void update() override;

protected:
	/// <summary>
	///	Creates a specified number of inactive game objects and includes them in both groups
	/// </summary>		
	virtual void createGos(int howMany);
};
#endif // !ENEMYPOOLCOMPONENT_H
