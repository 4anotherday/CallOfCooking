#include "CameraControllerComponent.h"
#include "CameraComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "KeyboardInput.h"
#include "MouseInput.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "EngineTime.h"
#include "Engine.h"
#include "includeLUA.h"
#include "Exceptions.h"
#include <math.h>

ADD_COMPONENT(CameraControllerComponent);

CameraControllerComponent::CameraControllerComponent() :Component(UserComponentId::PlayerMovementComponent),
_tr(nullptr), _targetTr(nullptr), _engineTime(nullptr), _myCam(nullptr), _offsetX(0.0f), _offsetY(4.0f), _offsetZ(0.0f),_target("Player")
{
}

CameraControllerComponent::CameraControllerComponent(GameObject* gameObject) : Component(UserComponentId::PlayerMovementComponent, gameObject),
_tr(nullptr), _targetTr(nullptr), _engineTime(nullptr),_myCam(nullptr) , _offsetX(0.0f), _offsetY(4.0f), _offsetZ(0.0f), _target("Player")
{
}

CameraControllerComponent::~CameraControllerComponent()
{
}

void CameraControllerComponent::awake(luabridge::LuaRef& data)
{
	if(LUAFIELDEXIST(Target)) _target = GETLUASTRINGFIELD(Target);
	if(LUAFIELDEXIST(Offset))
	{
		if(!data["Offset"]["X"].isNil()) _offsetX = data["Offset"]["X"].cast<float>();
		if(!data["Offset"]["Y"].isNil()) _offsetY = data["Offset"]["Y"].cast<float>();
		if(!data["Offset"]["Z"].isNil()) _offsetZ = data["Offset"]["Z"].cast<float>();
	}	
}

void CameraControllerComponent::start()
{
	_targetTr = static_cast<Transform*>(Engine::getInstance()->findGameObject(_target)->getComponent(ComponentId::Transform));
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_myCam = static_cast<CameraComponent*>(_gameObject->getComponent(ComponentId::Camera));
}

void CameraControllerComponent::postFixedUpdate()
{
	Vector3 finalPos = _targetTr->getPosition();
	finalPos = finalPos + Vector3(_offsetX, _offsetY, _offsetZ);
	_tr->setPosition(finalPos);
}