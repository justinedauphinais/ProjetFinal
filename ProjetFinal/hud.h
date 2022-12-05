#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"

using namespace sf;

class hud {
private:
	gameDataRef _data;

	Text _scoreSprite;

	int _score;
	//int _money;

public:
	hud(gameDataRef data, int score = 0);

	void setScore(int score);
	void addScore(int score = 1);

	int getScore() const;

	void draw() const;
};