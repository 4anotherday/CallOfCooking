#include "PlayerShootComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "MouseInput.h"
#include "EngineTime.h"
#include "Engine.h"
#include "includeLUA.h"
#include "Transform.h"
#include "RenderObjectComponent.h"
#include "RigidBodyComponent.h"
#include "PlayerBulletPoolComponent.h"
#include "PlayerBulletBehaviorComponent.h"
#include "includeLUA.h"

ADD_COMPONENT(PlayerShootComponent);

PlayerShootComponent::PlayerShootComponent() : Component(UserComponentId::PlayerShootComponent),
_tr(nullptr), _rb(nullptr), _damage(5),
_mouse(MouseInput::getInstance()), _engineTime(EngineTime::getInstance()), _timeToShoot(_engineTime->deltaTime()), _cadence(0.5)
{
}

PlayerShootComponent::~PlayerShootComponent()
{
}

void PlayerShootComponent::awake(luabridge::LuaRef& data)
{
	_damage = data["Damage"].cast<float>();
	_cadence = data["Cadence"].cast<float>();
}

void PlayerShootComponent::start()
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_gameManager = Engine::getInstance()->findGameObject("GameManager");
	//_bulletsManager = static_cast<PlayerBulletPoolComponent*>(_gameManager->getComponent(UserComponentId::PlayerBulletsManagerComponent));
}

void PlayerShootComponent::update()
{
	float currentDeltaTime = _engineTime->deltaTime();
	_timeToShoot -= currentDeltaTime;
	if (_timeToShoot <= 0 && _mouse->isMouseButtonJustDown(MouseButton::RIGHT))
	{
		_timeToShoot = _cadence;
		shoot();
	}
}

void PlayerShootComponent::onTrigger(GameObject* other)
{
}

void PlayerShootComponent::shoot()
{
	//Me quedo con la direcci�n a la que dispara el player
	Vector3 direction = _tr->getForward();
	Vector3 position = _tr->getPosition() + direction.normalize() * 5; //Me coloco un poco m�s alante que el player

	//Instanciar la bala
	//GameObject* bala = _bulletsManager->getInactiveGO();
	GameObject* nuevaBala = Engine::getInstance()->findGameObject("BalaJugador");
	PlayerBulletBehaviorComponent* c = static_cast<PlayerBulletBehaviorComponent*>(nuevaBala->getComponent(UserComponentId::PlayerBulletBehaviorComponent));

	float mousePosX = MouseInput::getInstance()->getMousePos()[0];
	float mousePosY = MouseInput::getInstance()->getMousePos()[1];
	MouseInput::getInstance()->getMousePos();

	std::cout << "Mouse X =" << mousePosX << "Mouse Y =" << mousePosY << std::endl;
	Vector3 dir = Vector3(mousePosX, 0, mousePosY);

	Vector3 myPos = _tr->getPosition();
	Vector3 bulletPos = myPos + (dir * 40);
	c->beShot(bulletPos, dir);
	//BulletBehaviour
}

void PlayerShootComponent::getDirectionOfShot()
{
	float mousePosX = MouseInput::getInstance()->getMousePos()[0];
	float mousePosY = MouseInput::getInstance()->getMousePos()[1];
}