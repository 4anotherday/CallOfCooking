#pragma once
#ifndef POOLCOMPONENT_H
#define POOLCOMPONENT_H

#include "Component.h"
#include <vector>

class PoolComponent : public Component	
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	PoolComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~PoolComponent();

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
	/// <summary>
	///	Creates a specified number of inactive game objects and includes them in both groups
	// 	Each subclass must define how to do this process
	/// </summary>		
	virtual void createGos(int howMany) {};

	std::vector<GameObject*> _mainPool;
	std::vector<GameObject*> _inactivePool;

};
#endif // !POOLCOMPONENT_H
