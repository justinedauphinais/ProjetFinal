#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "mainCharacter.h"
#include "hearts.h"
#include "mainWalls.h"
#include <iostream>

using namespace sf;
using namespace std;

// Chaque state représentera une vraie fenêtre et hérite de state, car on implémentera
// un init, update, draw et handleInput différent pour chaque fenêtre.
class gameState : public state
{
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
							// donne accès au stateMachine, au RenderWindow, au
							// assertManager et au inputManager

	Sprite _background;		// Le sprite pour la background
	Sprite _foreground;		// Le sprite pour la background

	hearts* _hearts;
	wall* _wall;

	mainCharacter* _mainCharacter;	// Le personnage principal
	
public:
	gameState(gameDataRef data);
	~gameState();

	void init();

	void handleInput();
	void update(float dt);

	void draw(float dt) const;
};