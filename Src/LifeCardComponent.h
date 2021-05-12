#pragma once
#ifndef LIFECARDCOMPONENT_H
#define LIFECARDCOMPONENT_H

#include "CardComponent.h"

class PlayerHealthComponent;

class LifeCardComponent : public CardComponent
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	LifeCardComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~LifeCardComponent();

	virtual void start() override;

	/// <summary>
	/// Static function for the button
	/// </summary>
	static void operate(void* player);

private:
	PlayerHealthComponent* _player;

	static int _extraLife;
};
#endif // !POOLCOMPONENT_H
