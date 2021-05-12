#pragma once
#ifndef MOVEMENTSPEEDCARDCOMPONENT_H
#define MOVEMENTSPEEDCARDCOMPONENT_H

#include "CardComponent.h"
class PlayerMovementComponent;
class ButtonComponent;

class MovementSpeedCardComponent : public CardComponent
{
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	MovementSpeedCardComponent();

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~MovementSpeedCardComponent();

	virtual void start() override;

	/// <summary>
	/// Static function for the button
	/// </summary>
	static void operate(void* player);

protected:
	PlayerMovementComponent* _player;
	ButtonComponent* _button;
	static int _extraMovementSpeed;
};
#endif // !MOVEMENTSPEEDCARDCOMPONENT_H
