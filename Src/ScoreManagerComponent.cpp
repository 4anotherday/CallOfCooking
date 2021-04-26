#include "ScoreManagerComponent.h"
#include "UserComponentIDs.h"

ScoreManagerComponent::ScoreManagerComponent(): Component(UserComponentId::ScoreManagerComponent),_score(0),_maxScore(0)
{
}

ScoreManagerComponent::~ScoreManagerComponent()
{
}

void ScoreManagerComponent::awake(luabridge::LuaRef& data)
{
	_score = data["Score"].cast<int>();
	_maxScore = data["MaxScore"].cast<int>();
}
