#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"

using namespace sf;

class shopOwner : public entity {
private:
	gameDataRef _data;

	int _animationIterator;

	Clock _clock;

public:
	shopOwner(gameDataRef data);

	void update(float dt);

	void draw()const;
};