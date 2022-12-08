/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: mainWalls.h																	*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <vector>
#include "game.h"

using namespace sf;

class wall
{

private:
	gameDataRef _data;
	vector<Sprite> _wallSprites;

public:
	wall(gameDataRef data, int nbrWall = 1);
	
	void draw() const;
	void drawBackWall() const;
	const vector<Sprite>& getSprites() const;

	const Sprite& getWallUp() const;
	const Sprite& getWallDown() const;
	const Sprite& getWallLeft() const;
	const Sprite& getWallRight() const;

};

