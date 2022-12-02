#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include <iostream>

using namespace sf;
using namespace std;
// Chaque state repr�sentera une vraie fen�tre et h�rite de state, car on impl�mentera
// un init, update, draw et handleInput diff�rent pour chaque fen�tre.
class gameState : public state
{
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
	// donne acc�s au stateMachine, au RenderWindow, au
	// assertManager et au inputManager

	Sprite _background;		// Le sprite pour la background
	Sprite _foreground;		// Le sprite pour la background

public:
	gameState(gameDataRef data);
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt) const;
};