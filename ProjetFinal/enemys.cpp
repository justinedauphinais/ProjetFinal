
#include "enemys.h";

enemys::enemys(gameDataRef data) : _data(data)
{
	_animationIterator = 0;

	//idle right
	for (int  i = 1; i < 5; i++)
	{
		_animationFramesIdleRight.push_back(_data->assets.getTexture("enemy idle frame right" + to_string(i)));
	}
	//idle left
	for (int  i = 1; i < 5; i++)
	{
		_animationFramesIdleLeft.push_back(_data->assets.getTexture("enemy idle frame left" + to_string(i)));
	}
	//Attack left
	for (int i = 1; i < 6; i++)
	{
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("enemy attack frame left" + to_string(i)));
	}
	//Attack right
	for (int i = 1; i < 6; i++)
	{
		_animationFramesFightingRight.push_back(_data->assets.getTexture("enemy attack frame right" + to_string(i)));
	}

	_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));

	_sprite.setScale(5.0, 5.0);

	_sprite.setPosition((_data->window.getSize().x / 2) - (_sprite.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_sprite.getGlobalBounds().height / 2));
}

void enemys::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > ENEMY_IDLE_TIME / _animationFramesIdleLeft.size() && (_state == entityStates::IDLE)) {
		_animationIterator++;

		if (_animationIterator == _animationFramesIdleRight.size()) {
			_animationIterator = 0;
		}

		if (_dir == RIGHT || _dir == TOP) {
			_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));
		}
		else {
			_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator));
		}

		_clock.restart();
	}
}

void enemys::draw() const
{
	_data->window.draw(_sprite);
}


