#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "items.h"
#include "drawable.h"



class inventaire : public drawable
{

protected:
	
	Clock _clock;
	vector<item>_items;
public:

	inventaire(gameDataRef data);
	void addItem(item item);
	void removeItem(item item);
	void draw()const;

};
