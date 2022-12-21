#include "drawable.h"

/// <summary>
/// Retourne le sprite
/// </summary>
/// <returns></returns>
Sprite drawable::getSprite() const
{
	return _sprite;
}

/// <summary>
/// Set la position
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void drawable::setPosition(float x, float y)
{
	_sprite.setPosition(x, y);
}

/// <summary>
/// Dessine le sprite dans la fenêtre
/// </summary>
void drawable::draw() const
{
	_data->window.draw(_sprite);
}