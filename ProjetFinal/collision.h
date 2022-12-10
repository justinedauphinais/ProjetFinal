/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: collision.h																	*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

class collision
{
public:
	bool checkSpriteCollision(Sprite sprite1, Sprite sprite2)const;
	bool checkSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2) const;
	bool checkSpriteCollision(Sprite sprite1, float scale1X, float scale1Y, Sprite sprite2, float scale2X, float scale2Y) const;
	Vector2f getDistance(Sprite sprite1, Sprite sprite2) const;
	float DistanceToEntity(const Vector2f& LocalPlayer, const Vector2f& Enemy);

};