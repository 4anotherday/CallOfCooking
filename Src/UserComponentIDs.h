#pragma once

#ifndef USERCOMPONENTSIDS_H
#define USERCOMPONENTSIDS_H

#include "ComponentIDs.h"

/*
This enum controls de order of updates of components and their IDs.
Always after engine basic components.

It's recommendable to keep an order when introducing a new Component to the enum
	(Eg. first graphic-related objects, then audio, etc)
*/

namespace UserComponentId {
	enum UserComponentId : unsigned int {
		Health = ComponentId::__StartPointUser__,
		PlayerMovementComponent,
		PlayerAttackComponent,
		PlayerShootComponent,
		LevelManagerComponent,
		ScoreManagerComponent,
		PoolComponent,
		EnemyBehaviorComponent,
		EnemyHealthComponent
	};
}

#endif // !USERCOMPONENTSIDS_H