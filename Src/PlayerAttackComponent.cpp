#include "PlayerAttackComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "KeyboardInput.h"
#include "Transform.h"
#include "RigidBodyComponent.h"

PlayerAttackComponent::PlayerAttackComponent():Component(UserComponentId::PlayerAttackComponent),
_tr(nullptr), _rb(nullptr),_attackKey(KeyCode::KEYCODE_P),_damage(5)
{
}

PlayerAttackComponent::PlayerAttackComponent(GameObject* gameObject) : Component(UserComponentId::PlayerAttackComponent, gameObject),
_tr(nullptr), _rb(nullptr), _attackKey(KeyCode::KEYCODE_P), _damage(5)
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}

void PlayerAttackComponent::update()
{
	KeyBoardInput* keyBoard = KeyBoardInput::getInstance();
	
	if (keyBoard->isKeyDown(_attackKey)) 
	{
		//Here we should attack
	}
	
}
