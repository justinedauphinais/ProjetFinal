/*******************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: gardeEnemy.h																	*
* Date		: 21/12/2022																	*
* Description : Ennemi qui poursuit le joueur lorsqu'il est assez proche. Attaque le		*
				joueur si celui-ci est à portée.											*
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
	void move(Vector2f distance, float time, float hitDistanceX, float hitDistanceY);
};