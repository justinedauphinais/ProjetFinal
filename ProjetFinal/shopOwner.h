/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: shopOwner.h																	*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"

using namespace sf;

class shopOwner : public entity {
private:
	int _animationIterator;

	Clock _clock;

public:
	shopOwner(gameDataRef data);

	void update(float dt);
};