#pragma once
#ifndef POOLCOMPONENT_H
#define POOLCOMPONENT_H

#include <stdlib.h> 
#include <time.h>       /* time -> ver si se puede cambiar el random por uno que use los delta times de EngineTime*/
#include "UserComponentIDs.h"
#include "Component.h"
#include <vector>
#include "Vector3.h"
#include "UserComponentIDs.h"
class LevelManagerComponent;

class PoolComponent : public Component
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	PoolComponent(UserComponentId::UserComponentId id);

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~PoolComponent();

	virtual void start() override;

	virtual void update() override;

	/// <summary>
	/// Returns the entire group of game objects
	/// </summary>
	std::vector<GameObject*> getPool() const { return _mainPool; }

	/// <summary>
	/// Returns the group of inactive game objects
	/// </summary>
	std::vector<GameObject*> getInactivePool() const { return _inactivePool; }

	/// <summary>
	///	Returns an inactive game object, in case there is not it will create a group to have them ready
	/// </summary>
	virtual GameObject* getInactiveGO();

	/// <summary>
	///	Set an game object as inactive
	/// </summary>
	virtual void setInactiveGO(GameObject* go);

	/// <summary>
	///	Wake up the requested number of enemies, it is a process similar to resetting them
	/// </summary>
	virtual void wakeUpEnemies(int howMany);

protected:
	/// <summary>
	///	Creates a specified number of inactive game objects and includes them in both groups
	// 	Each subclass must define how to do this process
	/// </summary>
	virtual void createGos(int howMany) {};


	bool isTimeToSpawn();

	LevelManagerComponent* _lvlManager;

	std::vector<GameObject*> _mainPool;
	std::vector<GameObject*> _inactivePool;	
	std::vector<Vector3> _respawnsPositions;	

	bool _isSpawnTime;
	int _howManyEnemiesSpawn;
	int _totalEnemiesSpawned;
	float _spawnEnemyTime;
	float _lastSpawnEnemyTime;
};
#endif // !POOLCOMPONENT_H
