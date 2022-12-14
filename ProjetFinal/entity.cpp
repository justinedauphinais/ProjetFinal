#include "entity.h"
#include <iostream>

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
/// 
/// </summary>
/// <returns></returns>
directions entity::getDirection() const
{
	return _dir;
}

/// <summary>
/// Set le state de l'entité
/// </summary>
/// <param name="state"></param>
void entity::setState(entityStates state)
{
	_state = state;
	_animationIterator = 0;
}

/// <summary>
/// 
/// </summary>
/// <param name="nbr"></param>
bool entity::removeHearts(int nbr)
{
	_nbrLives -= nbr;

	return _nbrLives <= 0;
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

/// <summary>
/// 
/// </summary>
/// <param name="distance"></param>
/// <param name="time"></param>
/// <returns></returns>
bool entity::move(Vector2f distance, float time, float hitDistanceX, float hitDistanceY)
{
	if (_state != ATTACKING) {
		if (abs(distance.x) > AGRO_RANGE && abs(distance.y) < AGRO_RANGE)
			setState(IDLE);
		else if (abs(distance.x) < hitDistanceX && abs(distance.y) < hitDistanceY && _attackClock.getElapsedTime().asSeconds() > 6)
			return true;
		else if (abs(distance.x) > abs(distance.y) && distance.x < 0)
			move(Keyboard::A, ENEMY_WALK_TIME);
		else if (abs(distance.x) > abs(distance.y))
			move(Keyboard::D, ENEMY_WALK_TIME);
		else if (distance.y < 0)
			move(Keyboard::W, ENEMY_WALK_TIME);
		else if (distance.y > 0)
			move(Keyboard::S, ENEMY_WALK_TIME);
	}

	return false;
}