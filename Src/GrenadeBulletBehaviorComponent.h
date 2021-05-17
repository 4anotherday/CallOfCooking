#pragma once
#ifndef GRENADEBULLETBEHAVIORCOMPONENT_H
#define GRENADEBULLETBEHAVIORCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"
#include "Vector3.h"

class Transform;
class RigidBodyComponent;
class GranadeBulletPoolComponent;
class BoxColliderComponent;

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

	virtual void onTrigger(GameObject* other);

	void beShot(Vector3 pos, Vector3 dir);

protected:

	void deactivate();

	RigidBodyComponent* _rigidbody;
	BoxColliderComponent* _myCollider;
	Transform* _tr;
	GranadeBulletPoolComponent* _pool;

	float _movementSpeed;
	Vector3 _direction;
	float _damage;
	float _lifeTime;
	float _timeToDie;

private:
};
#endif // !GRENADEBULLETBEHAVIORCOMPONENT_H
