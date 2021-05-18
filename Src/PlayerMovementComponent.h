#pragma once
#ifndef PLAYERMOVEMENTCOMPONENT_H
#define PLAYERMOVEMENTCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"
#include "Vector3.h"

class GameObject;
class RigidBodyComponent;
class Transform;
class EngineTime;
class KeyBoardInput;
class MouseInput;

class PlayerMovementComponent : public Component
{
public:

	PlayerMovementComponent();
	PlayerMovementComponent(GameObject* gameObject);
	virtual ~PlayerMovementComponent();

	/// <summary>
	/// Awake class, initializes the local variables
	/// </summary>
	/// <param name="data">Luaref with the data</param>
	virtual void awake(luabridge::LuaRef& data) override;

	/// <summary>
	/// Initialise the rigidbody and transform and store the window size
	/// </summary>
	virtual void start() override;

	/// <summary>
	/// Calculates the velocity of the player and rotates the player
	/// </summary>
	virtual void update() override;

	/// <summary>
	/// Apply a velocity to the player
	/// </summary>
	virtual void fixedUpdate() override;

	/// <summary>
	/// Increases the current speed of the player
	/// </summary>
	/// <param name="extraSpeed">Amount of speed</param>
	void increaseSpeed(float extraSpeed);

	void resetPosition();

	inline void gameOver(bool b) { _gameOver = b; };

private:

	Transform* _tr;
	RigidBodyComponent* _rb;
	KeyBoardInput* _keyboard;
	MouseInput* _mouseInput;
	EngineTime* _engineTime;

	KeyCode _keyUp, _keyLeft, _keyRight, _keyDown;
	Vector3 _velocity;
	float _speed, _rotationSpeed;
	int _windowSizeX, _windowSizeY;
	bool _gameOver;
};
#endif // !PLAYERMOVEMENTCOMPONENT_H
