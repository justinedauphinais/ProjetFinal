#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

enum coffresEtat {
	Closed,
	Opened
};

class coffres {
private:
	gameDataRef _data;

	Sprite _sprite;

	coffresEtat _state;

public:
	coffres(gameDataRef data, coffresEtat state = Closed);
	~coffres();

	void openCoffre();

	coffresEtat getState() const;
	Sprite getSprite() const;

	void draw() const;
};
