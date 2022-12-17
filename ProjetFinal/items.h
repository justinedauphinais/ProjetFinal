#pragma once

#include "drawable.h"

class item : public drawable {
private:
	itemTypes itemType;
	Text _priceText;
	int _price;

	bool _bought;

public:
	item(gameDataRef data, itemTypes itemType);
	item(gameDataRef data, itemTypes itemType, float posX, float posY);

	void wasBought();
	bool isBought() const;

	int getPrice() const;
	void draw()const;
};