#include "door.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="state"></param>
door::door(gameDataRef data, doorState state, int nbr) : _data(data)
{
	_state = state;

	if (_state == CLOSED) {				// Si porte fermée
		_sprite.setTexture(_data->assets.getTexture("closed door " + to_string(nbr)));
	}
	else {
		_sprite.setTexture(_data->assets.getTexture("opened door"));
	}

	_sprite.setScale(5.0, 5.0);
	_sprite.setPosition((SCREEN_WIDTH / 2) - (_sprite.getGlobalBounds().width / 2), 0);

	if (!_openDoorBuffer.loadFromFile(SOUND_DOOR_OPENING))	// Son
		cout << "Erreur loading sound effect" << endl;

	_openDoorSound.setBuffer(_openDoorBuffer);
}

/// <summary>
/// Ouvre la porte
/// </summary>
void door::openDoor()
{
	_openDoorSound.play();
	_state = OPENED;
	_sprite.setTexture(_data->assets.getTexture("opened door"));
}

/// <summary>
/// Retourne le state
/// </summary>
/// <returns></returns>
doorState door::getState() const
{
	return _state;
}

/// <summary>
/// Retourne le sprite
/// </summary>
/// <returns></returns>
Sprite door::getSprite() const
{
	return _sprite;
}

/// <summary>
/// Dessine le sprite
/// </summary>
void door::draw() const
{
	_data->window.draw(_sprite);
}