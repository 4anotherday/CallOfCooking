#pragma once
#ifndef PLAYERATTACKCOMPONENT_H
#define PLAYERATTACKCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"

class GameObject;
class RigidBodyComponent;
class Transform;
class EngineTime;
class MouseInput;
class EnemyHealthComponent;
class GranadePoolComponent;
class LemonPoolComponent;
class WatermelonPoolComponent;

class PlayerAttackComponent : public Component
{
public:

	/// <summary>
	/// Default component constructor
	/// </summary>
	PlayerAttackComponent();
	PlayerAttackComponent(GameObject* gameObject);

	/// <summary>
	/// Destructor of the component
	/// </summary>
	virtual ~PlayerAttackComponent();

	virtual void awake(luabridge::LuaRef& data) override;
	virtual void start() override;
	virtual void update() override;
	virtual void onTrigger(GameObject* other) override;

	void increaseAttackRate(float extraAttackRate);

private:

	/// <summary>
	/// Rotates the hitbox of the players attack so that it matches the direction he is aiming
	/// </summary>
	void rotateAttackHitBox();

	/// <summary>
	/// Determines which enemies are in range and if the mouse specified INPUT is pressed
	/// the attackRate is checked to see if the attack must be done
	/// </summary>
	void attack(float deltaTime);

	/// <summary>
	/// Puts enemies outside the player's range
	/// </summary>
	void EnemiesNotInPlayerRange();

	/// <summary>
	/// Damages the enemies which are in player range
	/// </summary>
	void AttackEnemies();

	Transform* _trPlayer;
	Transform* _tr;
	RigidBodyComponent* _rb;
	EngineTime* _engineTime;
	MouseInput* _mouse;
	LemonPoolComponent* _lemonPool;
	GranadePoolComponent* _grenadePool;
	WatermelonPoolComponent* _watermelonPool;

	float _damage, _lastAttack, _attackRate, _attackHitBoxDistance,_playerRange;
	int _windowSizeX, _windowSizeY;
};
#endif // !PLAYERATTACKCOMPONENT_H
