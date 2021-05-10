#pragma once
#ifndef GRANADEPOOLCOMPONENT_H
#define GRANADEPOOLCOMPONENT_H

#include "EnemyPoolComponent.h"

class GranadePoolComponent : public EnemyPoolComponent
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
};
#endif // !GRANADEPOOLCOMPONENT_H
