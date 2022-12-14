#include "door.h"

/// <summary>
/// 
/// </summary>
/// <param name="state"></param>
door::door(gameDataRef data, doorState state, int nbr) : _data(data)
{
	_state = state;

	if (_state == CLOSED) {
		_sprite.setTexture(_data->assets.getTexture("closed door " + to_string(nbr)));
	}
	else {
		_sprite.setTexture(_data->assets.getTexture("opened door"));
	}

	_sprite.setScale(5.0, 5.0);
	_sprite.setPosition((SCREEN_WIDTH / 2) - (_sprite.getGlobalBounds().width / 2), 0);
}

/// <summary>
/// 
/// </summary>
door::~door()
{
}

/// <summary>
/// 
/// </summary>
void door::openDoor()
{
	_state = OPENED;
	_sprite.setTexture(_data->assets.getTexture("opened door"));
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
doorState door::getState() const
{
	return _state;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
Sprite door::getSprite() const
{
	return _sprite;
}

/// <summary>
/// 
/// </summary>
void door::draw() const
{
	_data->window.draw(_sprite);
}