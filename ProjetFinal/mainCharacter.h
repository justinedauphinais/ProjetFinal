/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: mainCharacter.h																*
* Date		: 21/12/2022																	*
* Description : Classe enfant de entity, controllée par le joueur. 							*
*********************************************************************************************/
#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"

using namespace sf;

class mainCharacter : public entity {
private:
	Clock _movementClock;

	SoundBuffer _stepBuffer;
	Sound _stepSound;

public:
	mainCharacter(gameDataRef data, int nbrVies = NBR_LIVES);

	void update(float dt);

	void attack();
};