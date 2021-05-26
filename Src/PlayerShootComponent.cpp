#include "PlayerShootComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "MouseInput.h"
#include "EngineTime.h"
#include "Exceptions.h"
#include "Engine.h"

#include "includeLUA.h"
#include "Transform.h"
#include "RenderObjectComponent.h"
#include "RigidBodyComponent.h"
#include "PlayerBulletPoolComponent.h"
#include "PlayerBulletBehaviorComponent.h"
#include "AudioSourceComponent.h"

ADD_COMPONENT(PlayerShootComponent);

PlayerShootComponent::PlayerShootComponent() : Component(UserComponentId::PlayerShootComponent),
_tr(nullptr), 
_rb(nullptr), 
_mouse(MouseInput::getInstance()), 
_engineTime(EngineTime::getInstance()),
_gameManager(nullptr),
_bulletsManager(nullptr),
_shotDirection(),
_audio(nullptr),
_windowSizeX(), _windowSizeY(),
_offsetX(), _offsetZ(),
_cadence(0.5), _damage(5),
_timeToShoot(_engineTime->deltaTime())
{
	//_mouse->setMouseRelativeMode(true);
}

PlayerShootComponent::~PlayerShootComponent()
{
	if (_shotDirection != nullptr)delete _shotDirection;
}

void PlayerShootComponent::awake(luabridge::LuaRef& data)
{
	if(LUAFIELDEXIST(Damage)) _damage = data["Damage"].cast<float>();
	if (LUAFIELDEXIST(Cadence)) _cadence = data["Cadence"].cast<float>();
}

void PlayerShootComponent::start()
{

	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
	_audio = GETCOMPONENT(AudioSourceComponent, ComponentId::AudioSource);
	_gameManager = Engine::getInstance()->findGameObject("GameManager");
	_bulletsManager = static_cast<PlayerBulletPoolComponent*>(_gameObject->getComponent(UserComponentId::PlayerBulletPoolComponent));

	_offsetX = 40;
	_offsetZ = 40;
	_shotDirection = new Vector3(0, 0, 1);
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

void PlayerShootComponent::increaseAttackSpeed()
{
	if(_cadence > 0)
		_cadence -= 0.01;
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
		Vector3 bulletPos = myPos + (dir * 0.25f);

		//Shot
		c->beShot(bulletPos, dir);
		_audio->playAudio(1);
	}
}

void PlayerShootComponent::getDirectionOfShot()
{
	float mousePosX = MouseInput::getInstance()->getMousePos()[0];
	float mousePosY = MouseInput::getInstance()->getMousePos()[1];
}