#pragma once
#ifndef PLAYERMOVEMENTCOMPONENT_H
#define PLAYERMOVEMENTCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"

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

	virtual void awake(luabridge::LuaRef& data) override;
	virtual void update() override;

private:

	/// <summary>
	/// Moves the player
	/// </summary>
	/// <param name="deltaTime">The current delta time</param>
	void move(const float deltaTime);

	/// <summary>
	/// Rotates the player
	/// </summary>
	/// <param name="deltaTime">The current delta time</param>
	void rotate(const float deltaTime);

	Transform* _tr;
	RigidBodyComponent* _rb;
	KeyBoardInput* _keyboard;
	MouseInput* _mouseInput;
	EngineTime* _engineTime;

	KeyCode _keyUp, _keyLeft, _keyRight, _keyDown;

	float _speed, _rotationSpeed;
};
#endif // !PLAYERMOVEMENTCOMPONENT_H
