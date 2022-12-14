/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: entity.h																		*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include "drawable.h"

class entity : public drawable {
protected:
	int _animationIterator;
	vector<Texture> _animationFramesWalkingRight;
	vector<Texture> _animationFramesWalkingLeft;
	vector<Texture> _animationFramesFightingRight;
	vector<Texture> _animationFramesFightingLeft;
	vector<Texture> _animationFramesIdleRight;
	vector<Texture> _animationFramesIdleLeft;
	vector<Texture> _animationFramesDamagedLeft;
	vector<Texture> _animationFramesDamagedRight;
	vector<Texture> _animationFramesDyingLeft;
	vector<Texture> _animationFramesDyingRight;

	entityStates _state;
	directions _dir;

	int _nbrLives;
	int _totalLives;

	bool _wasHit;
	bool _hit;
	bool _dead;

	Clock _attackClock;

public:
	int getNbrLives() const;
	entityStates getState() const;
	directions getDirection() const;
	bool getWasHit() const;
	bool getHit() const;

	void setState(entityStates state);
	void setWasHit(bool value, int nbLives = 0);
	void setHit(bool value);

	void move(Keyboard::Key key, float time);
	bool move(Vector2f distance, float time, float hitDistanceX, float hitDistanceY);
};