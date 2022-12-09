/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: gameOverState.h																*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "gameState.h"
#include <iostream>
#include <fstream>

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

	int _color;				// Couleur du texte qui appara�t
	int _score;				// Score de l'utilisateur
	bool _gagne;			// Si utilisateur a gagne ou pas

	Text _vousEtesText;		// Les diff�rents textes
	Text _outcomeText;
	Text _scoreText;
	Text _highScoreText;

	Clock _clock;			// Horloge pour calculer le temps avant de faire appara�tre les scores

public:
	gameOverState(gameDataRef data, int score, bool gagne);	// Constructeur
	~gameOverState();										// Destructeur

	void init();					// Initilise les variables

	void handleInput();				// R�agit aux inputs de l'utilisateur
	void update(float dt);			// Mets-�-jour les objets 

	void draw(float dt) const;		// Clear, dessine le background et display la fen�tre
};