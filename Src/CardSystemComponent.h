#pragma once
#ifndef CARDSYSTEMCOMPONENT_H
#define CARDSYSTEMCOMPONENT_H

#include "Component.h"
#include <vector>

class CardSystemComponent : public Component
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	CardSystemComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~CardSystemComponent();

	/// <summary>
	/// Default component constructor
	/// </summary>
	virtual void awake(luabridge::LuaRef& data) override;
	
	/// <summary>
	/// Set the cards visible or not visible
	/// </summary>
	void setCardsUp(bool enable);

private:
	std::vector<GameObject*> _cards;
};
#endif // !CARDSYSTEMCOMPONENT_H
