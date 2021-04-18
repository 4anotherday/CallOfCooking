#pragma once
#ifndef PLAYERATTACKCOMPONENT_H
#define PLAYERATTACKCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"

class GameObject;
class RigidBodyComponent;
class Transform;

class PlayerAttackComponent : public Component	
{
public:

	PlayerAttackComponent();
	PlayerAttackComponent(GameObject* gameObject);

	virtual void update();
	
private:
	Transform* _tr;
	RigidBodyComponent* _rb;

	KeyCode _attackKey;

	float _damage;
};
#endif // !PLAYERATTACKCOMPONENT_H
