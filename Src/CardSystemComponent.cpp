#include "CardSystemComponent.h"
#include "UserComponentIDs.h"
#include "PrefabLoader.h"
#include "GameObject.h"
#include "Exceptions.h"
#include "includeLUA.h"
#include "Engine.h"

ADD_COMPONENT(CardSystemComponent);

CardSystemComponent::CardSystemComponent() : Component(UserComponentId::UserComponentId::CardSystemComponent)
{
}

CardSystemComponent::~CardSystemComponent()
{
}

void CardSystemComponent::awake(luabridge::LuaRef& data)
{
	try {
		std::string nameAttack;
		if (LUAFIELDEXIST(AttackCardPrefab)) nameAttack = GETLUAFIELD(AttackCardPrefab, std::string);
		GameObject* o = PrefabLoader::getInstance()->loadPrefab(nameAttack, 1);
		_cards.push_back(o);
		o->setEnabled(true);

		std::string nameLife;
		if (LUAFIELDEXIST(LifeCardPrefab)) nameLife = GETLUAFIELD(LifeCardPrefab, std::string);
		o = PrefabLoader::getInstance()->loadPrefab(nameLife, 1);
		_cards.push_back(o);
		o->setEnabled(true);

		std::string nameMovSpeed;
		if (LUAFIELDEXIST(MovSpeedCardPrefab)) nameMovSpeed = GETLUAFIELD(MovSpeedCardPrefab, std::string);
		o = PrefabLoader::getInstance()->loadPrefab(nameMovSpeed, 1);
		_cards.push_back(o);
		o->setEnabled(true);
	}
	catch (...) {
		throw ExcepcionTAD("Error loading prefabs in the game object: " + _gameObject->getName() + " component: CardSystemComponent");
	}

}

void CardSystemComponent::setCardsUp(bool enable)
{
	for (int i = 0; i < _cards.size(); i++) {
		_cards[i]->setEnabled(enable);
	}
}
