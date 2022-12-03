#include "mainWalls.h"

wall::wall(gameDataRef data) : _data(data)
{

}

void wall::spawnLeftWall()
{
	Sprite sprite(_data->assets.getTexture("wall left"));
	sprite.setPosition( 0, 0 );
	_wallSprite.push_back(sprite);
}

void wall::spawnRightWall() {
	Sprite sprite(_data->assets.getTexture("wall right"));
	sprite.setPosition(_data->window.getSize().x - sprite.getGlobalBounds().width, 0);
	_wallSprite.push_back(sprite);
}

void wall::spawnDownWall() {
	Sprite sprite(_data->assets.getTexture("wall down"));
	sprite.setPosition(47, _data->window.getSize().y - sprite.getGlobalBounds().height - 20);
	_wallSprite.push_back(sprite);
}

void wall::spawnUpWall() {
	Sprite sprite(_data->assets.getTexture("wall up"));
	sprite.setPosition(47, 0);
	_wallSprite.push_back(sprite);
}

void wall::draw()
{
	for (list<Sprite>::iterator it = _wallSprite.begin(); it != _wallSprite.end(); it++)
		_data->window.draw(*it);
}

list<Sprite>& wall::getSprites()
{
	return _wallSprite;
}
