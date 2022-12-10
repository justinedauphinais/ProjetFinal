/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: shopState.h																	*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include "gameState.h"
#include "torch.h"
#include "cat.h"

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
	shopOwner* _shopOwner;			// Le NPC
	cat* _cat;

	Sprite _shopOwnerHiSprite;		// Dialogue du NPC

	vector<torch> _torches;

	vector<Sprite> _lstSprites;		// Liste des sprites

	collision _collision;

	int _gameState;
	int _moveX;
	int _moveY;

	bool _showDialogue;

	Clock _clock;

public:
	shopState(gameDataRef data, hud*& hud);
	~shopState();

	void init();

	void handleInput();
	void update(float dt);

	void draw(float dt) const;
};