#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

class mainCharacter {
private:
	gameDataRef _data;

	Sprite _skeletonSprite;

	vector<Texture> _animationFramesWalking;
	int _animationIterator;

	Clock _clock;

	Clock _movementClock;

public:
	mainCharacter(gameDataRef data);

	Sprite getSprite() const;

	void animate(float dt);
	void update(float dt);

	void draw() const;
};