#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "gameState.h"
#include <iostream>

using namespace sf;
using namespace std;

// Chaque state repr�sentera une vraie fen�tre et h�rite de state, car on impl�mentera
// un init, update, draw et handleInput diff�rent pour chaque fen�tre.
class gameOverState : public state
{
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
							// donne acc�s au stateMachine, au RenderWindow, au
							// assertManager et au inputManager

	int _color;
	int _score;

	Text _youDiedText;
	Text _scoreText;
	Text _highScoreText;

	Clock _clock;

public:
	gameOverState(gameDataRef data, int score);
	~gameOverState();

	void init();

	void handleInput();
	void update(float dt);

	void draw(float dt) const;
};