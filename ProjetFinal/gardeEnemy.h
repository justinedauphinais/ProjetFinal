/*******************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: gardeEnemy.h																	*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"

class gardeEnemy : public entity {
public:
	gardeEnemy(gameDataRef data, float posX, float posY);

	void update(float dt);

	void attack();
};