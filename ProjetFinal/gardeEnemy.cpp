#include "gardeEnemy.h";

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
gardeEnemy::gardeEnemy(gameDataRef data, float posX, float posY)
{
	_data = data;
	_animationIterator = 0;
	_nbrLives = NBR_LIVES_GUARD;

	// Idle 
	for (int i = 1; i <= 5; i++)
		_animationFramesIdleRight.push_back(_data->assets.getTexture("guard idle frame right" + to_string(i)));

	for (int i = 1; i <= 5; i++)
		_animationFramesIdleLeft.push_back(_data->assets.getTexture("guard idle frame left" + to_string(i)));

	// Walking
	for (int i = 1; i < 6; i++)
		_animationFramesWalkingLeft.push_back(_data->assets.getTexture("guard walking frame left" + to_string(i)));

	for (int i = 1; i < 6; i++)
		_animationFramesWalkingRight.push_back(_data->assets.getTexture("guard walking frame right" + to_string(i)));

	// Attack
	for (int i = 1; i < 6; i++)
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("guard attack frame left" + to_string(i)));

	for (int i = 1; i < 6; i++)
		_animationFramesFightingRight.push_back(_data->assets.getTexture("guard attack frame right" + to_string(i)));

	// Damaged
	for (int i = 1; i < 3; i++)
		_animationFramesDamagedLeft.push_back(_data->assets.getTexture("guard damaged frame left" + to_string(i)));

	for (int i = 1; i < 3; i++)
		_animationFramesDamagedRight.push_back(_data->assets.getTexture("guard damaged frame right" + to_string(i)));

	// Dying
	for (int i = 1; i <= 6; i++) 
		_animationFramesDyingLeft.push_back(_data->assets.getTexture("guard dying frame left" + to_string(i)));

	for (int i = 1; i <= 6; i++)
		_animationFramesDyingRight.push_back(_data->assets.getTexture("guard dying frame right" + to_string(i)));

	_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));

	_sprite.setScale(8.0, 8.0);

	_sprite.setPosition(posX, posY);

	_state = IDLE;
}

/// <summary>
/// Mets à jour le sprite du garde
/// selon ce qu'il est en train de faire
/// </summary>
/// <param name="dt"></param>
void gardeEnemy::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > GUARD_IDLE_TIME / _animationFramesIdleLeft.size() && (_state == entityStates::IDLE)) {	// Si idle
		_animationIterator++;

		if (_animationIterator >= _animationFramesIdleRight.size())		// Si fin du vecteur
			_animationIterator = 0;

		if (_dir == RIGHT || _dir == TOP)								// Gauche ou droite
			_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator), true);
		else
			_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator), true);

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > GUARD_ATTACK_TIME / _animationFramesIdleRight.size() && (_state == entityStates::ATTACKING)) {	// Si attaque
		_animationIterator++;

		if (_animationIterator >= _animationFramesFightingRight.size()) {	// Si fin de l'attaque
			_animationIterator = 0;

			if (_dir == TOP || _dir == RIGHT)		// Gauche ou droite
				_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator), true);
			else
				_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator), true);

			_sprite.move(30, 5);

			_state = entityStates::IDLE;
		}
		else if (_dir == RIGHT)						// Gauche ou droite
			_sprite.setTexture(_animationFramesFightingRight.at(_animationIterator));
		else
			_sprite.setTexture(_animationFramesFightingLeft.at(_animationIterator));

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > GUARD_HIT_TIME / _animationFramesDamagedRight.size() && (_state == entityStates::HIT)) {		// Si frappé
		if (_dir == RIGHT || _dir == TOP)			// Gauche ou droite
			_sprite.setTexture(_animationFramesDamagedRight[_animationIterator], true);
		else
			_sprite.setTexture(_animationFramesDamagedLeft[_animationIterator], true);

		_animationIterator++;

		if (_animationIterator >= _animationFramesDamagedLeft.size())
			setState(IDLE);

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > GUARD_DYING_TIME / _animationFramesDyingRight.size() && (_state == entityStates::DYING)) {	// Si meurt
		if (_dir == RIGHT || _dir == TOP)			// Gauche ou droite
			_sprite.setTexture(_animationFramesDyingRight[_animationIterator], true);
		else
			_sprite.setTexture(_animationFramesDyingLeft[_animationIterator], true);

		if (_animationIterator == 0)				// Début de l'animation
			_sprite.move(-80, -15);

		_animationIterator++;

		if (_animationIterator >= _animationFramesDyingRight.size())	// Fin de l'animation
			setState(DEAD);

		_clock.restart();
	}

	_sprite.setScale(8.0, 8.0);
}

/// <summary>
/// Déclenche l'attaque de l'entité
/// </summary>
void gardeEnemy::attack()
{
	if (_state == entityStates::IDLE || _state == entityStates::WALKING)	// Si marche ou idle
	{
		_state = entityStates::ATTACKING;
		_animationIterator = 0;

		if ((_dir == directions::RIGHT) || (_dir == directions::TOP)) {		// Gauche ou droite
			_sprite.setTexture(_animationFramesFightingRight.at(_animationIterator), true);
			_sprite.move(-30, -5);
		}
		else {
			_sprite.setTexture(_animationFramesFightingLeft.at(_animationIterator), true);
		}
		_sprite.setScale(8.0, 8.0);

		_attackClock.restart();
	}
}

/// <summary>
/// Update le garde selon la position du MC
/// </summary>
/// <param name="distance"></param>
/// <param name="time"></param>
/// <param name="hitDistanceX"></param>
/// <param name="hitDistanceY"></param>
/// <returns></returns>
void gardeEnemy::move(Vector2f distance, float time, float hitDistanceX, float hitDistanceY)
{
	int x = abs(distance.x);
	int y = abs(distance.y);

	if (_state == WALKING || _state == IDLE) {									// Update le garde selon la position du MC
		if (abs(distance.x) > AGRO_RANGE && abs(distance.y) < AGRO_RANGE)		// si est idle ou marche
			setState(IDLE);
		else if (abs(distance.x) < hitDistanceX && abs(distance.y) < hitDistanceY && _attackClock.getElapsedTime().asSeconds() > GUARD_WAIT_TIME)
			attack();
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