#pragma once
#ifndef GRENADEBULLETBEHAVIORCOMPONENT_H
#define GRENADEBULLETBEHAVIORCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"
#include "Vector3.h"

class Transform;
class RigidBodyComponent;

class GrenadeBulletBehaviorComponent : public Component
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	GrenadeBulletBehaviorComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~GrenadeBulletBehaviorComponent();

	/// <summary>
	/// Awake class, initializes the local variables
	/// </summary>
	/// <param name="data">Luaref with the data</param>
	virtual void awake(luabridge::LuaRef& data) override;

	/// <summary>
	/// Initialise the rigidbody and transform
	/// </summary>
	virtual void start() override;

	/// <summary>
	/// Checks the state and calls the corresponding method
	/// </summary>
	virtual void update() override;

	virtual void onCollision(GameObject* other);

protected:

	RigidBodyComponent* _rigidbody;
	Transform* _playerPos;

	float _movementSpeed;
	Vector3 _direction;
	float damage;

private:
};
#endif // !GRENADEBULLETBEHAVIORCOMPONENT_H
