#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"
class enemys : public entity {
private:
	gameDataRef _data;

	int _animationIterator;



public:
	enemys(gameDataRef data);
	void update(float dt);
	void attack();
	void draw() const;
};
