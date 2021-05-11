#pragma once
#ifndef CAMERACONTROLLERCOMPONENT_H
#define CAMERACONTROLLERCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"
#include "Vector3.h"
#include <string>

class GameObject;
class RigidBodyComponent;
class Transform;
class EngineTime;
class KeyBoardInput;
class MouseInput;
class CameraComponent;

class CameraControllerComponent : public Component
{
public:

	CameraControllerComponent();
	CameraControllerComponent(GameObject* gameObject);
	virtual ~CameraControllerComponent();

	virtual void awake(luabridge::LuaRef& data) override;
	virtual void start() override;
	virtual void postFixedUpdate() override;

private:

	Transform* _tr;
	Transform* _targetTr;
	CameraComponent* _myCam;

	std::string _target;
	float _offsetX;
	float _offsetY;
	float _offsetZ;

	EngineTime* _engineTime;
};
#endif // !CAMERACONTROLLERCOMPONENT_H
