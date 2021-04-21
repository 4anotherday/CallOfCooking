#include "PlayerHealth.h"
#include "UserComponentIDs.h"

PlayerHealth::PlayerHealth(int nLives) :Component(ComponentId::__StartPointUser__ + UserComponentId::Health), maxLife(nLives), lives(nLives)
{
}

PlayerHealth::PlayerHealth(int nLives, GameObject* go) : Component(ComponentId::__StartPointUser__ + UserComponentId::Health, go), maxLife(nLives), lives(nLives)
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
		reset();
	}
	else lives--;
}

void PlayerHealth::reset()
{
	lives = maxLife;
}
