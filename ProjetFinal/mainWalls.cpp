#include "mainWalls.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
/// <param name="nbrWall"></param>
wall::wall(gameDataRef data, int nbrWall) : _data(data)
{
	// Création des murs de la pièce
	// Mur du haut
	Sprite sprite1(_data->assets.getTexture("wall up " + to_string(nbrWall)));
	sprite1.setPosition(47, 0);
	_wallSprites.push_back(sprite1);
	
	// Mur du bas
	Sprite sprite2(_data->assets.getTexture("wall down " + to_string(nbrWall)));
	sprite2.setPosition(47, _data->window.getSize().y - sprite2.getGlobalBounds().height - 20);
	_wallSprites.push_back(sprite2);

	// Mur de gauche
	Sprite sprite3(_data->assets.getTexture("wall left " + to_string(nbrWall)));
	sprite3.setPosition(0, 0);
	_wallSprites.push_back(sprite3);

	// Mur de droite
	Sprite sprite4(_data->assets.getTexture("wall right " + to_string(nbrWall)));
	sprite4.setPosition(_data->window.getSize().x - sprite4.getGlobalBounds().width, 0);
	_wallSprites.push_back(sprite4);

}

/// <summary>
/// Dessine dans la fenêtre
/// </summary>
void wall::draw() const
{
	for (int i = 1; i < _wallSprites.size(); i++)
		_data->window.draw(_wallSprites.at(i));
}

/// <summary>
/// Dessine le mur derrière
/// </summary>
void wall::drawBackWall() const
{
	_data->window.draw(_wallSprites.at(0));
}

/// <summary>
/// Retourne les sprites
/// </summary>
/// <returns></returns>
const vector<Sprite>& wall::getSprites() const
{
	return _wallSprites;
}

/// <summary>
/// Get le mur du haut
/// </summary>
/// <returns></returns>
const Sprite& wall::getWallUp() const
{
	return _wallSprites[0];
}

/// <summary>
/// Get le mur du bas
/// </summary>
/// <returns></returns>
const Sprite& wall::getWallDown() const
{
	return _wallSprites[1];
}

/// <summary>
/// Get le mur de gauche
/// </summary>
/// <returns></returns>
const Sprite& wall::getWallLeft() const
{
	return _wallSprites[2];
}

/// <summary>
/// Get le mur de droite
/// </summary>
/// <returns></returns>
const Sprite& wall::getWallRight() const
{
	return _wallSprites[3];
}