#include "entity.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
entity::entity()
{

}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
Sprite entity::getSprite() const
{
	return _sprite;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int entity::getNbrLives() const
{
	return _nbrLives;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
entityStates entity::getState() const
{
	return _state;
}

/// <summary>
/// 
/// </summary>
/// <param name="state"></param>
void entity::setState(entityStates state)
{
	_state = state;
}

/// <summary>
/// 
/// </summary>
/// <param name="key"></param>
void entity::move(Keyboard::Key key)
{
	if (_clock.getElapsedTime().asSeconds() > SKELETON_WALK_TIME / _animationFramesWalkingRight.size() && (_state != entityStates::ATTACKING)) {

		_animationIterator++;
		_state = entityStates::WALKING;

		// Si on revient au début de la liste
		if (_animationIterator >= _animationFramesWalkingRight.size()) {
			_animationIterator = 0;
		}

		// Bouge le sprite
		if (key == Keyboard::D) {
			_sprite.move(20, 0);
			_sprite.setTexture(_animationFramesWalkingRight.at(_animationIterator));
			_dir = RIGHT;
		}
		else if (key == Keyboard::W) {
			_sprite.move(0, -20);
			_sprite.setTexture(_animationFramesWalkingRight.at(_animationIterator));
			_dir = TOP;
		}
		else if (key == Keyboard::A) {
			_sprite.move(-20, 0);
			_sprite.setTexture(_animationFramesWalkingLeft.at(_animationIterator));
			_dir = LEFT;
		}
		else if (key == Keyboard::S) {
			_sprite.move(0, 20);
			_sprite.setTexture(_animationFramesWalkingLeft.at(_animationIterator));
			_dir = BOTTOM;
		}

		_clock.restart();
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void entity::setPosition(float x, float y)
{
	_sprite.setPosition(x, y);
}
