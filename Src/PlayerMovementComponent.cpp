#include "PlayerMovementComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "KeyboardInput.h"
#include "Transform.h"
#include "RigidBodyComponent.h"

PlayerMovementComponent::PlayerMovementComponent():Component(UserComponentId::PlayerMovementComponent),
_tr(nullptr), _rb(nullptr),
_keyUp(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyDown(KeyCode::KEYCODE_S), _speed(5)
{
}

PlayerMovementComponent::PlayerMovementComponent(GameObject* gameObject) : Component(UserComponentId::PlayerMovementComponent, gameObject),
_tr(nullptr), _rb(nullptr),
_keyUp(KeyCode::KEYCODE_W), _keyLeft(KeyCode::KEYCODE_A), _keyRight(KeyCode::KEYCODE_D), _keyDown(KeyCode::KEYCODE_S),_speed(5)
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}

void PlayerMovementComponent::update()
{
	KeyBoardInput* keyBoard = KeyBoardInput::getInstance();
	//Front and back movement
	if (keyBoard->isKeyDown(_keyUp)) {
		//Move player forward
	}
	else if (keyBoard->isKeyDown(_keyDown)) {
		//Move player backwards
	}

	//Sideways movement
	if (keyBoard->isKeyDown(_keyLeft)) {
		//Move player to the left
	}
	else if (keyBoard->isKeyDown(_keyRight)) {
		//Move player to the right
	}
}
