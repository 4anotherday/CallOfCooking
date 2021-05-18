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
#include "Engine.h";

ADD_COMPONENT(PlayerMovementComponent);

PlayerMovementComponent::PlayerMovementComponent() :Component(UserComponentId::PlayerMovementComponent),
_tr(nullptr), _rb(nullptr), _velocity(),
_keyUp(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyDown(KeyCode::KEYCODE_S), _speed(10), _rotationSpeed(8),
_keyboard(KeyBoardInput::getInstance()), _mouseInput(MouseInput::getInstance()), _engineTime(EngineTime::getInstance()),_windowSizeX(),_windowSizeY(), _gameOver(false)
{
}

PlayerMovementComponent::PlayerMovementComponent(GameObject* gameObject) : Component(UserComponentId::PlayerMovementComponent, gameObject),
_tr(nullptr), _rb(nullptr), _velocity(),
_keyUp(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyDown(KeyCode::KEYCODE_S), _speed(10), _rotationSpeed(8),
_keyboard(KeyBoardInput::getInstance()), _mouseInput(MouseInput::getInstance()), _engineTime(EngineTime::getInstance()), _windowSizeX(), _windowSizeY(), _gameOver(false)
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
	std::pair<int, int> size = Engine::getInstance()->getWindowSize();
	_windowSizeX = size.first;
	_windowSizeY = size.second;

	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}

void PlayerMovementComponent::update()
{
	if (_gameOver) return;

	float deltaTime = _engineTime->deltaTime();

	//Here se set the velocity of the player
	_velocity = Vector3(0, 0, -1); _velocity.normalize();
	Vector3 right(_velocity.getZ(), 0, -_velocity.getX());
	right.normalize();

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
		_velocity = _velocity + (right * _speed);
	}

	_velocity = _velocity * deltaTime;


	//Here we set the rotation of the player
	float mousePosX = MouseInput::getInstance()->getMousePos()[0];
	mousePosX = mousePosX * _windowSizeX;
	mousePosX = mousePosX - (_windowSizeX / 2);
	float mousePosY = MouseInput::getInstance()->getMousePos()[1];
	mousePosY = mousePosY * _windowSizeY;
	mousePosY = mousePosY - (_windowSizeY / 2);

	float dirX = mousePosX - _tr->getPosition().getX();
	float dirZ = mousePosY - _tr->getPosition().getZ();

	Vector3 dir = Vector3(dirX, 0.0f,dirZ);

	float angle = -atan2(dir.getZ(),dir.getX()) * 180.0f;
	
	_tr->setRotation(Vector3(0.0f, angle, 0.0f) * 0.005f * _rotationSpeed);
}

void PlayerMovementComponent::fixedUpdate()
{
	_rb->setLinearVelocity(_velocity);
}

void PlayerMovementComponent::increaseSpeed(float extraSpeed)
{
	_speed += extraSpeed;
}