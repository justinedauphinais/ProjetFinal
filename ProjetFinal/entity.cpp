#include "entity.h"

/// <summary>
/// Get le nombre de vie de l'entité
/// </summary>
/// <returns></returns>
int entity::getNbrLives() const
{
	return _nbrLives;
}

/// <summary>
/// Get le state de l'entité
/// </summary>
/// <returns></returns>
entityStates entity::getState() const
{
	return _state;
}

/// <summary>
/// Set le state de l'entité
/// </summary>
/// <param name="state"></param>
void entity::setState(entityStates state)
{
	_state = state;
}

/// <summary>
/// Bouge l'entité
/// </summary>
/// <param name="key"></param>
void entity::move(Keyboard::Key key, float time)
{
	// Si on change de frame et que nous ne sommes pas en train d'attaquer
	if (_clock.getElapsedTime().asSeconds() > (time / _animationFramesWalkingRight.size()) && (_state == entityStates::IDLE || _state == entityStates::WALKING)) {
		_state = entityStates::WALKING;
		_animationIterator++;

		// Si on revient au début de la liste
		if (_animationIterator >= _animationFramesWalkingRight.size())
			_animationIterator = 0;

		// Bouge le sprite
		if (key == Keyboard::D) {
			_sprite.move(MOVEMENT_DISTANCE, 0);
			_sprite.setTexture(_animationFramesWalkingRight.at(_animationIterator));
			_dir = RIGHT;
		}
		else if (key == Keyboard::W) {
			_sprite.move(0, -MOVEMENT_DISTANCE);
			_sprite.setTexture(_animationFramesWalkingRight.at(_animationIterator));
			_dir = TOP;
		}
		else if (key == Keyboard::A) {
			_sprite.move(-MOVEMENT_DISTANCE, 0);
			_sprite.setTexture(_animationFramesWalkingLeft.at(_animationIterator));
			_dir = LEFT;
		}
		else if (key == Keyboard::S) {
			_sprite.move(0, MOVEMENT_DISTANCE);
			_sprite.setTexture(_animationFramesWalkingLeft.at(_animationIterator));
			_dir = BOTTOM;
		}

		_clock.restart();
	}
}