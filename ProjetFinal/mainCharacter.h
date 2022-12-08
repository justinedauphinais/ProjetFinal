/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: mainCharacter.h																*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"

using namespace sf;

class mainCharacter : public entity {
private:
	int _animationIterator;

	Clock _movementClock;

public:
	mainCharacter(gameDataRef data, int nbrVies = NBR_LIVES);

	void update(float dt);

	void attack();
};