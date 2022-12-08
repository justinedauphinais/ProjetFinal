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

// Chaque state représentera une vraie fenêtre et hérite de state, car on implémentera
// un init, update, draw et handleInput différent pour chaque fenêtre.
class gameOverState : public state
{
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
							// donne accès au stateMachine, au RenderWindow, au
							// assertManager et au inputManager

	int _color;				// Couleur du texte qui apparaît
	int _score;				// Score de l'utilisateur
	bool _gagne;			// Si utilisateur a gagne ou pas

	Text _vousEtesText;		// Les différents textes
	Text _outcomeText;
	Text _scoreText;
	Text _highScoreText;

	Clock _clock;			// Horloge pour calculer le temps avant de faire apparaître les scores

public:
	gameOverState(gameDataRef data, int score, bool gagne);	// Constructeur
	~gameOverState();										// Destructeur

	void init();					// Initilise les variables

	void handleInput();				// Réagit aux inputs de l'utilisateur
	void update(float dt);			// Mets-à-jour les objets 

	void draw(float dt) const;		// Clear, dessine le background et display la fenêtre
};