/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: minotaur.h																	*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include "entity.h"

class minotaur : public entity {
public:
	minotaur(gameDataRef data);

	void update(float dt);

	void attack();

	void draw()const;
};