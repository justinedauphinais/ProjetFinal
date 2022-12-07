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
	int _nbrRoom;
	
	vector<Sprite> _hearts;		// Les coeurs
	Sprite _heart;

	Text _roomText;

public:
	hud(gameDataRef data, int nbrRoom, int score = 0, int nbCoeurs = NBR_LIVES);

	void setScore(int score);
	void addScore(int score = 1);

	bool removeHeart(int nb = 1);
	void addHeart(int nb = 1);

	void addRoom();

	int getScore() const;
	int getNbrVies() const;

	void draw() const;
};