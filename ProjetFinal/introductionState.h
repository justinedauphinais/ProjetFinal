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
class introductionState: public state
{
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
	// donne acc�s au stateMachine, au RenderWindow, au
	// assertManager et au inputManager

	int _color;				// Couleur du texte qui appara�t
	bool intro;				// Si utilisateur a gagne ou pas

	Text _titreText;		// Les diff�rents textes
	Text _introparagragh1Text;
	Text _introparagragh2Text;
	Text _introparagragh3Text;
	Text _introparagragh4Text;
	Text _introparagragh5Text;
	Text _introparagragh6Text;
	Text _introparagragh7Text;

	Sprite _suivantButton;		// Le sprite du bouton suivant



	Clock _clock;			// Horloge pour calculer le temps avant de faire appara�tre les scores

public:
	introductionState(gameDataRef data);	// Constructeur
	~introductionState();										// Destructeur

	void init();					// Initilise les variables

	void handleInput();				// R�agit aux inputs de l'utilisateur
	void update(float dt);			// Mets-�-jour les objets 

	void draw(float dt) const;		// Clear, dessine le background et display la fen�tre
};
