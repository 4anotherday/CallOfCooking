#include "CardComponent.h"
#include "ButtonComponent.h"
#include "Engine.h"
#include "GameObject.h"
#include "includeLUA.h"

CardComponent::CardComponent(UserComponentId::UserComponentId id) : Component(id)
{
}

CardComponent::~CardComponent()
{
}

void CardComponent::start()
{
	_button = static_cast<ButtonComponent*>(Engine::getInstance()->findGameObject(_gameObject->getName())->getComponent(UserComponentId::Health));
}

void CardComponent::setOverlayName(std::string& const name)
{
	_button->setOverlayName(name);
}

void CardComponent::setContainerName(std::string& const name)
{
	_button->setContainerName(name);
}

void CardComponent::setDefaultName(std::string& const name)
{
	_button->setDeafultName(name);
}

void CardComponent::setHoverName(std::string& const name)
{
	_button->setHoverName(name);
}

void CardComponent::setPressName(std::string& const name)
{
	_button->setPressName(name);
}

void CardComponent::setCallBack(CallBackOnClick* callback)
{
	_button->setCallBack(callback);
}
void CardComponent::setCallBackParam(void* param)
{
	_button->setCallBackParam(param);
}
void CardComponent::setActive(bool active)
{
	_button->hideShowButton(active);
}