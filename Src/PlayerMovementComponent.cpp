#include "PlayerMovementComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "KeyboardInput.h"
#include "MouseInput.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "EngineTime.h"
#include "includeLUA.h"
#include <math.h>
#include "includeLUA.h"


ADD_COMPONENT(PlayerMovementComponent);

PlayerMovementComponent::PlayerMovementComponent() :Component(UserComponentId::PlayerMovementComponent),
_tr(nullptr), _rb(nullptr),_velocity(),
_keyUp(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyDown(KeyCode::KEYCODE_S), _speed(10), _rotationSpeed(8),
_keyboard(KeyBoardInput::getInstance()), _mouseInput(MouseInput::getInstance()), _engineTime(EngineTime::getInstance())
{	
}

PlayerMovementComponent::PlayerMovementComponent(GameObject* gameObject) : Component(UserComponentId::PlayerMovementComponent, gameObject),
_tr(nullptr), _rb(nullptr), _velocity(),
_keyUp(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyDown(KeyCode::KEYCODE_S), _speed(10), _rotationSpeed(8),
_keyboard(KeyBoardInput::getInstance()), _mouseInput(MouseInput::getInstance()), _engineTime(EngineTime::getInstance())
{
}

PlayerMovementComponent::~PlayerMovementComponent()
{
}

void PlayerMovementComponent::awake(luabridge::LuaRef& data)
{
	_speed = data["Speed"].cast<float>();
	_rotationSpeed = data["RotationSpeed"].cast<float>();
}

void PlayerMovementComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	/*_rb->constrainZ(true, false);
	_rb->constrainX(true, false);
	_rb->constrainY(true, false);*/
}

void PlayerMovementComponent::update()
{
	float deltaTime = _engineTime->deltaTime();

	_velocity = _tr->getForward(); _velocity.normalize();
	Vector3 right(_velocity.getZ(), 0, -_velocity.getX());

	if (_keyboard->isKeyDown(_keyUp))
	{
		_velocity = _velocity * _speed;
	}
	else if (_keyboard->isKeyDown(_keyDown))
	{
		_velocity = _velocity * (-1.0 * _speed);
	}

	if (_keyboard->isKeyDown(_keyRight))
	{
		_velocity = _velocity + (right * _speed * -1);
	}
	else if (_keyboard->isKeyDown(_keyLeft))
	{
		_velocity = _velocity + (right * _speed );
	}

	_velocity = _velocity * deltaTime;
}

void PlayerMovementComponent::fixedUpdate()
{
	_rb->addForce(_velocity);
	float deltaTime = _engineTime->deltaTime();
	rotate(deltaTime);
}

void PlayerMovementComponent::rotate(const float deltaTime)
{
	float mousePosX = _mouseInput->getMousePos().at(0) - _tr->getPosition().getX();
	float mousePosY = _mouseInput->getMousePos().at(1) - _tr->getPosition().getY();

	float angle = atan2(mousePosX, mousePosY) * 3.141592653589793 / 180.0;
	//*_rotationSpeed* deltaTime
	//_rb->setRotation(angle,Vector3(0, 0, 1) );
}