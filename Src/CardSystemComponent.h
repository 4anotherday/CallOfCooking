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

	virtual void start() override;

private:
	std::vector<GameObject*> _carts;
};
#endif // !CARDSYSTEMCOMPONENT_H
