#include "gardeEnemy.h";

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
gardeEnemy::gardeEnemy(gameDataRef data) : _data(data)
{
	_animationIterator = 0;

	// Idle right
	for (int  i = 1; i < 5; i++)
	{
		_animationFramesIdleRight.push_back(_data->assets.getTexture("enemy idle frame right" + to_string(i)));
	}

	// Idle left
	for (int  i = 1; i < 5; i++)
	{
		_animationFramesIdleLeft.push_back(_data->assets.getTexture("enemy idle frame left" + to_string(i)));
	}

	// Attack left
	for (int i = 1; i < 6; i++)
	{
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("enemy attack frame left" + to_string(i)));
	}

	// Attack right
	for (int i = 1; i < 6; i++)
	{
		_animationFramesFightingRight.push_back(_data->assets.getTexture("enemy attack frame right" + to_string(i)));
	}

	_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));

	_sprite.setScale(8.0,8.0);

	_sprite.setPosition((_data->window.getSize().x / 2) - (_sprite.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_sprite.getGlobalBounds().height / 2));

	_state = IDLE;
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void gardeEnemy::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > ENEMY_IDLE_TIME / _animationFramesIdleLeft.size() && (_state == entityStates::IDLE)) {	// Si idle
		_animationIterator++;

		if (_animationIterator == _animationFramesIdleRight.size())		// Si fin du vecteur
			_animationIterator = 0;

		if (_dir == RIGHT || _dir == TOP)								// Gauche ou droite
			_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));
		else
			_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator));

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > ENEMY_ATTACK_TIME / _animationFramesIdleRight.size() && (_state == entityStates::ATTACKING)) {	// Si attaque
		_animationIterator++;

		if (_animationIterator == _animationFramesFightingRight.size()) {	// Si fin de l'attaque
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
}

/// <summary>
/// 
/// </summary>
void gardeEnemy::attack()
{
	if (_state != entityStates::ATTACKING)
	{
		_state = entityStates::ATTACKING;
		_animationIterator = 0;

		if ((_dir == directions::RIGHT) || (_dir == directions::TOP))
			_sprite.setTexture(_animationFramesFightingRight.at(_animationIterator), true);
		else
			_sprite.setTexture(_animationFramesFightingLeft.at(_animationIterator));
	}
}

/// <summary>
/// 
/// </summary>
void gardeEnemy::draw() const
{
	_data->window.draw(_sprite);
}