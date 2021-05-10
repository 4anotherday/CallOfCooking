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
};
#endif // !LEMONPOOLCOMPONENT_H