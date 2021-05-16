#pragma once
#ifndef GRANADEBEHAVIORCOMPONENT_H
#define GRANADEBEHAVIORCOMPONENT_H

#include "EnemyBehaviorComponent.h"

class ParticleSystemComponent;
class Transform;
class PlayerHealthComponent;
class GranadeBulletPoolComponent;

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
	virtual void walk() override;
	/// <summary>
	/// Deals damage to player
	/// </summary>
	virtual void attack() override;
private:
	Transform* _tr;
	PlayerHealthComponent* _healthPlayer;
	GranadeBulletPoolComponent* _bulletsManager;
	GameObject* _gameManager;

	float _timeToShoot;
};
#endif // !GRANADEBEHAVIORCOMPONENT_H
