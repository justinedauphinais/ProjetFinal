#include "mainWalls.h"

wall::wall(gameDataRef data, int nbrWall) : _data(data)
{
	// Cr�ation des murs de la pi�ce
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

void wall::draw() const
{
	for (int i = 1; i < _wallSprites.size(); i++)
		_data->window.draw(_wallSprites.at(i));
}

void wall::drawBackWall() const
{
	_data->window.draw(_wallSprites.at(0));
}

const vector<Sprite>& wall::getSprites() const
{
	return _wallSprites;
}

const Sprite& wall::getWallUp() const
{
	return _wallSprites[0];
}

const Sprite& wall::getWallDown() const
{
	return _wallSprites[1];
}

const Sprite& wall::getWallLeft() const
{
	return _wallSprites[2];
}

const Sprite& wall::getWallRight() const
{
	return _wallSprites[3];
}

