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
class PlayerBulletPoolComponent;

class PlayerShootComponent : public Component
{
public:

	/// <summary>
	/// Default component constructor
	/// </summary>
	PlayerShootComponent();

	/// <summary>
	/// Default component constructor
	/// </summary>
	virtual ~PlayerShootComponent();

	virtual void awake(luabridge::LuaRef& data) override;
	virtual void start() override;
	virtual void update() override;
	virtual void onTrigger(GameObject* other) override;

private:

	/// <summary>
	/// Used to track where the player is aiming and shoot
	/// </summary>
	void shoot();

	void getDirectionOfShot();

	Transform* _tr;
	RigidBodyComponent* _rb;
	EngineTime* _engineTime;
	MouseInput* _mouse;
	GameObject* _gameManager;
	PlayerBulletPoolComponent* _bulletsManager;

	float _damage, _timeToShoot, _cadence;
};
#endif // !PLAYERATTACKCOMPONENT_H
