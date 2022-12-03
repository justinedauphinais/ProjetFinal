#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

enum entityStates {
	WALKING,
	IDLE,
	ATTACKING,
	DYING,
	DEAD
};

class entity {
protected:
	Sprite _sprite;

	vector<Texture> _animationFramesWalkingRight;
	vector<Texture> _animationFramesWalkingLeft;
	int _animationIterator;

	entityStates _state;
	directions _dir;

	int _nbrLives;

	Clock _clock;

public:
	entity();

	Sprite getSprite() const;
	int getNbrLives() const;

	void move(Keyboard::Key key);
};