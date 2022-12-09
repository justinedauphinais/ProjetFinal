
#include "gardeEnemy.h";

/// <summary>
/// crée les animations de l'enemie est set la position de celui ci.
/// </summary>
/// <param name="data"></param>
gardeEnemy::gardeEnemy(gameDataRef data) : _data(data)
{
	_animationIterator = 0;

	//idle right
	for (int  i = 1; i < 5; i++)
	{
		_animationFramesIdleRight.push_back(_data->assets.getTexture("enemy idle frame right" + to_string(i)));
	}
	//idle left
	for (int  i = 1; i < 5; i++)
	{
		_animationFramesIdleLeft.push_back(_data->assets.getTexture("enemy idle frame left" + to_string(i)));
	}
	//Attack left
	for (int i = 1; i < 6; i++)
	{
		_animationFramesFightingLeft.push_back(_data->assets.getTexture("enemy attack frame left" + to_string(i)));
	}
	//Attack right
	for (int i = 1; i < 6; i++)
	{
		_animationFramesFightingRight.push_back(_data->assets.getTexture("enemy attack frame right" + to_string(i)));
	}

	_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));

	_sprite.setScale(8.0,8.0);

	_sprite.setPosition((_data->window.getSize().x / 2) - (_sprite.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_sprite.getGlobalBounds().height / 2));
}
/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void gardeEnemy::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > ENEMY_IDLE_TIME / _animationFramesIdleLeft.size() && (_state == entityStates::IDLE)) {
		_animationIterator++;

		if (_animationIterator == _animationFramesIdleRight.size()) {
			_animationIterator = 0;
		}

		if (_dir == RIGHT || _dir == TOP) {
			_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));
		}
		else {
			_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator));
		}

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > ENEMY_ATTACK_TIME / _animationFramesIdleRight.size() && (_state == entityStates::ATTACKING)) {
		_animationIterator++;

		if (_animationIterator == _animationFramesFightingRight.size()) {
			_animationIterator = 0;

			if (_dir == TOP || _dir == RIGHT) {
				Sprite spriteTemp(_animationFramesIdleRight.at(_animationIterator));
				spriteTemp.setPosition(_sprite.getPosition().x + 15, _sprite.getPosition().y + 20);
				spriteTemp.setScale(5.0, 5.0);
				_sprite = spriteTemp;
			}
			else {
				Sprite spriteTemp(_animationFramesIdleLeft.at(_animationIterator));
				spriteTemp.setPosition(_sprite.getPosition().x + 80, _sprite.getPosition().y + 20);
				spriteTemp.setScale(5.0, 5.0);
				_sprite = spriteTemp;
			}

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
/// crée les attacks
/// </summary>
void gardeEnemy::attack()
{
	if (_state != entityStates::ATTACKING)
	{
		_state = entityStates::ATTACKING;
		_animationIterator = 0;
		Sprite spriteTemp;

		if ((_dir == directions::RIGHT) || (_dir == directions::TOP)) {
			spriteTemp.setTexture(_animationFramesFightingRight.at(_animationIterator));
			spriteTemp.setPosition(_sprite.getPosition().x - 15, _sprite.getPosition().y - 20);
		}
		else {
			spriteTemp.setTexture(_animationFramesFightingLeft.at(_animationIterator));
			spriteTemp.setPosition(_sprite.getPosition().x - 80, _sprite.getPosition().y - 20);
		}

		spriteTemp.setScale(8.0, 8.0);
		_sprite = spriteTemp;
	}
}
/// <summary>
/// affiche l'enemie
/// </summary>
void gardeEnemy::draw() const
{
	_data->window.draw(_sprite);
}


