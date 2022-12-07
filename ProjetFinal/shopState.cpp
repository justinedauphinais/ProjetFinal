#include "shopState.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
/// <param name="hud"></param>
shopState::shopState(gameDataRef data, hud*& hud) : _data(data)
{
	_hud = hud;
	_mainCharacter = nullptr;
	_wall = nullptr;
	_hud = nullptr;
	_door = nullptr;
	_shopOwner = nullptr;
}

/// <summary>
/// 
/// </summary>
shopState::~shopState()
{
	delete _mainCharacter;
	delete _wall;
	delete _door;
	delete _shopOwner;
}

/// <summary>
/// 
/// </summary>
void shopState::init()
{
	_background.setTexture(_data->assets.getTexture("game background"));

	_hud->addRoom();

	_mainCharacter = new mainCharacter(_data);
	_wall = new wall(_data);
	_door = new door(_data);
	_mainCharacter = new mainCharacter(_data, _hud->getNbrVies());
	_shopOwner = new shopOwner(_data);

	_gameState = gameStates::ready;
}

/// <summary>
/// 
/// </summary>
void shopState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)	// Ferme la fenêtre
			_data->window.close();
		else if (event.type == Event::KeyPressed) {			// Mouvement

			if (Keyboard::isKeyPressed(Keyboard::D)) {
				_mainCharacter->move(Keyboard::D);
				_moveX = 20;
				_moveY = 0;
			}

			if (Keyboard::isKeyPressed(Keyboard::A)) {
				_mainCharacter->move(Keyboard::A);
				_moveX = -20;
				_moveY = 0;
			}

			if (Keyboard::isKeyPressed(Keyboard::W)) {
				_mainCharacter->move(Keyboard::W);
				_moveX = 0;
				_moveY = -20;
			}

			if (Keyboard::isKeyPressed(Keyboard::S)) {
				_mainCharacter->move(Keyboard::S);
				_moveX = 0;
				_moveY = 20;
			}
		}
		else if (event.type == Event::KeyReleased) {		// Idle
			_mainCharacter->setState(entityStates::IDLE);
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void shopState::update(float dt)
{
	_mainCharacter->update(dt);
	_shopOwner->update(dt);

	// Collision porte
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _door->getSprite(), 1.0f, 0.2f)) {
		_hud->addRoom();
		_hud->removeHeart(2);
		_data->machine.addState(stateRef(new gameState(_data, _hud)), true);
	}

	// Collision mur du haut
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 2.5f, 2.5f, _wall->getWallUp(), 1.0f, 0.1f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y + 20);
	}

	// Collision mur du bas
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 3.5f, _wall->getWallDown(), 1.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y - 20);
	}

	// Collision mur gauche
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _wall->getWallLeft(), 0.7f, 1.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x + 20, _mainCharacter->getSprite().getPosition().y);
	}

	// Collision mur droit
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 4.0f, 5.0f, _wall->getWallRight(), 1.0f, 1.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - 20, _mainCharacter->getSprite().getPosition().y);
	}

	// Collision shop keeper
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 3.0f, _shopOwner->getSprite(), 8.0f, 3.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - _moveX, _mainCharacter->getSprite().getPosition().y - _moveY);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void shopState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_wall->drawBackWall();
	_door->draw();
	_shopOwner->draw();
	_mainCharacter->draw();
	_wall->draw();
	_hud->draw();
	_data->window.display();
}
