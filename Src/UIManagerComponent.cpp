#include "UIManagerComponent.h"
#include "UserComponentIDs.h"
#include "includeLUA.h"
#include "TextManagerElement.h"
#include "OverlayComponent.h"

ADD_COMPONENT(UIManagerComponent);

UIManagerComponent::UIManagerComponent() : Component(UserComponentId::UIManagerComponent)
{
}

UIManagerComponent::~UIManagerComponent()
{
}

void UIManagerComponent::start()
{
	_textRounds = new TextManagerElement("PruebaUI", "PruebaUI/Bullets");
	_textScore = new TextManagerElement("PruebaUI", "PruebaUI/Points");
}

void UIManagerComponent::setRoundsText(int round)
{
	_textRounds->setText(std::to_string(round));
}

void UIManagerComponent::setPlayerScore(int score)
{
	_textScore->setText(std::to_string(score));
}
