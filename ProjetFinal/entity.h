/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: entity.h																		*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

class entity {
protected:
	gameDataRef _data;

	Sprite _sprite;

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

	Clock _clock;

public:
	Sprite getSprite() const;
	int getNbrLives() const;
	entityStates getState() const;

	void setState(entityStates state);
	void setPosition(float x, float y);

	void move(Keyboard::Key key, float time);

	void draw()const;
};