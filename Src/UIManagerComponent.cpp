#include "UIManagerComponent.h"
#include "UserComponentIDs.h"
#include "includeLUA.h"
#include "TextManagerElement.h"
#include "OverlayElementMngr.h"
#include "OverlayComponent.h"

ADD_COMPONENT(UIManagerComponent);

UIManagerComponent::UIManagerComponent() : Component(UserComponentId::UIManagerComponent), _textRounds(nullptr), _textScore(nullptr), _weaponPanel(nullptr), _lifesPanel(nullptr)
{
}

UIManagerComponent::~UIManagerComponent()
{
}

void UIManagerComponent::start()
{
	_textRounds = new TextManagerElement("PruebaUI/Bullets");
	_textScore = new TextManagerElement("PruebaUI/Points");
	_weaponPanel = new OverlayElementMngr("PruebaUI/Arma");
}

void UIManagerComponent::setRoundsText(int round)
{
	_textRounds->setText(std::to_string(round));
}

void UIManagerComponent::setPlayerScore(int score)
{
	_textScore->setText(std::to_string(score));
}

void UIManagerComponent::changeWeapon(int weaponNumber)
{
	//WIP
}
