#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

enum doorState {
	CLOSED,
	OPENED
};

class door {
private:
	gameDataRef _data;

	Sprite _sprite;

	doorState _state;

public:
	door(gameDataRef data, doorState state = CLOSED);
	~door();

	void openDoor();

	doorState getState() const;
	Sprite getSprite() const;

	void draw() const;
};