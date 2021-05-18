#pragma once
#ifndef SCOREMANAGERCOMPONENT_H
#define SCOREMANAGERCOMPONENT_H

#include "Component.h"
class EngineTime;
class LevelManagerComponent;
class UIManagerComponent;

class ScoreManagerComponent : public Component	
{
public:
	
	ScoreManagerComponent();
	~ScoreManagerComponent();

	virtual void awake(luabridge::LuaRef& data);

	virtual void update() override;

	virtual void start() override;

	/// <summary>
	/// Adds amount points to the current score
	/// </summary>
	/// <param name="amount">The amount we add to the score</param>
	inline void addScore(int amount) { _score += amount; }

	/// <summary>
	/// Adds a combo point for for hitting an enemy	
	//  Eevery 20 hits, player will receive 5 extra points
	/// </summary>
	void addComboHitPoint();

	/// <summary>
	/// Adds combo points for for killing an enemy
	//  Each fruit will give the same number of points as the lives it has.Every 10 rounds, increase the points each fruit gives by the sum of itself.
	/// </summary>
	/// <param name="deathPoints">How many combo points for getting a kill</param>
	void addComboDeathPoint(int deathPoints);

	/// <summary>
	/// Performs the calculation of points related to the active combo sequence
	/// Every 10x combo, a multiplier will be added that will increase the points the player has made in the duration of his combo
	/// </summary>
	void addTotalComboScore();


	void gameOver();

	/// <summary>
	/// Retuns the current score
	/// </summary>
	inline int getScore() const { return _score; }

	/// <summary>
	/// Sets the score to 0
	/// </summary>
	inline void resetScore() { _score = 0; }

	/// <summary>
	/// Sets the score to a new value
	/// </summary>
	/// <param name="newScore">New score value</param>
	inline void setScore(int newScore) { _score = newScore; }

	/// <summary>
	/// Sets how long the combo sequence will last
	/// </summary>
	/// <param name="cT">New comboTime value</param>
	inline void setComboTime(float cT) { _comboTime = cT; }

	/// <summary>
	/// Sets the maxScore
	/// </summary>
	/// <param name="maxScore">New maxScore value</param>
	inline void setMaxScore(int maxScore) { _maxScore = maxScore; }

	/// <summary>
	/// Returns the current maxScore
	/// </summary>
	inline int getMaxScore() const { return _maxScore; }

private:
	/// </summary>
	/// Renews or start the timing of the current combo sequence
	/// </summary>
	void startOrRenewComboTime();


	/// </summary>
	/// Reset the attributes related to the combo sequence
	/// </summary>
	void clearComboSequence();

	LevelManagerComponent* _lvlManager;
	UIManagerComponent* _uimanager;

	int _score;
	int _maxScore;	

	EngineTime* _engineTime;
	bool _isComboSequence;
	int _comboDeathPoints;
	int _comboHitPoints;
	float _comboTime;
	float _actualComboSequenceTime;
	float _time;
};
#endif // !SCOREMANAGERCOMPONENT_H

