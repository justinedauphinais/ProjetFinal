#include "drawable.h"

/// <summary>
/// 
/// </summary>
/// <returns></returns>
Sprite drawable::getSprite() const
{
	return _sprite;
}

/// <summary>
/// 
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void drawable::setPosition(float x, float y)
{
	_sprite.setPosition(x, y);
}

/// <summary>
/// 
/// </summary>
void drawable::draw() const
{
	_data->window.draw(_sprite);
}
