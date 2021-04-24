#include "PlayerMovementComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "KeyboardInput.h"
#include "MouseInput.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "EngineTime.h"
#include <math.h>

PlayerMovementComponent::PlayerMovementComponent():Component(UserComponentId::PlayerMovementComponent),
_tr(nullptr), _rb(nullptr),
_keyUp(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyDown(KeyCode::KEYCODE_S), _speed(10),
_keyboard(KeyBoardInput::getInstance()), _mouseInput(MouseInput::getInstance()), _engineTime(EngineTime::getInstance())
{

}

PlayerMovementComponent::PlayerMovementComponent(GameObject* gameObject) : Component(UserComponentId::PlayerMovementComponent, gameObject),
_tr(nullptr), _rb(nullptr),
_keyUp(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyDown(KeyCode::KEYCODE_S),_speed(10),
_keyboard(KeyBoardInput::getInstance()),_mouseInput(MouseInput::getInstance()),_engineTime(EngineTime::getInstance())
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}

void PlayerMovementComponent::awake(luabridge::LuaRef& data)
{
}

void PlayerMovementComponent::update()
{
	float deltaTime = _engineTime->deltaTime();

	move(deltaTime);
	rotate(deltaTime);
}

void PlayerMovementComponent::move(const float deltaTime)
{
	Vector3 velocity = _tr->getForward(); velocity.normalize();
	Vector3 right = { velocity.getZ(), 0, -velocity.getX() };

	//Front and back movement
	if (_keyboard->isKeyDown(_keyUp)) 
	{
		//Move player forward
		velocity = velocity * _speed;
	}
	else if (_keyboard->isKeyDown(_keyDown)) 
	{
		//Move player backwards
		velocity = velocity * (-1.0 * _speed);
	}

	//Sideways movement
	if (_keyboard->isKeyDown(_keyLeft)) 
	{
		//Move player to the left
		velocity = velocity + (right * _speed * -1.0);
	}
	else if (_keyboard->isKeyDown(_keyRight)) 
	{
		//Move player to the right
		velocity = velocity + (right * _speed);
	}

	velocity = velocity * deltaTime;

	_rb->addForce(velocity);
}

void PlayerMovementComponent::rotate(const float deltaTime)
{
	float mousePosX = _mouseInput->getMousePos().at(0) - _tr->getPosition().getX();
	float mousePosY = _mouseInput->getMousePos().at(1) - _tr->getPosition().getY();

	float angle = atan2(mousePosX, mousePosY) * 3.141592653589793 / 180.0;

	_rb->setRotation(Vector3(0,0,angle) *_speed * deltaTime);
}
