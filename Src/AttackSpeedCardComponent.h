#pragma once
#ifndef ATTACKSPEEDCARDCOMPONENT_H
#define ATTACKSPEEDCARDCOMPONENT_H

#include "CardComponent.h"

class PlayerShootComponent;

class AttackSpeedCardComponent : public CardComponent
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	AttackSpeedCardComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~AttackSpeedCardComponent();

	virtual void start() override;

	/// <summary>
	/// Static function for the button
	/// </summary>
	static void operate(void* player);

protected:

	PlayerShootComponent* _shootComponent;
	static float _attackRate;
};
#endif // !ATTACKSPEEDCARDCOMPONENT_H
