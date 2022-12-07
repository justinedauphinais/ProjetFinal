#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "state.hpp"
#include "game.h"
#include "gameState.h"
#include "mainWalls.h"
#include "hud.h"

/// <summary>
/// 
/// </summary>
class shopState : public state {
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
							// donne accès au stateMachine, au RenderWindow, au
							// assertManager et au inputManager

	Sprite _background;			// Le sprite pour la background

	wall* _wall;					// Les murs
	door* _door;					// La porte
	hud* _hud;						// Le hud
	mainCharacter* _mainCharacter;	// Le personnage principal
	shopOwner* _shopOwner;

	collision _collision;

	int _gameState;
	int _moveX;
	int _moveY;

public:
	shopState(gameDataRef data, hud*& hud);
	~shopState();

	void init();

	void handleInput();
	void update(float dt);

	void draw(float dt) const;
};