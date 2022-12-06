#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "gameState.h"
#include <iostream>

using namespace sf;
using namespace std;

// Chaque state représentera une vraie fenêtre et hérite de state, car on implémentera
// un init, update, draw et handleInput différent pour chaque fenêtre.
class gameOverState : public state
{
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
							// donne accès au stateMachine, au RenderWindow, au
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