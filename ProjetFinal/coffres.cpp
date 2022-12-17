#include "coffres.h"

coffres::coffres(gameDataRef data, coffresEtat state)
{
	_state = state;

	if (_state == Closed) {
		_sprite.setTexture(_data->assets.getTexture("coffres close"));
	}
	else {
		_sprite.setTexture(_data->assets.getTexture("coffres open"));
	}

	_sprite.setScale(5.0, 5.0);
	_sprite.setPosition(SCREEN_WIDTH / 2 - _sprite.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - _sprite.getGlobalBounds().height / 2);
}

coffres::~coffres()
{

}

void coffres::openCoffre()
{
	_state = Opened;
	_sprite.setTexture(_data->assets.getTexture("opened door"));
}

coffresEtat coffres::getState() const
{
	return _state;
}

Sprite coffres::getSprite() const
{
	return _sprite;
}

void coffres::draw() const
{
	_data->window.draw(_sprite);
}
