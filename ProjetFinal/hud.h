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
	
	vector<Sprite> _hearts;		// Les coeurs
	Sprite _heart;

public:
	hud(gameDataRef data, int score = 0, int nbCoeurs = NBR_LIVES);

	void setScore(int score);
	void addScore(int score = 1);

	bool removeHeart(int nb = 1);
	void addHeart(int nb = 1);

	int getScore() const;

	void draw() const;
};