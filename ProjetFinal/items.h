/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: items.h																		*
* Date		: 21/12/2022																	*
* Description : Item pouvant être obtenu par le joueur pour augmenter sa vie.				*
*********************************************************************************************/
#pragma once

#include "drawable.h"

class item : public drawable {
private:
	itemTypes itemType;
	Text _priceText;
	int _price;

	bool _bought;

	int _effect;

public:
	item(gameDataRef data, itemTypes itemType);
	item(gameDataRef data, itemTypes itemType, float posX, float posY);

	void wasBought();
	bool isBought() const;

	int getPrice() const;

	int getEffect() const;
};