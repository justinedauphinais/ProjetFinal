/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: cat.h																			*
* Date		: 21/12/2022																	*
* Description : Objet du chat dans le shopState. N'a pas d'effet particulier dans le jeu.	*
*********************************************************************************************/
#pragma once

#include "entity.h"

class cat : public entity {
public:
	cat(gameDataRef data);

	void update(float dt);
};