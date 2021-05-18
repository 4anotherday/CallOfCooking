#pragma once
#ifndef WATERMELONBEHAVIORCOMPONENT_H
#define WATERMELONBEHAVIORCOMPONENT_H

#include "EnemyBehaviorComponent.h"

class ParticleSystemComponent;
class Transform;
class PlayerHealthComponent;
class EnemyHealthComponent;

class WatermelonBehaviorComponent : public EnemyBehaviorComponent
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	WatermelonBehaviorComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~WatermelonBehaviorComponent();

	/// <summary>
	/// Awake class, initializes the local variables
	/// </summary>
	/// <param name="data">Luaref with the data</param>
	virtual void awake(luabridge::LuaRef& data);

	/// <summary>
	/// Initialise the particle system,transform and player health
	/// </summary>
	virtual void start() override;

	/// <summary>
	/// Checks the distance between the player and the enemy to change the state
	/// </summary>
	virtual void update();

	/// <summary>
	/// Disables the particle effect if lemon is walking
	/// </summary>
	virtual void walk() override;

private:
	void resetBehavior();

	ParticleSystemComponent* _pSystem;
	Transform* _tr;
	PlayerHealthComponent* _healthPlayer;
	EnemyHealthComponent* _myHealth;

	float _timeToExplode;
	bool _exploding;
	float _explosionCountDown;
};
#endif // !WATERMELONBEHAVIORCOMPONENT_H
