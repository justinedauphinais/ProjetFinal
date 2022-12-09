/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: door.h																		*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

enum doorState {
	CLOSED,
	OPENED
};

class door {
private:
	gameDataRef _data;

	Sprite _sprite;

	doorState _state;

public:
	door(gameDataRef data, doorState state = CLOSED, int nbr = 1);
	~door();

	void openDoor();

	doorState getState() const;
	Sprite getSprite() const;

	void draw() const;
};