#pragma once
#ifndef PLAYERBULLETBEHAVIORCOMPONENT_H
#define PLAYERBULLETBEHAVIORCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"
#include "Vector3.h"

class Transform;
class RigidBodyComponent;
class PlayerBulletPoolComponent;

class PlayerBulletBehaviorComponent : public Component
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	PlayerBulletBehaviorComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~PlayerBulletBehaviorComponent();

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

	void beShot(Vector3 pos, Vector3 dir);

protected:

	void deactivate();

	RigidBodyComponent* _rigidbody;
	Transform* _tr;
	PlayerBulletPoolComponent* _pool;

	Vector3 _direction;
	float _movementSpeed;
	float _damage;
	float _lifeTime;
	float _timeToDie;

private:
};
#endif // !PLAYERBULLETBEHAVIORCOMPONENT_H
