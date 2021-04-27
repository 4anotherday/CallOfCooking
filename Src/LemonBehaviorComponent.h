#pragma once
#ifndef LEMONBEHAVIORCOMPONENT_H
#define LEMONBEHAVIORCOMPONENT_H

#include "EnemyBehaviorComponent.h"

class ParticleSystemComponent;
class Transform;
class PlayerHealthComponent;

class LemonBehaviorComponent : public EnemyBehaviorComponent
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	LemonBehaviorComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~LemonBehaviorComponent();

	/// <summary>
	/// Awake class, initializes the local variables 
	/// </summary>
	/// <param name="data">Luaref with the data</param>
	virtual void awake(luabridge::LuaRef& data);

	/// <summary>
	/// Initialise the particle system,transform and player health
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
	ParticleSystemComponent* _pSystem;
	Transform* _tr;
	PlayerHealthComponent* _healthPlayer;

	float _range;
};
#endif // !LEMONBEHAVIORCOMPONENT_H
