#pragma once
#ifndef LEMONPOOLCOMPONENT_H
#define LEMONPOOLCOMPONENT_H

#include "EnemyPoolComponent.h"

class LemonPoolComponent : public EnemyPoolComponent	
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	LemonPoolComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~LemonPoolComponent();

	virtual void awake(luabridge::LuaRef& data) override;

protected:
	/// <summary>
	///	Creates a specified number of inactive game objects and includes them in both groups
	/// </summary>		
	virtual void createGos(int howMany);
};
#endif // !LEMONPOOLCOMPONENT_H