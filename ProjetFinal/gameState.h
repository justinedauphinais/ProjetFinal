#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "mainCharacter.h"
#include "mainWalls.h"
#include "collision.h"
#include "hud.h"
#include "door.h"
#include "enemys.h"
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

	Sprite _background;			// Le sprite pour la background

	wall* _wall;					// Les murs
	hud* _hud;						// Le hud
	door* _door;					// La porte
	mainCharacter* _mainCharacter;	// Le personnage principal
	enemys* _enemys;
	collision _collision;

	int _gameState;
	
public:
	gameState(gameDataRef data);
	~gameState();

	void init();

	void handleInput();
	void update(float dt);

	void draw(float dt) const;
};