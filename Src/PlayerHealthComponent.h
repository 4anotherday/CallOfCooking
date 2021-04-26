#pragma once
#include "KeyboardInput.h"
#include "Component.h"
#ifndef PLAYERHEALTHCOMPONENT_H
#define PLAYERHEALTHCOMPONENT_H

class PlayerHealthComponent : public Component	
{
public:
	/// <summary>
	/// initialize the player with "lives" lives
	/// </summary>
	/// <param name="nLives">initial lives of the player</param>
	PlayerHealthComponent(int nLives);

	/// <summary>
	/// initialize the player with "lives" lives
	/// </summary>
	/// <param name="nLives">initial lives of the player</param>
	/// <param name="go">the gameObject this component will be attached to</param>
	PlayerHealthComponent(int nLives, GameObject* go);

	virtual void awake(luabridge::LuaRef& data);

	/// <summary>
	/// add n life points to the player
	/// </summary>
	/// <param name="n">number of life points to add</param>
	void addLife(int n);
	/// <summary>
	/// lose one life
	/// </summary>
	void loseLife(int n);
	/// <summary>
	/// reset the player life points
	/// </summary>
	void reset();
private:
	int _lives;
	int _maxLife;
};
#endif // !PLAYERHEALTHCOMPONENT_H
