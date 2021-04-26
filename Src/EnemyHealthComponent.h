#pragma once
#ifndef ENEMYHEALTHCOMPONENT_H
#define ENEMYHEALTHCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"

class ScoreManagerComponent;

class EnemyHealthComponent : public Component	
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	EnemyHealthComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~EnemyHealthComponent();

	/// <summary>
	/// Awake class, initializes the local variables 
	/// </summary>
	/// <param name="data">Luaref with the data</param>
	virtual void awake(luabridge::LuaRef& data) override;

	/// <summary>
	/// Initialise the score manager
	/// </summary>
	virtual void start() override;

	/// <summary>
	/// Reduce hit points
	/// </summary>
	/// <param name="damage">Damage points</param>
	void reduceHitPoints(int damage);
private:
	ScoreManagerComponent* _scoreManager;
	int _points;
	int _hitPoints;
	
};
#endif // !ENEMYHEALTHCOMPONENT_H
