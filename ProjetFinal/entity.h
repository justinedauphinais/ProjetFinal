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
private:
	gameDataRef _data;

	Sprite _sprite;

	vector<Texture> _animationFramesWalkingRight;
	vector<Texture> _animationFramesWalkingLeft;
	int _animationIterator;

	entityStates _state;

	int _nbrVies;

	Clock _clock;

public:
	entity(gameDataRef data);

	Sprite getSprite() const;

	void move(Keyboard::Key key);
	
	void draw() const;
};