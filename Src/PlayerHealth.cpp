#include "PlayerHealth.h"
#include "UserComponentIDs.h"

PlayerHealth::PlayerHealth(int nLives) :Component(UserComponentId::Health), maxLife(nLives), lives(nLives)
{
}

PlayerHealth::PlayerHealth(int nLives, GameObject* go) : Component(UserComponentId::Health, go), maxLife(nLives), lives(nLives)
{
}

void PlayerHealth::addLife(int n)
{
	if (n > 0)
		if (n + lives <= maxLife)
			lives += n;
		else lives = maxLife;

}

void PlayerHealth::loseLife(int n)
{

	if (n > 0)
		if (lives - n > 0)
			lives -= n;
		else reset();


}

void PlayerHealth::reset()
{
	lives = maxLife;
}