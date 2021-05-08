#pragma once
#ifndef ATTACKSPEEDCARDCOMPONENT_H
#define ATTACKSPEEDCARDCOMPONENT_H

#include "CardComponent.h"
class PlayerAttackComponent;

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

	static void operate(void* player);

protected:
	PlayerAttackComponent* _player;
	static float _attackRate;
};
#endif // !ATTACKSPEEDCARDCOMPONENT_H