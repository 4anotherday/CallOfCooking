#pragma once
#ifndef WATERMELONPOOLCOMPONENT_H
#define WATERMELONPOOLCOMPONENT_H

#include "EnemyPoolComponent.h"

class WatermelonPoolComponent : public EnemyPoolComponent
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	WatermelonPoolComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~WatermelonPoolComponent();

	virtual void awake(luabridge::LuaRef& data) override;
	virtual void start() override;
	virtual void update() override;
};
#endif // !WATERMELONPOOLCOMPONENT_H
