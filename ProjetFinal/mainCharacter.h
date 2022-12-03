#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"

using namespace sf;

class mainCharacter : public entity {
private:
	gameDataRef _data;

	vector<Texture> _animationFramesIdle;

	int _animationIterator;

	Clock _movementClock;

public:
	mainCharacter(gameDataRef data);

	void animate(float dt);
	void idle(float dt);

	void attack(float dt);

	void draw() const;
};