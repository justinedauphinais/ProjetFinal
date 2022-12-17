/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: archerEnemy.h																	*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"

class archerEnemy : public entity {
public:
	archerEnemy(gameDataRef data, float posX, float posY);

	void update(float dt);

	void attack();
};