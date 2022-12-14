#include "gardeEnemy.h";

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
gardeEnemy::gardeEnemy(gameDataRef data)
{
	_data = data;
	_animationIterator = 0;
	_nbrLives = NBR_LIVES_GARD;
	_dead = false;

	// Idle right
	for (int  i = 1; i < 5; i++)
		_animationFramesIdleRight.push_back(_data->assets.getTexture("enemy idle frame right" + to_string(i)));

	// Idle left
	for (int  i = 1; i < 5; i++)
		_animationFramesIdleLeft.push_back(_data->assets.getTexture("enemy idle frame left" + to_string(i)));

	// Walking left
	for (int i = 1; i < 6; i++)
		_animationFramesWalkingLeft.push_back(_data->assets.getTexture("enemy walking frame left" + to_string(i)));

	// Walking right
	for (int i = 1; i < 6; i++)
		_animationFramesWalkingRight.push_back(_data->assets.getTexture("enemy walking frame right" + to_string(i)));

	// Attack left
	for (int i = 1; i < 6; i++)
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("enemy attack frame left" + to_string(i)));

	// Attack right
	for (int i = 1; i < 6; i++)
		_animationFramesFightingRight.push_back(_data->assets.getTexture("enemy attack frame right" + to_string(i)));

	// Damaged left
	for (int i = 1; i < 3; i++)
		_animationFramesDamagedLeft.push_back(_data->assets.getTexture("enemy damaged frame left" + to_string(i)));

	// Damaged right
	for (int i = 1; i < 3; i++)
		_animationFramesDamagedRight.push_back(_data->assets.getTexture("enemy damaged frame right" + to_string(i)));

	_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));

	_sprite.setScale(8.0,8.0);

	_sprite.setPosition((_data->window.getSize().x / 2) - (_sprite.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_sprite.getGlobalBounds().height / 2));

	//_lifeBarSprite.setTexture(_data->assets.getTexture("lifeBar"));
	//_lifeBarSprite.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - 50);
	//_lifeBarSprite.setScale(2.0f, 2.0f);

	//_lifeSprite.setFillColor(Color::Color(244, 20, 20));
	//_lifeSprite.setSize(Vector2f(100, 50));

	_state = IDLE;
}

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
gardeEnemy::gardeEnemy(gameDataRef data, float posX, float posY)
{
	_data = data;
	_animationIterator = 0;
	_nbrLives = NBR_LIVES_GARD;
	_dead = false;

	// Idle right
	for (int i = 1; i < 5; i++)
		_animationFramesIdleRight.push_back(_data->assets.getTexture("enemy idle frame right" + to_string(i)));

	// Idle left
	for (int i = 1; i < 5; i++)
		_animationFramesIdleLeft.push_back(_data->assets.getTexture("enemy idle frame left" + to_string(i)));

	// Walking left
	for (int i = 1; i < 6; i++)
		_animationFramesWalkingLeft.push_back(_data->assets.getTexture("enemy walking frame left" + to_string(i)));

	// Walking right
	for (int i = 1; i < 6; i++)
		_animationFramesWalkingRight.push_back(_data->assets.getTexture("enemy walking frame right" + to_string(i)));

	// Attack left
	for (int i = 1; i < 6; i++)
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("enemy attack frame left" + to_string(i)));

	// Attack right
	for (int i = 1; i < 6; i++)
		_animationFramesFightingRight.push_back(_data->assets.getTexture("enemy attack frame right" + to_string(i)));

	// Damaged left
	for (int i = 1; i < 3; i++)
		_animationFramesDamagedLeft.push_back(_data->assets.getTexture("enemy damaged frame left" + to_string(i)));

	// Damaged right
	for (int i = 1; i < 3; i++)
		_animationFramesDamagedRight.push_back(_data->assets.getTexture("enemy damaged frame right" + to_string(i)));

	// Dying left
	for (int i = 1; i <= 6; i++) 
		_animationFramesDyingLeft.push_back(_data->assets.getTexture("enemy dying frame left" + to_string(i)));

	// Dying right
	for (int i = 1; i <= 6; i++)
		_animationFramesDyingRight.push_back(_data->assets.getTexture("enemy dying frame right" + to_string(i)));

	_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));

	_sprite.setScale(8.0, 8.0);

	_sprite.setPosition(posX, posY);

	_state = IDLE;
}

/// <summary>
/// Update l'objet à chaque frame
/// </summary>
/// <param name="dt"></param>

void gardeEnemy::update(float dt)
{
	// Si on change de frame et que nous ne sommes pas en train d'attaquer
	if (_clock.getElapsedTime().asSeconds() > ENEMY_IDLE_TIME / _animationFramesIdleLeft.size() && (_state == entityStates::IDLE)) {	// Si idle
		_animationIterator++;

		if (_animationIterator >= _animationFramesIdleRight.size())		// Si fin du vecteur
			_animationIterator = 0;

		if (_dir == RIGHT || _dir == TOP)								// Gauche ou droite
			_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator), true);
		else
			_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator), true);

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > ENEMY_ATTACK_TIME / _animationFramesIdleRight.size() && (_state == entityStates::ATTACKING)) {	// Si attaque
		_animationIterator++;

		if (_animationIterator >= _animationFramesFightingRight.size()) {	// Si fin de l'attaque
			_animationIterator = 0;

			if (_dir == TOP || _dir == RIGHT)
				_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator), true);
			else
				_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator), true);

			_sprite.move(30, 5);

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
	else if (_clock.getElapsedTime().asSeconds() > ENEMY_HIT_TIME / _animationFramesDamagedRight.size() && (_state == entityStates::HIT)) {
		if (_dir == RIGHT || _dir == TOP) {
			_sprite.setTexture(_animationFramesDamagedRight[_animationIterator]);
		}
		else {
			_sprite.setTexture(_animationFramesDamagedLeft[_animationIterator]);
		}

		_animationIterator++;

		if (_animationIterator >= _animationFramesDamagedLeft.size() && _nbrLives == 0) {
			setState(DYING);
		}
		else if (_animationIterator >= _animationFramesDamagedLeft.size()) {
			setState(IDLE);
		}

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > ENEMY_DYING_TIME / _animationFramesDyingRight.size() && (_state == entityStates::DYING)) {
		if (_dir == RIGHT || _dir == TOP) {
			_sprite.setTexture(_animationFramesDyingRight[_animationIterator]);
		}
		else {
			_sprite.setTexture(_animationFramesDyingLeft[_animationIterator]);
		}

		_animationIterator++;

		if (_animationIterator >= _animationFramesDyingRight.size())
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
	if (_state == entityStates::IDLE || _state == entityStates::WALKING)
	{
		_state = entityStates::ATTACKING;
		_animationIterator = 0;

		if ((_dir == directions::RIGHT) || (_dir == directions::TOP)) {
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