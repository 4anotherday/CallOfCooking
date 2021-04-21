#pragma once
#include "Component.h"
#ifndef PLAYERHEALTH_H
#define PLAYERHEALTH_H

class PlayerHealth : public Component	
{
public:
	/// <summary>
	/// initialize the player with "lives" lives
	/// </summary>
	/// <param name="nLives">initial lives of the player</param>
	PlayerHealth(int nLives);

	/// <summary>
	/// initialize the player with "lives" lives
	/// </summary>
	/// <param name="nLives">initial lives of the player</param>
	/// <param name="go">the gameObject this component will be attached to</param>
	PlayerHealth(int nLives, GameObject* go);

	/// <summary>
	/// add n life points to the player
	/// </summary>
	/// <param name="n">number of life points to add</param>
	void addLife(int n);
	/// <summary>
	/// lose one life
	/// </summary>
	void loseLife();
	/// <summary>
	/// reset the player life points
	/// </summary>
	void reset();
private:
	int lives;
	int maxLife;
};
#endif // !PLAYERHEALTH_H

