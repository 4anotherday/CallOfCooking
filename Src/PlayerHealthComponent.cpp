#include "PlayerHealthComponent.h"
#include "Engine.h"
#include "GameObject.h"
#include "UserComponentIDs.h"
#include "UIManagerComponent.h"
#include "LevelManagerComponent.h"
#include "includeLUA.h"

ADD_COMPONENT(PlayerHealthComponent);

PlayerHealthComponent::PlayerHealthComponent() : Component(UserComponentId::PlayerHealthComponent), _maxLife(0), _lives(0)
{
}

PlayerHealthComponent::PlayerHealthComponent(int nLives) : Component(UserComponentId::PlayerHealthComponent), _maxLife(nLives), _lives(nLives)
{
}

PlayerHealthComponent::PlayerHealthComponent(int nLives, GameObject* go) : Component(UserComponentId::PlayerHealthComponent, go), _maxLife(nLives), _lives(nLives)
{
}

void PlayerHealthComponent::awake(luabridge::LuaRef& data)
{
	_lives = data["Lives"].cast<int>();
	_maxLife = data["MaxLife"].cast<int>();
}

void PlayerHealthComponent::start()
{
	_uimanager = static_cast<UIManagerComponent*>(Engine::getInstance()->findGameObject("UIManager")->getComponent(UserComponentId::UIManagerComponent));
	_uimanager->setPlayerLife(_maxLife);

	_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
}

void PlayerHealthComponent::addLife(int n)
{
	if (n > 0)
		if (n + _lives <= _maxLife)
			_lives += n;
		else _lives = _maxLife;
	updateUIlifes();
}

void PlayerHealthComponent::loseLife(int n)
{
	if (n > 0) {
		_lives -= n;
		if (_lives == 0)
			_lvlManager->gameOver();

		updateUIlifes();
	}	
}

void PlayerHealthComponent::reset()
{
	_lives = _maxLife;
	updateUIlifes();
}

void PlayerHealthComponent::updateUIlifes()
{
	_uimanager->setPlayerLife(_lives);
}
