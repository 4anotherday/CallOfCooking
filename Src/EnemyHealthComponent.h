#pragma once
#ifndef ENEMYHEALTHCOMPONENT_H
#define ENEMYHEALTHCOMPONENT_H

#include "Component.h"

class ScoreManagerComponent;
class LevelManagerComponent;

class EnemyHealthComponent : public Component	
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	EnemyHealthComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~EnemyHealthComponent();

	/// <summary>
	/// Awake class, initializes the local variables 
	/// </summary>
	/// <param name="data">Luaref with the data</param>
	virtual void awake(luabridge::LuaRef& data) override;

	/// <summary>
	/// Initialise the score manager
	/// </summary>
	virtual void start() override;


	/// <summary>
	/// Sets the value of combo points the enemy grants for dying
	/// </summary>
	inline void setDeathComboPoints(int dP) { _deathComboPoints = dP; }

	/// <summary>
	/// Reduce hit points on the enemy
	/// </summary>
	/// <param name="damage">Damage points</param>
	void reduceLivesPoints(int damage);

	/// <summary>
	/// Reset the number of lives
	/// </summary>
	void restartLives();

private:
	ScoreManagerComponent* _scoreManager;	
	LevelManagerComponent* _lvlManager;
	EnemyType _enemyType;

	int _totalLives;
	int _remainingLives;
	int _deathComboPoints;
};
#endif // !ENEMYHEALTHCOMPONENT_H
