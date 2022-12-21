/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: minotaur.h																	*
* Date		: 21/12/2022																	*
* Description : Gestion du boss final du jeu.												*
*********************************************************************************************/
#pragma once

#include "entity.h"

class minotaur : public entity {
public:
	minotaur(gameDataRef data);

	void update(float dt);

	void attack(Vector2f distance);

	void move(Vector2f distance, float time, float hitDistanceX, float hitDistanceY);
};