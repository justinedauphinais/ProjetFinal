#include "hearts.h"

/// <summary>
/// Constructeur par défaut
/// </summary>
hearts::hearts(gameDataRef data) : _data(data)
{
	_heart = Sprite(_data->assets.getTexture("life hearts"));
	_heart.setPosition(50, 50);
	_heart.setScale(4, 4);
}

/// <summary>
/// 
/// </summary>
/// <param name="nb"></param>
hearts::hearts(gameDataRef data, int nb) : _data(data)
{
	_heart = Sprite(_data->assets.getTexture("life hearts"));
	_heart.setPosition(50, 50);
	_heart.setScale(4, 4);

	for (int i = 0; i < nb; i++) {
		_hearts.push_back(_heart);
		_heart.move(80, 0);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="nb"></param>
/// <returns></returns>
bool hearts::removeHeart(int nb)
{
	for (int i = 0; i < nb; i++) {
		_hearts.pop_back();
		_heart.move(-80, 0);
	}

	return _hearts.size() == 0;
}

/// <summary>
/// 
/// </summary>
/// <param name="nb"></param>
void hearts::addHeart(int nb)
{
	for (int i = 0; i < nb; i++) {
		_hearts.push_back(_heart);
		_heart.move(80, 0);
	}
}

/// <summary>
/// 
/// </summary>
void hearts::draw() const
{
	for (int i = 0; i < _hearts.size(); i++) {
		_data->window.draw(_hearts[i]);
	}
}
