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
#include "gameOverState.h"
#include "minotaur.h"

using namespace sf;
using namespace std;

// Chaque state représentera une vraie fenêtre et hérite de state, car on implémentera
// un init, update, draw et handleInput différent pour chaque fenêtre.
class bossRoomState : public state {
private:
	gameDataRef _data;		// Chaque state recevra le pointeur sur la gameData qui
							// donne accès au stateMachine, au RenderWindow, au
							// assertManager et au inputManager

	Sprite _background;			// Le sprite pour la background

	wall* _wall;					// Les murs
	hud* _hud;						// Le hud
	mainCharacter* _mainCharacter;	// Le personnage principal
	minotaur* _minotaur;			// Le minotaur (boss)

	vector<Sprite> _lstSprites;		// Liste des sprites

	collision _collision;
	Clock _clock;

	int _gameState;
	int _moveX;
	int _moveY;

	bool _hit;
	bool _wasHit;

	SoundBuffer _enemyDeadBuffer;
	SoundBuffer _enemyHitBuffer;
	SoundBuffer _MCHitBuffer;

	Sound _enemyDeadSound;
	Sound _enemyHitSound;
	Sound _MCHitSound;

public:
	bossRoomState(gameDataRef data, hud*& hud);
	~bossRoomState();

	void init();

	void handleInput();
	void update(float dt);

	void draw(float dt) const;
};