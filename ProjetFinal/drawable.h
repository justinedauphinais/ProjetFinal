/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: drawable.h																	*
* Date		: 21/12/2022																	*
* Description : Classe parent pour tous les objets qui vont être affichés à la fenêtre.		*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

class drawable {
protected:
	gameDataRef _data;
	
	Sprite _sprite;

	Clock _clock;

public:
	Sprite getSprite() const;

	void setPosition(float x, float y);

	void draw()const;
};