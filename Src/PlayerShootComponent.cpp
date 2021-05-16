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
	//_mouse->setMouseRelativeMode(true);
}

PlayerShootComponent::~PlayerShootComponent()
{
	if (shotDirection != nullptr)delete shotDirection;
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
	_bulletsManager = static_cast<PlayerBulletPoolComponent*>(_gameObject->getComponent(UserComponentId::PlayerBulletPoolComponent));
	_offsetX = 40;
	_offsetZ = 40;
	shotDirection = new Vector3(0, 0, 1);
	std::pair<int, int> size = Engine::getInstance()->getWindowSize();
	_windowSizeX = size.first;
	_windowSizeY = size.second;
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
	//Instanciar la bala
	GameObject* newBullet = _bulletsManager->getInactiveGO();
	if (newBullet != nullptr) {
		PlayerBulletBehaviorComponent* c = static_cast<PlayerBulletBehaviorComponent*>(newBullet->getComponent(UserComponentId::PlayerBulletBehaviorComponent));

		//Get the mouse position in window sizes, considering the origin the windows center
		float mousePosX = MouseInput::getInstance()->getMousePos()[0];
		mousePosX = mousePosX * _windowSizeX;
		mousePosX = mousePosX - (_windowSizeX / 2);
		float mousePosY = MouseInput::getInstance()->getMousePos()[1];
		mousePosY = mousePosY * _windowSizeY;
		mousePosY = mousePosY - (_windowSizeY / 2);

		//Prepare the info for the bullet
		Vector3 dir = Vector3(mousePosX, 0, mousePosY);
		dir = dir.normalize();
		Vector3 myPos = _tr->getPosition();
		Vector3 bulletPos = myPos + (dir*0.25f);

		//Shot
		c->beShot(bulletPos, dir);
	}
}

void PlayerShootComponent::getDirectionOfShot()
{
	float mousePosX = MouseInput::getInstance()->getMousePos()[0];
	float mousePosY = MouseInput::getInstance()->getMousePos()[1];
}