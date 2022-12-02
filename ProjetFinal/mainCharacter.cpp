#include "mainCharacter.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
mainCharacter::mainCharacter(gameDataRef data)
{
	for (int i = 1; i <= 13; i++) 
		_animationFramesWalking.push_back(_data->assets.getTexture("skeleton walking frame" + i));

	_animationIterator = 0;

	_skeletonSprite.setTexture(_animationFramesWalking.at(_animationIterator));

	_skeletonSprite.setPosition((_data->window.getSize().x / 2) - (_skeletonSprite.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_skeletonSprite.getGlobalBounds().height / 2));
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
Sprite mainCharacter::getSprite() const
{
	return _skeletonSprite;
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void mainCharacter::animate(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > SKELETON_WALK_TIME) {
		_animationIterator++;
		if (_animationIterator >= _animationFramesWalking.size()) {
			_animationIterator = 0;
		}
		_skeletonSprite.setTexture(_animationFramesWalking.at(_animationIterator));
		_clock.restart();
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void mainCharacter::update(float dt)
{
}

/// <summary>
/// 
/// </summary>
void mainCharacter::draw() const
{
	_data->window.draw(_skeletonSprite);
}