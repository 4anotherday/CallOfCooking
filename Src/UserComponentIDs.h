#pragma once
/*
This enum controls de order of updates of components in every gameObject,
	except those defined by the user, which always update the latest

It's recommendable to keep an order when introducing a new Component to the enum
	(Eg. first graphic-related objects, then audio, etc)
*/
#include "ComponentIDs.h"
namespace UserComponentId {
	enum UserComponentId : unsigned int {

		Health = 1
	};
}