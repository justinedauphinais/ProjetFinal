#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

enum mainCharacterStates {
	WALKING,
	IDLE
};

class mainCharacter {
private:
	gameDataRef _data;

	Sprite _skeletonSprite;

	vector<Texture> _animationFramesWalkingRight;
	vector<Texture> _animationFramesWalkingLeft;
	int _animationIterator;

	directions _dir;
	mainCharacterStates _state;

	Clock _clock;

	Clock _movementClock;

public:
	mainCharacter(gameDataRef data);

	Sprite getSprite() const;

	void animate(float dt);

	void move(directions dir);
	void idle();

	void draw() const;
};