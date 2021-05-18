#include "Buttons.h"
#include "includeLUA.h"
#include "Engine.h"
#include "ButtonComponent.h"
#include "GameObject.h"
#include "MouseInput.h"
#include "AudioSourceComponent.h"
#include "UserComponentIDs.h"

//-----------------------------------------------PLAY BUTTON-------------------------------------------------------------
ADD_COMPONENT(PlayButtonComponent)

PlayButtonComponent::PlayButtonComponent(): Component(UserComponentId::PlayButtonComponent), _buttonComp(nullptr)
{
}

PlayButtonComponent::~PlayButtonComponent()
{
}

void PlayButtonComponent::start()
{
	_buttonComp = GETCOMPONENT(ButtonComponent, ComponentId::ButtonComponent);
	_buttonComp->setCallBackParam(nullptr);
	_buttonComp->setCallBack(startGame);
}

void PlayButtonComponent::startGame(void* null)
{
	MouseInput::getInstance()->setMouseRelativeMode(true);

	static_cast<AudioSourceComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(ComponentId::AudioSource))->stopChannel(0);

	Engine::getInstance()->changeScene("Level1.lua");
}

//-----------------------------------------------QUIT BUTTON-------------------------------------------------------------
ADD_COMPONENT(QuitButtonComponent)

QuitButtonComponent::QuitButtonComponent(): Component(UserComponentId::QuitButtonComponent), _buttonComp(nullptr)
{
}

QuitButtonComponent::~QuitButtonComponent()
{
}

void QuitButtonComponent::start()
{
	_buttonComp = GETCOMPONENT(ButtonComponent, ComponentId::ButtonComponent);
	_buttonComp->setCallBackParam(nullptr);
	_buttonComp->setCallBack(quitGame);
}

void QuitButtonComponent::quitGame(void* player)
{
	Engine::getInstance()->stopExecution();
}
