#include "items.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
/// <param name="itemType"></param>
item::item(gameDataRef data, itemTypes itemType)
{
	_data = data;
	_bought = false;

	if (itemType == bigLifePotion) {		// Si est une grosse potion 
		_price = PRICE_BIG_LIFE_POTION;
		_priceText = Text(to_string(_price), _data->assets.getFont("pixel art font"), 20);
		_priceText.setFillColor(Color::White);
		_priceText.setPosition((SCREEN_WIDTH - _sprite.getGlobalBounds().width - 60), 20);
		_sprite.setTexture(_data->assets.getTexture("big life potion"));
		_sprite.setScale(5.5f, 5.5f);
		_effect = 3;
	}
}

/// <summary>
/// Constructeur avec position
/// </summary>
/// <param name="data"></param>
/// <param name="itemType"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
item::item(gameDataRef data, itemTypes itemType, float posX, float posY)
{
	_data = data;
	_bought = false;

	if (itemType == bigLifePotion) {		// Si est une grosse potion 
		_price = PRICE_BIG_LIFE_POTION;	_priceText = Text(to_string(_price), _data->assets.getFont("pixel art font"), 20);
		_priceText.setFillColor(Color::White);
		_priceText.setPosition((SCREEN_WIDTH / 2) - (_sprite.getGlobalBounds().width),60);
		_sprite.setTexture(_data->assets.getTexture("big life potion"));
		_sprite.setScale(5.5f, 5.5f);
		_effect = 3;
	}

	_sprite.setPosition(posX, posY);
}

/// <summary>
/// Valide que l'item a été acheté
/// </summary>
void item::wasBought()
{
	_bought = true;
}

/// <summary>
/// Retourne si a été acheté 
/// </summary>
/// <returns></returns>
bool item::isBought() const
{
	return _bought;
}

/// <summary>
/// Retourne le prix
/// </summary>
/// <returns></returns>
int item::getPrice() const
{
	return _price;
}

/// <summary>
/// Retourne l'effet de l'item
/// </summary>
/// <returns></returns>
int item::getEffect() const
{
	return _effect;
}