#include "minotaur.h"
#include <iostream>

/// <summary>
/// Constructeur
/// </summary>
minotaur::minotaur(gameDataRef data)
{
	_data = data;
	_nbrLives = MINOTAUR_NBR_LIVES;
	_animationIterator = 0;

	// Idle right
	for (int i = 1; i <= 5; i++)
		_animationFramesIdleRight.push_back(_data->assets.getTexture("minotaur idle frame right " + to_string(i)));

	// Idle left
	for (int i = 1; i <= 5; i++)
		_animationFramesIdleLeft.push_back(_data->assets.getTexture("minotaur idle frame left " + to_string(i)));

	// Walking right
	for (int i = 1; i <= 6; i++)
		_animationFramesWalkingRight.push_back(_data->assets.getTexture("minotaur walking frame right " + to_string(i)));

	// Walking left
	for (int i = 1; i <= 6; i++)
		_animationFramesWalkingLeft.push_back(_data->assets.getTexture("minotaur walking frame left " + to_string(i)));

	// Fighting right
	for (int i = 1; i <= 10; i++)
		_animationFramesFightingRight.push_back(_data->assets.getTexture("minotaur attack 1 frame right " + to_string(i)));

	// Fighting left
	for (int i = 1; i <= 10; i++)
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("minotaur attack 1 frame left " + to_string(i)));

	// Damaged left
	for (int i = 1; i <= 4; i++)
		_animationFramesDamagedLeft.push_back(_data->assets.getTexture("minotaur damaged frame left " + to_string(i)));

	// Damaged right
	for (int i = 1; i <= 4; i++)
		_animationFramesDamagedRight.push_back(_data->assets.getTexture("minotaur damaged frame right " + to_string(i)));

	// Dying left
	for (int i = 1; i <= 8; i++)
		_animationFramesDyingLeft.push_back(_data->assets.getTexture("minotaur dying frame left " + to_string(i)));

	// Dying right
	for (int i = 1; i <= 8; i++)
		_animationFramesDyingRight.push_back(_data->assets.getTexture("minotaur dying frame right " + to_string(i)));

	_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));

	_sprite.setScale(7.0f, 7.0f);

	_sprite.setPosition((_data->window.getSize().x / 2) - (_sprite.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_sprite.getGlobalBounds().height / 2));

	_state = IDLE;
}

/// <summary>
/// Update l'entité à chaque frame
/// </summary>
/// <param name="dt"></param>
void minotaur::update(float dt)
{
	// Si on change de frame et que nous ne sommes pas en train d'attaquer
	if (_clock.getElapsedTime().asSeconds() > MINOTAUR_IDLE_TIME / _animationFramesIdleLeft.size() && (_state == entityStates::IDLE)) {	// Si idle
		_animationIterator++;

		if (_animationIterator == _animationFramesIdleRight.size())		// Si fin du vecteur
			_animationIterator = 0;

		if (_dir == RIGHT || _dir == TOP)								// Gauche ou droite
			_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));
		else
			_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator));

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > MINOTAUR_ATTACK_TIME / _animationFramesIdleRight.size() && (_state == entityStates::ATTACKING)) {	// Si attaque
		_animationIterator++;

		if (_animationIterator >= _animationFramesFightingRight.size()) {	// Si fin de l'attaque
			_animationIterator = 0;

			if (_dir == TOP || _dir == RIGHT)
				_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator), true);
			else
				_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator), true);

			_state = entityStates::IDLE;
		}
		else if (_dir == RIGHT) {
			_sprite.setTexture(_animationFramesFightingRight.at(_animationIterator));

			_clock.restart();
		}
		else {
			_sprite.setTexture(_animationFramesFightingLeft.at(_animationIterator));

			_clock.restart();
		}
	}
	else if (_clock.getElapsedTime().asSeconds() > MINOTAUR_HIT_TIME / _animationFramesDamagedRight.size() && (_state == entityStates::HIT)) {
		if (_dir == RIGHT || _dir == TOP) {
			_sprite.setTexture(_animationFramesDamagedRight[_animationIterator]);
		}
		else {
			_sprite.setTexture(_animationFramesDamagedLeft[_animationIterator]);
		}

		_animationIterator++;

		if (_animationIterator >= _animationFramesDamagedLeft.size() && _nbrLives <= 0) {
			setState(DYING);
		}
		else if (_animationIterator >= _animationFramesDamagedLeft.size()) {
			setState(IDLE);
		}

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > MINOTAUR_DYING_TIME / _animationFramesDyingRight.size() && (_state == entityStates::DYING)) {
		if (_dir == RIGHT || _dir == TOP) {
			_sprite.setTexture(_animationFramesDyingRight[_animationIterator], true);
		}
		else {
			_sprite.setTexture(_animationFramesDyingLeft[_animationIterator], true);
		}

		_animationIterator++;

		if (_animationIterator >= _animationFramesDyingRight.size())
			setState(DEAD);

		_clock.restart();
	}
}

/// <summary>
/// Déclenche l'attaque de l'entité
/// </summary>
void minotaur::attack(Vector2f distance)
{
	if (_state == entityStates::IDLE || _state == entityStates::WALKING)
	{
		_state = entityStates::ATTACKING;
		_animationIterator = 0;

		cout << distance.x << endl;

		if (distance.x - 50 > 0) {
			_sprite.setTexture(_animationFramesFightingRight.at(_animationIterator), true);
			_dir = RIGHT;
		}
		else {
			_sprite.setTexture(_animationFramesFightingLeft.at(_animationIterator), true);
			_dir = LEFT;
		}
		_sprite.setScale(7.0f, 7.0f);

		_attackClock.restart();
	}
}

/// <summary>
/// Vérifie prochain mouvement selon pos du MC
/// </summary>
/// <param name="distance"></param>
/// <param name="time"></param>
/// <param name="hitDistanceX"></param>
/// <param name="hitDistanceY"></param>
/// <returns></returns>
void minotaur::move(Vector2f distance, float time, float hitDistanceX, float hitDistanceY)
{
	int x = abs(distance.x);
	int y = abs(distance.y);
	if (_state == IDLE || _state == WALKING) {			// Si marche ou est idle vérifie prochain mouvement selon pos du MC
		if (abs(distance.x) < hitDistanceX && abs(distance.y) < hitDistanceY && _attackClock.getElapsedTime().asSeconds() > 6)
			attack(distance);
		else if (abs(distance.x) < hitDistanceX && abs(distance.y) < hitDistanceY)
			setState(IDLE);
		else if (abs(distance.x) > abs(distance.y) && distance.x < 0)
			entity::move(Keyboard::A, GUARD_WALK_TIME);
		else if (abs(distance.x) > abs(distance.y))
			entity::move(Keyboard::D, GUARD_WALK_TIME);
		else if (distance.y < 0)
			entity::move(Keyboard::W, GUARD_WALK_TIME);
		else if (distance.y > 0)
			entity::move(Keyboard::S, GUARD_WALK_TIME);
	}
}