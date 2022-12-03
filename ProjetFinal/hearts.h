#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "game.h"

using namespace sf;
using namespace std;

class hearts {
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
							// donne accès au stateMachine, au RenderWindow, au
							// assertManager et au inputManager

	vector<Sprite> _hearts;
	Sprite _heart;

public:
	hearts(gameDataRef data);
	hearts(gameDataRef data, int nb);

	bool removeHeart(int nb = 1);
	void addHeart(int nb = 1);

	void draw() const;
};