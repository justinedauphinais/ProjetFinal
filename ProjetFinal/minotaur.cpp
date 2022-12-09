#include "minotaur.h"

/// <summary>
/// Constructeur
/// </summary>
minotaur::minotaur(gameDataRef data)
{
	_data = data;

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
	{
		_animationFramesWalkingLeft.push_back(_data->assets.getTexture("minotaur walking frame left " + to_string(i)));
	}

	_sprite.setTexture(_animationFramesIdleRight.at(_animationIterator));

	_sprite.setScale(5.0f, 5.0f);

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
}

/// <summary>
/// Déclenche l'attaque de l'entité
/// </summary>
void minotaur::attack()
{
}

/// <summary>
/// Affiche 
/// </summary>
void minotaur::draw() const
{
	_data->window.draw(_sprite);
}