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

	_torches.push_back(torch(_data, 250, 40, 1));
	_torches.push_back(torch(_data, 800, 40, 3));
	_torches.push_back(torch(_data, 1100, 40, 2));
	_torches.push_back(torch(_data, 1600, 40, 0));

	// Pointeurs
	_wall = new wall(_data, 2);
	_door = new door(_data, CLOSED, 2);
	_mainCharacter = new mainCharacter(_data, _hud->getNbrVies());
	_shopOwner = new shopOwner(_data);
	_cat = new cat(_data);

	// Shop owner
	_shopOwnerHiSprite.setTexture(_data->assets.getTexture("talking shop owner"));
	_shopOwnerHiSprite.setScale(5.0f, 5.0f);
	_shopOwnerHiSprite.setPosition(_shopOwner->getSprite().getPosition().x - ((_shopOwnerHiSprite.getGlobalBounds().width - _shopOwner->getSprite().getGlobalBounds().width) / 4),
									_shopOwner->getSprite().getPosition().y - _shopOwnerHiSprite.getGlobalBounds().height + 20);


	// Liste de sprites
	_lstSprites.push_back(_mainCharacter->getSprite());
	_lstSprites.push_back(_shopOwner->getSprite());

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
	_cat->update(dt);

	for (int i = 0; i < _torches.size(); i++)
		_torches[i].update(dt);

	#pragma region Mouvement personnage
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
	#pragma endregion

	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _door->getSprite(), 5.0f, 0.3f)) {				// Collision porte
		_hud->addRoom();
		_data->machine.addState(stateRef(new gameState(_data, _hud)), true);
	}
	else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 2.5f, 2.5f, _wall->getWallUp(), 1.0f, 0.1f)) {		// Collision mur du haut
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y + MOVEMENT_DISTANCE);
	}
	else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 3.5f, _wall->getWallDown(), 1.0f)) {					// Collision mur du bas
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y - MOVEMENT_DISTANCE);
	}
	else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _wall->getWallLeft(), 0.7f, 1.0f)) {		// Collision mur gauche
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x + MOVEMENT_DISTANCE, _mainCharacter->getSprite().getPosition().y);
	}
	else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 4.0f, 5.0f, _wall->getWallRight(), 1.0f, 1.0f)) {		// Collision mur droit
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - MOVEMENT_DISTANCE, _mainCharacter->getSprite().getPosition().y);
	}

	// Collision shop keeper
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 2.5f, _shopOwner->getSprite(), 7.0f, 2.5f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - _moveX, _mainCharacter->getSprite().getPosition().y - _moveY);
	}

	// Collision shop keeper
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 6.0f, 4.0f, _shopOwner->getSprite(), 9.0f, 4.0f))
		_showDialogue = true;
	else
		_showDialogue = false;

	_lstSprites[0] = _mainCharacter->getSprite();
	_lstSprites[1] = _shopOwner->getSprite();

	// Gestion de l'ordre d'affichage 
	for (int i = 0; i < _lstSprites.size() - 1; i++) {
		if (_collision.isPast(_lstSprites[i], _lstSprites[i + 1])) {
			Sprite temp = _lstSprites[i];
			_lstSprites[i] = _lstSprites[i + 1];
			_lstSprites[i + 1] = temp;
		}
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
	for (int i = 0; i < _torches.size(); i++)
		_torches[i].draw();
	_cat->draw();

	_door->draw();

	for (int i = 0; i < _lstSprites.size(); i++) {
		_data->window.draw(_lstSprites[i]);
	}

	_wall->draw();

	if (_showDialogue)
		_data->window.draw(_shopOwnerHiSprite);

	_hud->draw();
	_data->window.display();
}