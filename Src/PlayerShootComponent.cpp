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
#include "includeLUA.h"

ADD_COMPONENT(PlayerShootComponent);

PlayerShootComponent::PlayerShootComponent() : Component(UserComponentId::PlayerShootComponent),
_tr(nullptr), _rb(nullptr), _damage(5),
_mouse(MouseInput::getInstance()), _engineTime(EngineTime::getInstance()), _shotRate(0.5), _lastShot(_engineTime->deltaTime())
{
	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));
}

PlayerShootComponent::~PlayerShootComponent()
{
}

void PlayerShootComponent::awake(luabridge::LuaRef& data)
{
	_damage = data["Damage"].cast<float>();
	_shotRate = data["Damage"].cast<float>();
}

void PlayerShootComponent::start()
{
}

void PlayerShootComponent::update()
{
	float currentDeltaTime = _engineTime->deltaTime();
	if (currentDeltaTime > _lastShot + _shotRate && _mouse->isMouseButtonJustDown(MouseButton::RIGHT))
	{
		_lastShot = currentDeltaTime;
		shoot();
	}
}

void PlayerShootComponent::onTrigger(GameObject* other)
{
	//The enemy is in player range
	//static_cast<Enemy*>(other)->setInPlayerRange(true);
}

void PlayerShootComponent::shoot()
{
	//Me quedo con la direcci�n a la que dispara el player
	Vector3 direction = _tr->getForward();
	Vector3 position = _tr->getPosition() + direction.normalize() * 5; //Me coloco un poco m�s alante que el player

	//Instanciar la bala
}

GameObject* PlayerShootComponent::createBullet()
{
	//GameObject* newBullet = Engine::getInstance()->addGameObject();
	//newBullet->addComponent();  a�adir bala behaviour
	//Transform* tr = new Transform();
	//tr->setPosition(Vector3(0, 0, 0));
	//tr->setRotation(_tr->getRotation());

	//RenderObjectComponent* renderObject = new RenderObjectComponent();
	////renderObject->setMesh();  //Para ponerle algo visual que ver

	//RigidBodyComponent* rb = new RigidBodyComponent();
	////rb->setType();   //Hace falta decirle qu� tipo de colision tiene
	//rb->setMass(0);   //Har�a falta poner constrains

	////BulletComponent

	//newBullet->addComponent(tr);
	//newBullet->addComponent(renderObject);
	//newBullet->addComponent(rb);
	////newBullet->addComponent(bulletComponent);

	return nullptr;
}