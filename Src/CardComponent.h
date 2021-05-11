#pragma once
#ifndef CARDCOMPONENT_H
#define CARDCOMPONENT_H

#include "Component.h"
#include "UserComponentIDs.h"

class ButtonComponent;
namespace luabridge {
	class LuaRef;
}

class CardComponent : public Component
{
	/// <summary>
	/// Static function that is called when user clicks on the button
	/// </summary>
	using CallBackOnClick = void(void*);
public:
	/// <summary>
	/// Constructor of the class
	/// </summary>
	CardComponent(UserComponentId::UserComponentId id);

	/// <summary>
	/// Destructor of the class
	/// </summary>
	virtual ~CardComponent();

	virtual void start() override;

	void setOverlayName(std::string& const name);
	void setContainerName(std::string& const name);
	void setDefaultName(std::string& const name);
	void setHoverName(std::string& const name);
	void setPressName(std::string& const name);
	void setCallBack(CallBackOnClick* callback);
	void setCallBackParam(void* param);
	void setActive(bool active);

protected:

	ButtonComponent* _button;
};
#endif // !CARDCOMPONENT_H
