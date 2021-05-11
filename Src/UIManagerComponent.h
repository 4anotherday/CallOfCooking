#pragma once
#ifndef UIMANAGERCOMPONENT_H
#define UIMANAGERCOMPONENT_H

#include "Component.h"

class TextManagerElement;

class UIManagerComponent : public Component {
	public:
		UIManagerComponent();
		~UIManagerComponent();

		void start() override;

		void setRoundsText(int round);

		void setPlayerScore(int score);
	private:
		TextManagerElement* _textRounds;
		TextManagerElement* _textScore;
};

#endif // !UIMANAGERCOMPONENT_H