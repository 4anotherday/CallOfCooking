#pragma once
#ifndef WATERMELONBEHAVIORCOMPONENT_H
#define WATERMELONBEHAVIORCOMPONENT_H

#include "EnemyBehaviorComponent.h"

class ParticleSystemComponent;
class Transform;
class PlayerHealthComponent;

class GrenadeBehaviorComponent : public EnemyBehaviorComponent
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	GrenadeBehaviorComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~GrenadeBehaviorComponent();

	/// <summary>
	/// Awake class, initializes the local variables
	/// </summary>
	/// <param name="data">Luaref with the data</param>
	virtual void awake(luabridge::LuaRef& data);

	/// <summary>
	///
	/// </summary>
	virtual void start();

	/// <summary>
	/// Checks the distance between the player and the enemy to change the state
	/// </summary>
	virtual void update();

	/// <summary>
	/// Disables the particle effect if lemon is walking
	/// </summary>
	virtual void walk();
	/// <summary>
	/// Deals damage to player
	/// </summary>
	virtual void attack() override;
private:
	Transform* _tr;
	PlayerHealthComponent* _healthPlayer;
	float _timeToShoot;
};
#endif // !WATERMELONBEHAVIORCOMPONENT_H
