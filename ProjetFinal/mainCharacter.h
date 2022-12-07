#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"

using namespace sf;

class mainCharacter : public entity {
private:
	gameDataRef _data;

	int _animationIterator;

	Clock _movementClock;

public:
	mainCharacter(gameDataRef data, int nbrVies = NBR_LIVES);

	void animate(float dt);
	void update(float dt);

	void attack();

	void draw() const;
};