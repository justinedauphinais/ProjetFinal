#include "mainCharacter.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
mainCharacter::mainCharacter(gameDataRef data) : _data(data)
{
	_nbrLives = NBR_LIVES;

	_animationIterator = 0;

	#pragma region Load des assets
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

		// Animation fighting
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right1"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right2"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right3"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right4"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right5"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right6"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right7"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right8"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right9"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right10"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right11"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right12"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right13"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right14"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right15"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right16"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right17"));
		_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right18"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left1"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left2"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left3"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left4"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left5"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left6"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left7"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left8"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left9"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left10"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left11"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left12"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left13"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left14"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left15"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left16"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left17"));
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left18"));
	#pragma endregion

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
void mainCharacter::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > SKELETON_IDLE_TIME / _animationFramesIdle.size() && (_state == entityStates::IDLE)) {
		_animationIterator++;

		if (_animationIterator == _animationFramesIdle.size()) {
			_animationIterator = 0;
		}
		_sprite.setTexture(_animationFramesIdle.at(_animationIterator));

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > SKELETE_ATTACK_TIME / _animationFramesIdle.size() && (_state == entityStates::ATTACKING)) {
		_animationIterator++;

		if (_animationIterator == _animationFramesFightingRight.size()) {
			_animationIterator = 0;

			Sprite spriteTemp(_animationFramesIdle.at(_animationIterator));
			spriteTemp.setPosition(_sprite.getPosition().x + 15, _sprite.getPosition().y + 20);
			spriteTemp.setScale(5.0, 5.0);
			_sprite = spriteTemp;

			_state = entityStates::IDLE;
		} 
		else {
			_sprite.setTexture(_animationFramesFightingRight.at(_animationIterator));

			_clock.restart();
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void mainCharacter::attack()
{
	if (_state != entityStates::ATTACKING) {
		_state = entityStates::ATTACKING;

		_animationIterator = 0;
		Sprite spriteTemp;

		if ((_dir == directions::RIGHT) || (_dir == directions::TOP)) {
			spriteTemp.setTexture(_animationFramesFightingRight.at(_animationIterator));
			spriteTemp.setPosition(_sprite.getPosition().x - 15, _sprite.getPosition().y - 20);
		}
		else {
			spriteTemp.setTexture(_animationFramesFightingLeft.at(_animationIterator));
			spriteTemp.setPosition(_sprite.getPosition().x + 15, _sprite.getPosition().y + 20);
		}

		spriteTemp.setScale(5.0, 5.0);
		_sprite = spriteTemp;
	}
}

/// <summary>
/// 
/// </summary>
void mainCharacter::draw() const
{
	_data->window.draw(_sprite);
}
