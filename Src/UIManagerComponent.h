#pragma once
#ifndef UIMANAGERCOMPONENT_H
#define UIMANAGERCOMPONENT_H

#include "Component.h"

class TextManagerElement;
class OverlayElementMngr;

class UIManagerComponent : public Component {
	public:
		UIManagerComponent();
		~UIManagerComponent();

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
		/// Changes the weapon GUI sprite
		/// </summary>
		/// <param name="weaponNumber"></param>
		void changeWeapon(int weaponNumber);

		//lifesPanel method (WIP)
	private:
		TextManagerElement* _textRounds;
		TextManagerElement* _textScore;
		OverlayElementMngr* _weaponPanel;
		OverlayElementMngr* _lifesPanel;
};

#endif // !UIMANAGERCOMPONENT_H