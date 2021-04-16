#include "PlayerHealth.h"
PlayerHealth::PlayerHealth(int nLives) :Component(ComponentId::Health), maxLife(nLives), lives(nLives)
{
}

PlayerHealth::PlayerHealth(int nLives, GameObject* go) : Component(ComponentId::Health, go), maxLife(nLives), lives(nLives)
{
}

void PlayerHealth::addLife(int n)
{
	if (n > 0)
		lives += n;
}

void PlayerHealth::loseLife()
{
	if (lives == 1) {
		//ir a pantalla de game over
	}
	else lives--;
}

void PlayerHealth::reset()
{
	lives = maxLife;
}
