#pragma once
#ifndef UIMANAGERCOMPONENT_H
#define UIMANAGERCOMPONENT_H

#include "Component.h"
#include <vector>

class TextManagerElement;
class OverlayElementMngr;

class UIManagerComponent : public Component {
public:
	UIManagerComponent();
	~UIManagerComponent();

	void awake(luabridge::LuaRef& data) override;

	void start() override;

	/// <summary>
	/// Sets the current round in the GUI
	/// </summary>
	/// <param name="round"></param>
	void setRoundsText(int round);

	/// <summary>
	/// Sets the player score in the GUI
	/// </summary>
	/// <param name="score"></param>
	void setPlayerScore(int score);

	/// <summary>
	/// Sets the current life of the player in the GUI
	/// </summary>
	/// <param name="round"></param>
	void setPlayerLife(int life);

	/// <summary>
	/// Changes the weapon GUI sprite
	/// </summary>
	/// <param name="weaponNumber"></param>
	void changeWeapon(int weaponNumber);

	/// <summary>
	/// Shows the final game panel
	/// </summary>
	void showFinalPanel();

	/// <summary>
	/// Hides the final game panel
	/// </summary>
	void hideFinalPanel();

	/// <summary>
	/// Sets the final score to show the score in the final game panel
	/// </summary>
	void setFinalPanelScore(int score);

	/// <summary>
	/// Called when player dies
	/// </summary>
	inline void setGameOver(bool gOver) { _gameOver = gOver; }
private:
	TextManagerElement* _textRounds;
	TextManagerElement* _textScore;
	OverlayElementMngr* _weaponPanel;
	std::vector<OverlayElementMngr*> _lifes;

	OverlayElementMngr* _finalPanel;
	TextManagerElement* _textFinalScore;
	bool _gameOver;
};

#endif // !UIMANAGERCOMPONENT_H