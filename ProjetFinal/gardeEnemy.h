#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"
class gardeEnemy : public entity {
private:
	gameDataRef _data;

	int _animationIterator;



public:
	gardeEnemy(gameDataRef data);
	void update(float dt);
	void attack();
	void draw() const;
};
