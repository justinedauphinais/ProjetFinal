#include "shopOwner.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
shopOwner::shopOwner(gameDataRef data) : _data(data)
{
	for (int i = 1; i <= 9; i++) {
		_animationFramesIdleRight.push_back(_data->assets.getTexture("store owner idle " + to_string(i)));
	}

	_sprite.setTexture(_animationFramesIdleRight[_animationIterator]);
	_sprite.setScale(6.0, 6.0);
	_sprite.setPosition(250, 250);
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void shopOwner::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > STOREOWNER_IDLE_TIME / _animationFramesIdleRight.size()) {
		_animationIterator++;

		if (_animationIterator == _animationFramesIdleRight.size()) {
			_animationIterator = 0;
		}
		
		_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));

		_clock.restart();
	}
}

/// <summary>
/// 
/// </summary>
void shopOwner::draw() const
{
	_data->window.draw(_sprite);
}