#include "cat.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
cat::cat(gameDataRef data)
{
	_data = data;
	
	_animationIterator = 0;
	_animationFramesIdleLeft.push_back(_data->assets.getTexture("cat 1"));
	_animationFramesIdleLeft.push_back(_data->assets.getTexture("cat 2"));
	_animationFramesIdleLeft.push_back(_data->assets.getTexture("cat 3"));

	_sprite.setTexture(_animationFramesIdleLeft[_animationIterator]);
	_sprite.setScale(5.0f, 5.0f);
	_sprite.setPosition(SCREEN_WIDTH / 2 + 100, 110);
}

/// <summary>
/// Mets à jour le sprite du chat
/// </summary>
/// <param name="dt"></param>
void cat::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > CAT_IDLE_TIME) {
		_animationIterator++;
		if (_animationIterator == _animationFramesIdleLeft.size()) { _animationIterator = 0; }
		_sprite.setTexture(_animationFramesIdleLeft[_animationIterator]);

		_clock.restart();
	}
}