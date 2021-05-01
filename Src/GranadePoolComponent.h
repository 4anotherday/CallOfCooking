#pragma once
#ifndef GRANADEPOOLCOMPONENT_H
#define GRANADEPOOLCOMPONENT_H

#include "PoolComponent.h"

class GranadePoolComponent : public PoolComponent
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	GranadePoolComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~GranadePoolComponent();

	virtual void awake(luabridge::LuaRef& data) override;
	virtual void start() override;
	virtual void update() override;

protected:
	/// <summary>
	///	Creates a specified number of inactive game objects and includes them in both groups
	/// </summary>		
	virtual void createGos(int howMany);
};
#endif // !GRANADEPOOLCOMPONENT_H

