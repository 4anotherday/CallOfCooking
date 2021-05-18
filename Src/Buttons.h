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

//-----------------------------------------------RESTARTGAME BUTTON-------------------------------------------------------------
class RestartGameButtonComponent : public Component {
public:
	RestartGameButtonComponent();

	~RestartGameButtonComponent();

	virtual void start() override;

	void enableButton(bool b);
private:
	static void restartGame(void* player);

	ButtonComponent* _buttonComp;
};

//-----------------------------------------------QUITEND BUTTON-------------------------------------------------------------
class QuitEndGameButtonComponent : public Component {
public:
	QuitEndGameButtonComponent();

	~QuitEndGameButtonComponent();

	virtual void start() override;

	void enableButton(bool b);
private:
	static void quitGame(void* player);

	ButtonComponent* _buttonComp;
};

#endif // !BUTTONS_H
