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
	vector<Texture> _animationFramesAttack;

	int _animationIterator;

	Clock _movementClock;

public:
	mainCharacter(gameDataRef data);

	void animate(float dt);
	void update(float dt);

	void attack();

	void draw() const;
};