#include "UIManagerComponent.h"
#include "UserComponentIDs.h"
#include "includeLUA.h"
#include "TextManagerElement.h"
#include "OverlayElementMngr.h"
#include "OverlayComponent.h"

ADD_COMPONENT(UIManagerComponent);

UIManagerComponent::UIManagerComponent() : Component(UserComponentId::UIManagerComponent), _textRounds(nullptr), _textScore(nullptr), _weaponPanel(nullptr), _gameOver(false)
{
}

UIManagerComponent::~UIManagerComponent()
{
}

void UIManagerComponent::awake(luabridge::LuaRef& data)
{
	_textRounds = new TextManagerElement("GameUI/Rounds");
	_textScore = new TextManagerElement("GameUI/Points");

	_lifes.push_back(new OverlayElementMngr("GameUI/Corazon1"));
	_lifes.push_back(new OverlayElementMngr("GameUI/Corazon2"));
	_lifes.push_back(new OverlayElementMngr("GameUI/Corazon3"));

	_finalPanel = new OverlayElementMngr("GameUI/FinalPanel");
	_finalPanel->setEnabled(false);

	_textFinalScore = new TextManagerElement("GameUI/PlayerFinalScore");
}

void UIManagerComponent::start()
{
}

void UIManagerComponent::setRoundsText(int round)
{
	_textRounds->setText("RONDA " + std::to_string(round));
}

void UIManagerComponent::setPlayerScore(int score)
{
	_textScore->setText(std::to_string(score));
}

void UIManagerComponent::setPlayerLife(int life)
{
	if (life >= _lifes.size()) life = _lifes.size();

	for (auto& life : _lifes) {
		life->setEnabled(false);
	}
	for (int i = 0; i < life; i++) {
		_lifes[i]->setEnabled(true);
	}
}

void UIManagerComponent::changeWeapon(int weaponNumber)
{
	if (weaponNumber == 0)
		_weaponPanel->setMaterial("CallOfCooking/Rifle");
	else
		_weaponPanel->setMaterial("CallOfCooking/Cuchillo");
}

void UIManagerComponent::showFinalPanel()
{
	_finalPanel->setEnabled(true);
}

void UIManagerComponent::hideFinalPanel()
{
	_finalPanel->setEnabled(false);
}

void UIManagerComponent::setFinalPanelScore(int score)
{
	if (!_gameOver) {
		std::cout << "CAMBIA VALOR DEL SCORE EN PANEL FINAL" << std::endl;
		_textFinalScore->setText(std::to_string(score));
	}
}
