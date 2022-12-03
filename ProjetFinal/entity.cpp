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

int entity::getNbrLives() const
{
	return _nbrLives;
}

/// <summary>
/// 
/// </summary>
/// <param name="key"></param>
void entity::move(Keyboard::Key key)
{
	if (_clock.getElapsedTime().asSeconds() > SKELETON_WALK_TIME / _animationFramesWalkingRight.size()) {

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
		}
		else if (key == Keyboard::W) {
			_sprite.move(0, -20);
			_sprite.setTexture(_animationFramesWalkingRight.at(_animationIterator));
		}
		else if (key == Keyboard::A) {
			_sprite.move(-20, 0);
			_sprite.setTexture(_animationFramesWalkingLeft.at(_animationIterator));
		}
		else if (key == Keyboard::S) {
			_sprite.move(0, 20);
			_sprite.setTexture(_animationFramesWalkingLeft.at(_animationIterator));
		}

		_clock.restart();
	}
}