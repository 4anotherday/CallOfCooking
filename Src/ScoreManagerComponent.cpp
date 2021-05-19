#include "ScoreManagerComponent.h"
#include "UserComponentIDs.h"
#include "GameObject.h"
#include "includeLUA.h"
#include "Engine.h"
#include "EngineTime.h"
#include "LevelManagerComponent.h"
#include "UIManagerComponent.h"
#include "includeLUA.h"


ADD_COMPONENT(ScoreManagerComponent);

ScoreManagerComponent::ScoreManagerComponent(): Component(UserComponentId::ScoreManagerComponent),
	_score(0),_maxScore(0), _comboHitPoints(0), _comboDeathPoints(0), _comboTime(0.0f), _actualComboSequenceTime(0.0f), 
	_engineTime(EngineTime::getInstance()), _isComboSequence(false), _lvlManager(), _time(0.0f), _uimanager(nullptr), _gameOver(false)
{
}

ScoreManagerComponent::~ScoreManagerComponent()
{
}

void ScoreManagerComponent::awake(luabridge::LuaRef& data)
{
	if(LUAFIELDEXIST(Score)) _score = data["Score"].cast<int>();
	if(LUAFIELDEXIST(MaxScore)) _maxScore = data["MaxScore"].cast<int>();
	if(LUAFIELDEXIST(ComboTime)) _comboTime = data["ComboTime"].cast<float>();
}

void ScoreManagerComponent::update() 
{
	_time += _engineTime->deltaTime();
	if (_isComboSequence && (_actualComboSequenceTime + _comboTime <= _time)) {
		addTotalComboScore();
	}
}

void ScoreManagerComponent::start()
{
	_lvlManager = static_cast<LevelManagerComponent*>(Engine::getInstance()->findGameObject("GameManager")->getComponent(UserComponentId::LevelManagerComponent));
	_uimanager = static_cast<UIManagerComponent*>(Engine::getInstance()->findGameObject("UIManager")->getComponent(UserComponentId::UIManagerComponent));
	_uimanager->setPlayerScore(_score);
	_uimanager->setFinalPanelScore(_score);
}

void ScoreManagerComponent::addComboHitPoint()
{
	++_comboHitPoints;
	startOrRenewComboTime();
}

void ScoreManagerComponent::addComboDeathPoint(int deathPoints)
{
	_comboDeathPoints += deathPoints * ((_lvlManager->getCurrentLevel() / 10) + 1);
	startOrRenewComboTime();
}

void ScoreManagerComponent::gameOver()
{
	addTotalComboScore();
	_gameOver = true;
}

void ScoreManagerComponent::reset()
{
	_score = 0;
	clearComboSequence();
}

void ScoreManagerComponent::addTotalComboScore()
{
	if (!_gameOver) {
		_isComboSequence = false;

		//Adding combo hit extra points
		int totalPoints = ((_comboHitPoints / 20) + 1) * 5;

		//Adding combo death extra points
		totalPoints += _comboDeathPoints;

		//Adding multiplier extra points
		float multiplier = 0.1f * ((_comboHitPoints + _comboDeathPoints) / 10);
		float multiplierExtraPoints = totalPoints * multiplier;

		totalPoints += int(multiplierExtraPoints);

		_score += totalPoints;
		_uimanager->setPlayerScore(_score);
		_uimanager->setFinalPanelScore(_score);

		clearComboSequence();
	}
}

void ScoreManagerComponent::startOrRenewComboTime()
{
	_actualComboSequenceTime = _time;
	if (!_isComboSequence) _isComboSequence = true;
}

void ScoreManagerComponent::clearComboSequence()
{
	_comboHitPoints = 0;
	_comboDeathPoints = 0;
	_isComboSequence = false;
}

