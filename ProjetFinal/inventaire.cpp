#pragma once
#include "Inventaire.h"

inventaire::inventaire(gameDataRef data)
{
	_data = data;
	_sprite.setTexture(_data->assets.getTexture("inventory"));
	_sprite.setScale(5.0f, 2.0f);
	_sprite.setPosition(48, (SCREEN_HEIGHT / 2) - (_sprite.getGlobalBounds().height / 2)+440);
}

void inventaire::addItem(item item)
{
	
	item.setPosition(_sprite.getPosition().x + 50, _sprite.getPosition().y + 40);
	_items.push_back(item);
	
}

void inventaire::removeItem(item item)
{	
	_items.pop_back();
}

void inventaire::draw() const
{
	_data->window.draw(_sprite);
	for (int i = 0; i < _items.size(); i++)
	{
		_data->window.draw(_items[i].getSprite());
	}
}

