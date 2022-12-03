#include "mainCharacter.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
mainCharacter::mainCharacter(gameDataRef data) : _data(data)
{
	_nbrLives = NBR_LIVES;

	_animationIterator = 0;
	//Animation idle
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame1"));
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame2"));
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame3"));
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame4"));
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame5"));
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame6"));
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame7"));
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame8"));
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame9"));
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame10"));
	_animationFramesIdle.push_back(_data->assets.getTexture("skeleton idle frame11"));
	

	// Animations walks
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

	_sprite.setTexture(_animationFramesIdle.at(_animationIterator));

	_sprite.setScale(5.0, 5.0);

	_sprite.setPosition((_data->window.getSize().x / 2) - (_sprite.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_sprite.getGlobalBounds().height / 2));

	// Directions
	_dir = directions::RIGHT;
	_state = entityStates::IDLE;
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
/// create a animate character idle.
/// </summary>
void mainCharacter::idle(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > SKELETON_IDLE_TIME / _animationFramesIdle.size() && (_state == entityStates::IDLE))
	{
		if (_animationIterator < _animationFramesIdle.size() - 1)
		{
			_animationIterator++;
		}
		else {
			_animationIterator = 0;
		}
		_sprite.setTexture(_animationFramesIdle.at(_animationIterator));

		_clock.restart();
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void mainCharacter::attack(float dt)
{
	if (_state == entityStates::ATTACKING) {

	}
}

/// <summary>
/// 
/// </summary>
void mainCharacter::draw() const
{
	_data->window.draw(_sprite);
}
