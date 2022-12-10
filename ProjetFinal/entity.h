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

	entityStates _state;
	directions _dir;

	int _nbrLives;

public:
	int getNbrLives() const;
	entityStates getState() const;

	void setState(entityStates state);

	void move(Keyboard::Key key, float time);
};