#include "entity.h"
#include <iostream>

/// <summary>
/// Retourne le nombre de vie de l'entit�
/// </summary>
/// <returns></returns>
int entity::getNbrLives() const
{
	return _nbrLives;
}

/// <summary>
/// Retourne le state de l'entit�
/// </summary>
/// <returns></returns>
entityStates entity::getState() const
{
	return _state;
}

/// <summary>
/// Retourne la direction de l'entit�
/// </summary>
/// <returns></returns>
directions entity::getDirection() const
{
	return _dir;
}

/// <summary>
/// Set le state de l'entit�
/// </summary>
/// <param name="state"></param>
void entity::setState(entityStates state)
{
	if (_state != state) {
		_state = state;
		_animationIterator = 0;
	}
}

/// <summary>
/// Enl�ve le nombre de coeurs souhait�s
/// Retourne si l'entit� est morte 
/// </summary>
/// <param name="nbr"></param>
bool entity::removeHearts(int nbr)
{
	_nbrLives -= nbr;

	return _nbrLives <= 0;
}

/// <summary>
/// Bouge l'entit�
/// </summary>
/// <param name="key"></param>
void entity::move(Keyboard::Key key, float time)
{
	// Si on change de frame et que nous ne sommes pas en train d'attaquer
	if (_clock.getElapsedTime().asSeconds() > (time / _animationFramesWalkingRight.size()) && (_state == entityStates::IDLE || _state == entityStates::WALKING)) {
		_state = entityStates::WALKING;
		_animationIterator++;

		// Si on revient au d�but de la liste
		if (_animationIterator >= _animationFramesWalkingRight.size())
			_animationIterator = 0;

		// Bouge le sprite
		if (key == Keyboard::D) {
			_sprite.move(MOVEMENT_DISTANCE, 0);
			_sprite.setTexture(_animationFramesWalkingRight.at(_animationIterator), true);
			_dir = RIGHT;
		}
		else if (key == Keyboard::W) {
			_sprite.move(0, -MOVEMENT_DISTANCE);
			_sprite.setTexture(_animationFramesWalkingRight.at(_animationIterator), true);
			_dir = TOP;
		}
		else if (key == Keyboard::A) {
			_sprite.move(-MOVEMENT_DISTANCE, 0);
			_sprite.setTexture(_animationFramesWalkingLeft.at(_animationIterator), true);
			_dir = LEFT;
		}
		else if (key == Keyboard::S) {
			_sprite.move(0, MOVEMENT_DISTANCE);
			_sprite.setTexture(_animationFramesWalkingLeft.at(_animationIterator), true);
			_dir = BOTTOM;
		}

		_clock.restart();
	}
}