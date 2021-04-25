#pragma once
#ifndef PLAYERATTACKCOMPONENT_H
#define PLAYERATTACKCOMPONENT_H

#include "Component.h"
#include "KeyCodes.h"

class GameObject;
class RigidBodyComponent;
class Transform;
class EngineTime;
class MouseInput;

class PlayerAttackComponent : public Component	
{
public:

	PlayerAttackComponent();
	PlayerAttackComponent(GameObject* gameObject);
	virtual ~PlayerAttackComponent();

	virtual void awake(luabridge::LuaRef& data) override;
	virtual void start() override;
	virtual void update() override;
	
private:

	void rotateAttackHitBox();
	void attack(float deltaTime);

	Transform* _tr;
	RigidBodyComponent* _rb;
	EngineTime* _engineTime;
	MouseInput* _mouse;
	//Gameobject child which contains a collider(hitbox)
	GameObject* hitbox;

	KeyCode _attackKey;

	float _damage,_lastAttack,_attackRate, _attackHitBoxDistance;
};
#endif // !PLAYERATTACKCOMPONENT_H
