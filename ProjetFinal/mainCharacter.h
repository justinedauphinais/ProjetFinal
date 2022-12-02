#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

class mainCharacter {
private:
	gameDataRef _data;

	Sprite _skeletonSprite;

	vector<Texture> _animationFramesWalkingRight;
	vector<Texture> _animationFramesWalkingLeft;
	int _animationIterator;

	directions _dir;

	Clock _clock;

	Clock _movementClock;

public:
	mainCharacter(gameDataRef data);

	Sprite getSprite() const;

	void animate(float dt);
	void move(directions dir);

	void draw() const;
};