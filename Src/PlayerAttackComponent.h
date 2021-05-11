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

	Transform* _tr;
	RigidBodyComponent* _rb;
	EngineTime* _engineTime;
	MouseInput* _mouse;
	const GameObject* _parent;

	float _damage, _lastAttack, _attackRate, _attackHitBoxDistance;
};
#endif // !PLAYERATTACKCOMPONENT_H
