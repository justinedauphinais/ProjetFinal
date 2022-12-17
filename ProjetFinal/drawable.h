#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

class drawable {
protected:
	gameDataRef _data;
	
	Sprite _sprite;

	Clock _clock;

public:
	Sprite getSprite() const;

	void setPosition(float x, float y);

	void draw()const;
};