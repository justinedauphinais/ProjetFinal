#include "mainCharacter.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
mainCharacter::mainCharacter(gameDataRef data) : _data(data)
{
	// Animations
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right1"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right2"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right3"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right4"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right5"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right6"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right7"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right8"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right9"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right10"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right11"));
	_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right12"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left1"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left2"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left3"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left4"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left5"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left6"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left7"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left8"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left9"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left10"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left11"));
	_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left12"));
	_animationIterator = 0;

	_skeletonSprite.setTexture(_animationFramesWalkingRight.at(_animationIterator));

	_skeletonSprite.setScale(5.0, 5.0);

	_skeletonSprite.setPosition((_data->window.getSize().x / 2) - (_skeletonSprite.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_skeletonSprite.getGlobalBounds().height / 2));

	// Directions
	_dir = directions::RIGHT;
	_state = mainCharacterStates::IDLE;
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

		_clock.restart();
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dir"></param>
void mainCharacter::move(directions dir)
{
	if (_clock.getElapsedTime().asSeconds() > SKELETON_WALK_TIME) {

		_animationIterator++;

		// Si on revient au début de la liste
		if (_animationIterator >= _animationFramesWalkingRight.size()) {
			_animationIterator = 0;
		}

		// Bouge le sprite
		if (dir == directions::RIGHT) {
			_skeletonSprite.move(20, 0);
			_skeletonSprite.setTexture(_animationFramesWalkingRight.at(_animationIterator));
		}
		else if (dir == directions::TOP) {
			_skeletonSprite.move(0, -20);
			_skeletonSprite.setTexture(_animationFramesWalkingRight.at(_animationIterator));
		}
		else if (dir == directions::LEFT) {
			_skeletonSprite.move(-20, 0);
			_skeletonSprite.setTexture(_animationFramesWalkingLeft.at(_animationIterator));
		}
		else if (dir == directions::BOTTOM) {
			_skeletonSprite.move(0, 20);
			_skeletonSprite.setTexture(_animationFramesWalkingLeft.at(_animationIterator));
		}

		_clock.restart();
	}
}

/// <summary>
/// 
/// </summary>
void mainCharacter::idle()
{
}

/// <summary>
/// 
/// </summary>
void mainCharacter::draw() const
{
	_data->window.draw(_skeletonSprite);
}