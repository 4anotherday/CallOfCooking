#include "PlayerAttackComponent.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "MouseInput.h"
#include "EngineTime.h"
#include "includeLUA.h"
#include "Transform.h"
#include "RigidBodyComponent.h"
#include "Engine.h"
#include "EnemyHealthComponent.h"
#include "LemonPoolComponent.h"
#include "WatermelonPoolComponent.h"
#include "GranadePoolComponent.h"

ADD_COMPONENT(PlayerAttackComponent);

PlayerAttackComponent::PlayerAttackComponent() : Component(UserComponentId::PlayerAttackComponent),
_trPlayer(nullptr), _tr(nullptr), _rb(nullptr), _damage(1.0f), _attackHitBoxDistance(0.35f), _windowSizeX(), _windowSizeY(), _playerRange(1.0f),
_lemonPool(nullptr), _grenadePool(nullptr), _watermelonPool(nullptr),
_mouse(MouseInput::getInstance()), _engineTime(EngineTime::getInstance()), _attackRate(0.5), _lastAttack(_engineTime->deltaTime())
{
}

PlayerAttackComponent::PlayerAttackComponent(GameObject* gameObject) : Component(UserComponentId::PlayerAttackComponent, gameObject),
_trPlayer(nullptr), _tr(nullptr), _rb(nullptr), _damage(5), _attackHitBoxDistance(0.25f), _windowSizeX(), _windowSizeY(), _playerRange(3.0f),
_lemonPool(nullptr), _grenadePool(nullptr), _watermelonPool(nullptr),
_mouse(MouseInput::getInstance()), _engineTime(EngineTime::getInstance()), _attackRate(2.0f), _lastAttack(_engineTime->deltaTime())
{
}

PlayerAttackComponent::~PlayerAttackComponent()
{
}

void PlayerAttackComponent::awake(luabridge::LuaRef& data)
{
	if(LUAFIELDEXIST(Damage)) _damage = data["Damage"].cast<float>();
	if(LUAFIELDEXIST(AtackRate)) _attackRate = data["AtackRate"].cast<float>();
	if(LUAFIELDEXIST(AttackHitBoxDistance)) _attackHitBoxDistance = data["AttackHitBoxDistance"].cast<float>();
	if(LUAFIELDEXIST(PlayerRange)) _playerRange = data["PlayerRange"].cast<float>();
}

void PlayerAttackComponent::start()
{
	std::pair<int, int> size = Engine::getInstance()->getWindowSize();
	_windowSizeX = size.first;
	_windowSizeY = size.second;

	_tr = static_cast<Transform*>(_gameObject->getComponent(ComponentId::Transform));
	_trPlayer = static_cast<Transform*>(Engine::getInstance()->findGameObject("Player")->getComponent(ComponentId::Transform));
	//_rb = static_cast<RigidBodyComponent*>(_gameObject->getComponent(ComponentId::Rigidbody));

	_lemonPool = static_cast<LemonPoolComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LemonPoolComponent));
	_grenadePool = static_cast<GranadePoolComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::GranadePoolComponent));
	_watermelonPool = static_cast<WatermelonPoolComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::WatermelonPoolComponent));

	_mouse->setMouseRelativeMode(false);
}

void PlayerAttackComponent::update()
{
	float currentDeltaTime = _engineTime->deltaTime();

	rotateAttackHitBox();
	attack(currentDeltaTime);
}

void PlayerAttackComponent::onTrigger(GameObject* other)
{
	//The enemy is in player range
	EnemyHealthComponent* h = static_cast<EnemyHealthComponent*>(other->getComponent(UserComponentId::EnemyHealthComponent));
	if (h != nullptr) h->setInPlayerRange(true);
}

void PlayerAttackComponent::increaseAttackRate(float extraAttackRate)
{
	_attackRate += extraAttackRate;
}

void PlayerAttackComponent::rotateAttackHitBox()
{
	float mousePosX = MouseInput::getInstance()->getMousePos()[0];
	mousePosX = mousePosX * _windowSizeX;
	mousePosX = mousePosX - (_windowSizeX / 2);
	float mousePosY = MouseInput::getInstance()->getMousePos()[1];
	mousePosY = mousePosY * _windowSizeY;
	mousePosY = mousePosY - (_windowSizeY / 2);

	float dirX = mousePosX - _trPlayer->getPosition().getX();
	float dirZ = mousePosY - _trPlayer->getPosition().getZ();

	Vector3 attackDir = Vector3(dirX, 0.0f, dirZ).normalize();

	_tr->setPosition(_trPlayer->getPosition() + attackDir * _attackHitBoxDistance);
}

void PlayerAttackComponent::attack(float deltaTime)
{
	_lastAttack -= deltaTime;

	//Here we attack
	if (_lastAttack <= 0 && _mouse->isMouseButtonJustDown(MouseButton::LEFT))
	{
		//Enemies are not in player range
		enemiesNotInPlayerRange();
		_lastAttack = _attackRate;

		attackEnemies();
	}
}

void PlayerAttackComponent::enemiesNotInPlayerRange()
{
	for (auto& e : _lemonPool->getPool())
	{
		Transform* enemyTr = static_cast<Transform*>(e->getComponent(ComponentId::Transform));
		EnemyHealthComponent* h = static_cast<EnemyHealthComponent*>(e->getComponent(UserComponentId::EnemyHealthComponent));
		float distance = (_tr->getPosition() - enemyTr->getPosition()).magnitude();

		if (distance > _playerRange)
		{
			h->setInPlayerRange(false);
		}
	}

	for (auto& e : _grenadePool->getPool())
	{
		Transform* enemyTr = static_cast<Transform*>(e->getComponent(ComponentId::Transform));
		EnemyHealthComponent* h = static_cast<EnemyHealthComponent*>(e->getComponent(UserComponentId::EnemyHealthComponent));
		float distance = (_tr->getPosition() - enemyTr->getPosition()).magnitude();

		if (distance > _playerRange)
		{
			h->setInPlayerRange(false);
		}
	}

	std::vector<GameObject*> vector2 = _lemonPool->getPool();
	std::vector<GameObject*> vector = _watermelonPool->getPool();

	for (auto& e : _watermelonPool->getPool())
	{
		Transform* enemyTr = static_cast<Transform*>(e->getComponent(ComponentId::Transform));
		EnemyHealthComponent* h = static_cast<EnemyHealthComponent*>(e->getComponent(UserComponentId::EnemyHealthComponent));
		float distance = (_tr->getPosition() - enemyTr->getPosition()).magnitude();

		if (distance > _playerRange)
		{
			h->setInPlayerRange(false);
		}
	}
}

void PlayerAttackComponent::attackEnemies()
{
	for (auto& e : _lemonPool->getPool())
	{
		EnemyHealthComponent* h = static_cast<EnemyHealthComponent*>(e->getComponent(UserComponentId::EnemyHealthComponent));

		if (h->inPlayerRange())
		{
			h->reduceLivesPoints(_damage);
		}
	}

	for (auto& e : _grenadePool->getPool())
	{
		EnemyHealthComponent* h = static_cast<EnemyHealthComponent*>(e->getComponent(UserComponentId::EnemyHealthComponent));

		if (h->inPlayerRange())
		{
			h->reduceLivesPoints(_damage);
		}
	}

	for (auto& e : _watermelonPool->getPool())
	{
		EnemyHealthComponent* h = static_cast<EnemyHealthComponent*>(e->getComponent(UserComponentId::EnemyHealthComponent));

		if (h->inPlayerRange())
		{
			h->reduceLivesPoints(_damage);
		}
	}
}