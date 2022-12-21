/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: door.h																		*
* Date		: 21/12/2022																	*
* Description : Porte qui permet de passer à la prochaine salle	lorsqu'elle est				*
				débarrée.																	*
*********************************************************************************************/
#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include <iostream>

enum doorState {
	CLOSED,
	OPENED
};

class door {
private:
	gameDataRef _data;
	Sprite _sprite;

	doorState _state;

	SoundBuffer _openDoorBuffer;	// Son porte ouvre
	Sound _openDoorSound;

public:
	door(gameDataRef data, doorState state = CLOSED, int nbr = 1);

	void openDoor();

	doorState getState() const;		// Retourne state
	Sprite getSprite() const;		// Retourne sprite

	void draw() const;
};