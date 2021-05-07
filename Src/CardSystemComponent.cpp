#include "GameObject.h"
#include "Engine.h"
#include "includeLUA.h"
#include "CardSystemComponent.h"
#include "LevelManagerComponent.h"
#include "UserComponentIDs.h"

CardSystemComponent::CardSystemComponent() : Component(UserComponentId::UserComponentId::CardSystemComponent)
{
}

CardSystemComponent::~CardSystemComponent()
{
}

void CardSystemComponent::start()
{
	//_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
}