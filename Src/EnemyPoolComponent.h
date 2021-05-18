#pragma once
#ifndef ENEMYPOOLCOMPONENT_H
#define ENEMYPOOLCOMPONENT_H

#include "PoolComponent.h"
#include "Vector3.h"

class EnemyPoolComponent : public PoolComponent	
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	EnemyPoolComponent(UserComponentId::UserComponentId id);

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~EnemyPoolComponent();

	virtual void update() override;

	/// <summary>
	///	Wake up the requested number of enemies, it is a process similar to resetting them
	/// </summary>
	virtual void wakeUpEnemies(int howMany, float spawnEnemyTime);

	/// <summary>
	///	Set the differents respawn enemy positions
	/// </summary>
	void setRespawnPositions(std::vector<Vector3> &rP) { _respawnsPositions = rP; };

	/// <summary>
	///	Set an infinite round
	/// </summary>
	void setInfinityRound(bool iR);

	/// <summary>
	///	Set the spawn enemy time
	/// </summary>
	void spawnEnemyTime(float sT) { _spawnEnemyTime = sT; }

protected:
	/// <summary>
	///	Check if it's time to spawn an enemy
	/// </summary>	
	bool isTimeToSpawn();

	/// <summary>
	///	Spawn an enemy so infinite enemies will appear
	/// </summary>	
	void enemySpawn();

	std::vector<Vector3> _respawnsPositions;

	int _howManyEnemiesSpawn;
	int _totalEnemiesSpawned;
	float _spawnEnemyTime;
	float _lastSpawnEnemyTime;
	bool _infiniteRound;
	float _time;
};
#endif // !ENEMYPOOLCOMPONENT_H
