#pragma once
#ifndef POOLCOMPONENT_H
#define POOLCOMPONENT_H

#include "UserComponentIDs.h"
#include "Component.h"
#include <vector>
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

protected:
	void loadPrefab(std::string path, int howMany);

	LevelManagerComponent* _lvlManager;

	std::vector<GameObject*> _mainPool;
	std::vector<GameObject*> _inactivePool;	
};
#endif // !POOLCOMPONENT_H
