#include "mainCharacter.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
mainCharacter::mainCharacter(gameDataRef data, int nbrVies)
{
	_data = data;
	_nbrLives = nbrVies;

	_animationIterator = 0;

	#pragma region Load des assets
		// Animation idle
		for (int i = 1; i < 12; i++) {
			_animationFramesIdleRight.push_back(_data->assets.getTexture("skeleton idle frame right " + to_string(i)));
		}

		for (int i = 1; i < 12; i++) {
			_animationFramesIdleLeft.push_back(_data->assets.getTexture("skeleton idle frame left " + to_string(i)));
		}

		// Animations walks
		for (int i = 1; i < 13; i++) {
			_animationFramesWalkingRight.push_back(_data->assets.getTexture("skeleton walking frame right" + to_string(i)));
		}

		for (int i = 1; i < 13; i++) {
			_animationFramesWalkingLeft.push_back(_data->assets.getTexture("skeleton walking frame left" + to_string(i)));
		}

		// Animation fighting
		for (int i = 1; i < 19; i++) {
			_animationFramesFightingRight.push_back(_data->assets.getTexture("skeleton attacking frame right" + to_string(i)));
		}

		for (int i = 1; i < 19; i++) {
			_animationFramesFightingLeft.push_back(_data->assets.getTexture("skeleton attacking frame left" + to_string(i)));
		}
	#pragma endregion

	_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));

	_sprite.setScale(5.0, 5.0);

	_sprite.setPosition((_data->window.getSize().x / 2) - (_sprite.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_sprite.getGlobalBounds().height / 2));

	// Directions
	_dir = directions::RIGHT;
	_state = entityStates::IDLE;
}

/// <summary>
/// Update l'entité à chaque frame
/// </summary>
void mainCharacter::update(float dt)
{
	// Si on change de frame et que nous ne sommes pas en train d'attaquer
	if (_clock.getElapsedTime().asSeconds() > SKELETON_IDLE_TIME / _animationFramesIdleRight.size() && (_state == entityStates::IDLE)) {
		_animationIterator++;

		if (_animationIterator == _animationFramesIdleRight.size())		// Si à la fin du vecteur
			_animationIterator = 0;

		if (_dir == RIGHT || _dir == TOP)								// Gauche ou droite
			_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));
		else
			_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator));

		_clock.restart();
	}
	else if (_clock.getElapsedTime().asSeconds() > SKELETE_ATTACK_TIME / _animationFramesIdleRight.size() && (_state == entityStates::ATTACKING)) {
		_animationIterator++;

		if (_animationIterator == _animationFramesFightingRight.size()) {
			_animationIterator = 0;

			if (_dir == TOP || _dir == RIGHT) {
				_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator), true);
				_sprite.setPosition(_sprite.getPosition().x + 15, _sprite.getPosition().y + 20);
			}
			else {
				_sprite.setTexture(_animationFramesIdleLeft.at(_animationIterator), true);
				_sprite.setPosition(_sprite.getPosition().x + 80, _sprite.getPosition().y + 20);
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
	//else if (_clock.getElapsedTime().asSeconds() > SKELETE_ATTACK_TIME);
}

/// <summary>
/// Déclenche l'attaque de l'entité
/// </summary>
/// <param name="dt"></param>
void mainCharacter::attack()
{
	if (_state != entityStates::ATTACKING) {
		_state = entityStates::ATTACKING;

		_animationIterator = 0;

		if ((_dir == directions::RIGHT) || (_dir == directions::TOP)) {
			_sprite.setTexture(_animationFramesFightingRight.at(_animationIterator), true);
			_sprite.setPosition(_sprite.getPosition().x - 15, _sprite.getPosition().y - 20);
		}
		else {
			_sprite.setTexture(_animationFramesFightingLeft.at(_animationIterator), true);
			_sprite.setPosition(_sprite.getPosition().x - 80, _sprite.getPosition().y - 20);
		}
	}
}