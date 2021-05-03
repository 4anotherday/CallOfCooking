#pragma once
#ifndef WATERMELONPOOLCOMPONENT_H
#define WATERMELONPOOLCOMPONENT_H

#include "PoolComponent.h"

class WatermelonPoolComponent : public PoolComponent	
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

	/// <summary>
	/// Awaken a group of inactive enemies
	/// </summary>
	virtual void wakeUpInactiveGroup(int howMany);
protected:
	/// <summary>
	///	Creates a specified number of inactive game objects and includes them in both groups
	/// </summary>		
	virtual void createGos(int howMany);
};
#endif // !WATERMELONPOOLCOMPONENT_H
