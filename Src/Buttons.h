#pragma once
#ifndef BUTTONS_H
#define BUTTONS_H

#include "Component.h"

class ButtonComponent;

//-----------------------------------------------PLAY BUTTON-------------------------------------------------------------
class PlayButtonComponent : public Component {
public:
	PlayButtonComponent();
	
	~PlayButtonComponent();
	
	virtual void start() override;
private:
	static void startGame(void* player);
	
	ButtonComponent* _buttonComp;
};

//-----------------------------------------------QUIT BUTTON-------------------------------------------------------------
class QuitButtonComponent : public Component {
public:
	QuitButtonComponent();

	~QuitButtonComponent();

	virtual void start() override;
private:
	static void quitGame(void* player);

	ButtonComponent* _buttonComp;
};

#endif // !BUTTONS_H
