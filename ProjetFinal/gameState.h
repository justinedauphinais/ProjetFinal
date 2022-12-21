/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: gameState.h																	*
* Date		: 21/12/2022																	*
* Description : Gestion des différentes salles (rooms). Contient les ennemis, le MC, les	*
				murs, la porte, etc. Gère les collisions du player.							*
*********************************************************************************************/
#pragma once

#include <SFML/Audio.hpp>
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
#include "shopState.h"
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
	Sprite _key;

	wall* _wall;					// Les murs
	door* _door;					// La porte
	hud* _hud;						// Le hud
	mainCharacter* _mainCharacter;	// Le personnage principal
	
	vector<gardeEnemy> _gardes;		// Vecteur des gardes

	vector<Sprite> _lstSprites;		// Liste des sprites
	
	collision _collision;
	Clock _clock;

	int _gameState;
	int _moveX;
	int _moveY;

	bool _hasKey;
	bool _hit;
	bool _wasHit;

	SoundBuffer _enemyDeadBuffer;
	SoundBuffer _enemyHitBuffer;
	SoundBuffer _MCHitBuffer;

	Sound _enemyDeadSound;
	Sound _enemyHitSound;
	Sound _MCHitSound;
	
public:
	gameState(gameDataRef data);
	gameState(gameDataRef data, hud*& hud);
	~gameState();

	void init();

	void handleInput();
	void update(float dt);

	void draw(float dt) const;
};