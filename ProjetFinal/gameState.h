/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: gameState.h																	*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
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
#include "gardeEnemy.h"
#include "gameOverState.h"
#include "minotaur.h"
#include "shopOwner.h"
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

	Sprite _background;			// Le sprite pour la background

	wall* _wall;					// Les murs
	door* _door;					// La porte
	hud* _hud;						// Le hud
	mainCharacter* _mainCharacter;	// Le personnage principal
	gardeEnemy* _garde;
	minotaur* _minotaur;

	collision _collision;
	Clock _clock;
	int _gameState;
	bool _toucher = false;
	
public:
	gameState(gameDataRef data);
	gameState(gameDataRef data, hud*& hud);
	~gameState();

	void init();

	void handleInput();
	void update(float dt);

	void draw(float dt) const;
};