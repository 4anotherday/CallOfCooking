#pragma once
#ifndef PLAYERMOVEMENTCOMPONENT_H
#define PLAYERMOVEMENTCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"

class GameObject;
class RigidBodyComponent;
class Transform;

class PlayerMovementComponent : public Component	
{
public:

	PlayerMovementComponent();
	PlayerMovementComponent(GameObject* gameObject);

	virtual void update();
	
private:
	Transform* _tr;
	RigidBodyComponent* _rb;

	KeyCode _keyUp, _keyLeft, _keyRight, _keyDown;

	float _speed;
};
#endif // !PLAYERMOVEMENTCOMPONENT_H
