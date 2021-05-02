#include "PlayerHealthComponent.h"
#include "UserComponentIDs.h"
#include "includeLUA.h"

ADD_COMPONENT(PlayerHealthComponent);

PlayerHealthComponent::PlayerHealthComponent() : Component(UserComponentId::Health), _maxLife(0), _lives(0)
{
}

PlayerHealthComponent::PlayerHealthComponent(int nLives) : Component(UserComponentId::Health), _maxLife(nLives), _lives(nLives)
{
}

PlayerHealthComponent::PlayerHealthComponent(int nLives, GameObject* go) : Component(UserComponentId::Health, go), _maxLife(nLives), _lives(nLives)
{
}

void PlayerHealthComponent::awake(luabridge::LuaRef& data)
{
	_lives = data["Lives"].cast<int>();
	_maxLife = data["MaxLife"].cast<int>();
}

void PlayerHealthComponent::addLife(int n)
{
	if (n > 0)
		if (n + _lives <= _maxLife)
			_lives += n;
		else _lives = _maxLife;
}

void PlayerHealthComponent::loseLife(int n)
{
	if (n > 0)
		if (_lives - n > 0)
			_lives -= n;
		else reset();
}

void PlayerHealthComponent::reset()
{
	_lives = _maxLife;
}