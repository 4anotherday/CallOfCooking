#pragma once
#ifndef ENEMYHEALTHCOMPONENT_H
#define ENEMYHEALTHCOMPONENT_H

#include "LevelManagerComponent.h"
class ScoreManagerComponent;

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
	/// Reduce hit points
	/// </summary>
	/// <param name="damage">Damage points</param>
	void reduceLivesPoints(int damage);

	/// <summary>
	/// Restart the lives of the enemy
	/// </summary>
	void restartLives();

	/// <summary>
	/// Return the current lives of the player
	/// </summary>
	/// <returns></returns>
	inline int getLives() { return _remainingLives; }

	/// <summary>
	/// Returns if the enemy is in player range
	/// </summary>
	inline bool inPlayerRange() const { return _inPlayerRange; }

	/// <summary>
	/// Sets if the enemy is in player range
	/// </summary>
	/// <param name="b">If it´s in player range or not</param>
	inline void setInPlayerRange(bool b) { _inPlayerRange = b; }

	/// <summary>
	/// Sets the enemy type
	/// </summary>
	/// <param name="type">Enemy type</param>
	inline void setMyEnemyType(int type) { _enemyType = (EnemyType)type; }

private:
	ScoreManagerComponent* _scoreManager;
	LevelManagerComponent* _lvlManager;
	EnemyType _enemyType;

	int _totalLives;
	int _remainingLives;
	int _deathComboPoints;
	bool _inPlayerRange;
};
#endif // !ENEMYHEALTHCOMPONENT_H
