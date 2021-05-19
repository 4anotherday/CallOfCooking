#pragma once
#ifndef BUTTONS_H
#define BUTTONS_H

#include "Component.h"

class ButtonComponent;

//-----------------------------------------------PLAY BUTTON-------------------------------------------------------------
class PlayButtonComponent : public Component {
public:
	/// <summary>
	/// Class constructor
	/// </summary>
	PlayButtonComponent();
	
	/// <summary>
	/// Class destructor
	/// </summary>
	~PlayButtonComponent();
	
	virtual void start() override;
private:
	/// <summary>
	/// Change scene to Level1
	/// </summary>
	/// <param name="player"></param>
	static void startGame(void* player);
	
	ButtonComponent* _buttonComp;
};

//-----------------------------------------------QUIT BUTTON-------------------------------------------------------------
class QuitButtonComponent : public Component {
public:
	/// <summary>
	/// Class constructor
	/// </summary>
	QuitButtonComponent();

	~QuitButtonComponent();

	virtual void start() override;
private:
	/// <summary>
	/// Called to stop execution of the engine
	/// </summary>
	/// <param name="player"></param>
	static void quitGame(void* player);

	ButtonComponent* _buttonComp;
};

//-----------------------------------------------RESTARTGAME BUTTON-------------------------------------------------------------
class RestartGameButtonComponent : public Component {
public:
	/// <summary>
	/// Class constructor
	/// </summary>
	RestartGameButtonComponent();

	~RestartGameButtonComponent();

	virtual void start() override;

	/// <summary>
	/// enables or disables the button
	/// </summary>
	void enableButton(bool b);
private:
	/// <summary>
	/// Goes back to main menu
	/// </summary>
	static void backToMainMenu(void* player);

	ButtonComponent* _buttonComp;
};

//-----------------------------------------------QUITEND BUTTON-------------------------------------------------------------
class QuitEndGameButtonComponent : public Component {
public:
	/// <summary>
	/// Class constructor
	/// </summary>
	QuitEndGameButtonComponent();

	~QuitEndGameButtonComponent();

	virtual void start() override;

	/// <summary>
	/// Enables or disables the button
	/// </summary>
	void enableButton(bool b);
private:
	/// <summary>
	/// Quits the game
	/// </summary>
	/// <param name="player"></param>
	static void quitGame(void* player);

	ButtonComponent* _buttonComp;
};

#endif // !BUTTONS_H
