#pragma once
#ifndef SCOREMANAGERCOMPONENT_H
#define SCOREMANAGERCOMPONENT_H

#include "Component.h"

class ScoreManagerComponent : public Component	
{
public:
	
	ScoreManagerComponent();
	~ScoreManagerComponent();

	/// <summary>
	/// Adds amount points to the current score
	/// </summary>
	/// <param name="amount">The amount we add to the score</param>
	inline void addScore(int amount) { _score += amount; }

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
	/// Sets the maxScore
	/// </summary>
	/// <param name="maxScore">New maxScore value</param>
	inline void setMaxScore(int maxScore) { _maxScore = maxScore; }

	/// <summary>
	/// Returns the current maxScore
	/// </summary>
	inline int getMaxScore() const { return _maxScore; }

private:

	int _score;
	int _maxScore;	
};
#endif // !SCOREMANAGERCOMPONENT_H

