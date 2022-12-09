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
	_door = nullptr;
	_shopOwner = nullptr;
	_showDialogue = false;
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
	_background.setTexture(_data->assets.getTexture("game background 2"));

	_wall = new wall(_data, 2);
	_door = new door(_data, CLOSED, 2);
	_mainCharacter = new mainCharacter(_data, _hud->getNbrVies());
	_shopOwner = new shopOwner(_data);

	_shopOwnerHiSprite.setTexture(_data->assets.getTexture("talking shop owner"));
	_shopOwnerHiSprite.setScale(5.0f, 5.0f);
	_shopOwnerHiSprite.setPosition(_shopOwner->getSprite().getPosition().x - ((_shopOwnerHiSprite.getGlobalBounds().width - _shopOwner->getSprite().getGlobalBounds().width) / 4),
									_shopOwner->getSprite().getPosition().y - _shopOwnerHiSprite.getGlobalBounds().height + 20);

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

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		_mainCharacter->move(Keyboard::D, SKELETON_WALK_TIME);
		_moveX = MOVEMENT_DISTANCE;
		_moveY = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		_mainCharacter->move(Keyboard::A, SKELETON_WALK_TIME);
		_moveX = -MOVEMENT_DISTANCE;
		_moveY = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		_mainCharacter->move(Keyboard::W, SKELETON_WALK_TIME);
		_moveX = 0;
		_moveY = -MOVEMENT_DISTANCE;
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		_mainCharacter->move(Keyboard::S, SKELETON_WALK_TIME);
		_moveX = 0;
		_moveY = MOVEMENT_DISTANCE;
	}

	// Collision porte
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _door->getSprite(), 5.0f, 0.3f)) {
		_hud->addRoom();
		_data->machine.addState(stateRef(new gameState(_data, _hud)), true);
	}

	// Collision mur du haut
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 2.5f, 2.5f, _wall->getWallUp(), 1.0f, 0.1f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y + MOVEMENT_DISTANCE);
	}

	// Collision mur du bas
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 3.5f, _wall->getWallDown(), 1.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y - MOVEMENT_DISTANCE);
	}

	// Collision mur gauche
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _wall->getWallLeft(), 0.7f, 1.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x + MOVEMENT_DISTANCE, _mainCharacter->getSprite().getPosition().y);
	}

	// Collision mur droit
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 4.0f, 5.0f, _wall->getWallRight(), 1.0f, 1.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - MOVEMENT_DISTANCE, _mainCharacter->getSprite().getPosition().y);
	}

	// Collision shop keeper
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 2.5f, _shopOwner->getSprite(), 7.0f, 2.5f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - _moveX, _mainCharacter->getSprite().getPosition().y - _moveY);
	}

	// Collision shop keeper
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 6.0f, 4.0f, _shopOwner->getSprite(), 9.0f, 4.0f)) {
		_showDialogue = true;
	}
	else {
		_showDialogue = false;
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

	if (_showDialogue) {
		_data->window.draw(_shopOwnerHiSprite);
	}

	_hud->draw();
	_data->window.display();
}
