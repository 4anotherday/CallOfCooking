#pragma once
#ifndef ENEMYBEHAVIORCOMPONENT_H
#define ENEMYBEHAVIORCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"
#include "UserComponentIDs.h"

class Transform;
class RigidBodyComponent;

class EnemyBehaviorComponent : public Component
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	EnemyBehaviorComponent(UserComponentId::UserComponentId id);

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~EnemyBehaviorComponent();

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
	virtual void update() {}
protected:
	/// <summary>
	/// The enemy walks towards the player
	/// </summary>
	virtual void walk() {}

	/// <summary>
	/// The enemy attacks the player if it is close enough
	/// </summary>
	virtual void attack() {}

	RigidBodyComponent* _rigidbody;
	Transform* _playerPos;

	float _attackSpeed;
	float _damagePerSecond;
	bool _isAttacking;
	float _range;
	float _movementSpeed;
};
#endif // !ENEMYBEHAVIORCOMPONENT_H
