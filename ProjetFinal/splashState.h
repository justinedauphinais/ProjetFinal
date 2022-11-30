#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include <iostream>
#include "mainMenuState.h"

using namespace sf;
using namespace std;
// Chaque state repr�sentera une vraie fen�tre et h�rite de state, car on impl�mentera
// un init, update, draw et handleInput diff�rent pour chaque fen�tre.
class splashState : public state
{
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
	// donne acc�s au stateMachine, au RenderWindow, au
	// assertManager et au inputManager

	Clock _clock;			// 1re fen�tre a besoin d�une clock car elle disparait
	// au bout de quelques secondes

	Sprite _background;		// Le sprite pour la background

public:
	splashState(gameDataRef data);
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt) const;
};