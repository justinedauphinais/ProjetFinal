/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: torch.h																		*
* Date		: 21/12/2022																	*
* Description : Objet décoratif qui se trouve dans le shopState.							*
*********************************************************************************************/
#pragma once

#include "drawable.h"

class torch : public drawable {
private:
	vector<Texture> _animation;
	int _animationIterator;

public:
	torch(gameDataRef data, float posX, float posY, int animationIterator);

	void update(float dt);
};