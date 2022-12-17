#include "items.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
/// <param name="itemType"></param>
item::item(gameDataRef data, itemTypes itemType)
{
	_data = data;
	_bought = false;

	if (itemType == bigLifePotion) {
		_price = PRICE_BIG_LIFE_POTION;
		_priceText = Text(to_string(_price), _data->assets.getFont("pixel art font"), 20);
		_priceText.setFillColor(Color::White);
		_priceText.setPosition((SCREEN_WIDTH - _sprite.getGlobalBounds().width - 60), 20);
		_sprite.setTexture(_data->assets.getTexture("big life potion"));
		_sprite.setScale(5.5f, 5.5f);
	}
	else if (itemType == smallLifePotion) {
		_price = PRICE_SMALL_LIFE_POTION;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
/// <param name="itemType"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
item::item(gameDataRef data, itemTypes itemType, float posX, float posY)
{
	_data = data;
	_bought = false;

	if (itemType == bigLifePotion) {
		_price = PRICE_BIG_LIFE_POTION;	_priceText = Text(to_string(_price), _data->assets.getFont("pixel art font"), 20);
		_priceText.setFillColor(Color::White);
		_priceText.setPosition((SCREEN_WIDTH / 2) - (_sprite.getGlobalBounds().width),60);
		_sprite.setTexture(_data->assets.getTexture("big life potion"));
		_sprite.setScale(5.5f, 5.5f);
	}
	else if (itemType == smallLifePotion) {
		_price = PRICE_SMALL_LIFE_POTION;
	}

	_sprite.setPosition(posX, posY);
}

/// <summary>
/// 
/// </summary>
void item::wasBought()
{
	_bought = true;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
bool item::isBought() const
{
	return _bought;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int item::getPrice() const
{
	return _price;
}

void item::draw() const
{
	_data->window.draw(_priceText);
}
