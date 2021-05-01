#include "ScoreManagerComponent.h"
#include "UserComponentIDs.h"
#include "GameObject.h"
#include "includeLUA.h"
#include "Engine.h"
#include "EngineTime.h"
#include "LevelManagerComponent.h"
#include "includeLUA.h"


ADD_COMPONENT(ScoreManagerComponent);

ScoreManagerComponent::ScoreManagerComponent(): Component(UserComponentId::ScoreManagerComponent),
	_score(0),_maxScore(0), _comboPoints(0), _comboTime(0.0f), _actualComboSequenceTime(0.0f), 
	_engineTime(EngineTime::getInstance()), _isComboSequence(false), _lvlManager()
{
}

ScoreManagerComponent::~ScoreManagerComponent()
{
}

void ScoreManagerComponent::awake(luabridge::LuaRef& data)
{
	_score = data["Score"].cast<int>();
	_maxScore = data["MaxScore"].cast<int>();
	_comboPoints = data["ComboPoints"].cast<int>();
	_comboTime = data["ComboTime"].cast<float>();
}

void ScoreManagerComponent::update() 
{
	if (_actualComboSequenceTime + _comboTime <= _engineTime->deltaTime()) {
		addTotalComboScore();
	}
}

void ScoreManagerComponent::start()
{
	_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
}

inline void ScoreManagerComponent::addComboHitPoint()
{
	++_comboPoints;
	startOrRenewComboTime();
}

inline void ScoreManagerComponent::addComboDeathPoint(int deathPoints)
{
	_comboPoints += deathPoints;
	startOrRenewComboTime();
}

void ScoreManagerComponent::addTotalComboScore()
{
	//PONER BIEN LA FUNCI�N DE C�LCULO -> REVISAR GDD O PREGUNTAR SI NO EST� CLARO
	_score += (_comboPoints * _lvlManager->getCurrentLevel());
}

void ScoreManagerComponent::startOrRenewComboTime()
{
	_actualComboSequenceTime = _engineTime->deltaTime();
	if (!_isComboSequence) _isComboSequence = true;
}

void ScoreManagerComponent::clearComboSequence()
{
	_comboPoints = 0;
	_isComboSequence = false;
}

