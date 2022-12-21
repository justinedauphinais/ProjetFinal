#include "shopState.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
/// <param name="hud"></param>
shopState::shopState(gameDataRef data, hud*& hud) : _data(data)
{
	_item = nullptr;
	_hud = hud;
	_mainCharacter = nullptr;
	_door = nullptr;
	_shopOwner = nullptr;
	_showDialogue = false;
}

/// <summary>
/// Destructeur
/// </summary>
shopState::~shopState()
{
	delete _mainCharacter;
	delete _wall;
	delete _door;
	delete _shopOwner;
	delete _item;
}

/// <summary>
/// Load les sprites à l’aide du assetManager ds _data et la set au Sprite
/// </summary>
void shopState::init()
{
	_background.setTexture(_data->assets.getTexture("game background 1"));
	_carpet.setTexture(_data->assets.getTexture("tapis"));
	_carpet.setScale(0.8f, 0.8f);
	_carpet.setPosition(150, 200);

	_torches.push_back(torch(_data, 250, 40, 1));
	_torches.push_back(torch(_data, 800, 40, 3));
	_torches.push_back(torch(_data, 1100, 40, 2));
	_torches.push_back(torch(_data, 1600, 40, 0));

	// Pointeurs
	_wall = new wall(_data, 1);
	_door = new door(_data, CLOSED, 1);
	_mainCharacter = new mainCharacter(_data, _hud->getNbrVies());
	_shopOwner = new shopOwner(_data);
	_cat = new cat(_data);
	_item = new item(_data, bigLifePotion, 700, 250);

	// Shop owner
	_shopOwnerHiSprite.setTexture(_data->assets.getTexture("talking shop owner"));
	_shopOwnerHiSprite.setScale(5.0f, 5.0f);
	_shopOwnerHiSprite.setPosition(_shopOwner->getSprite().getPosition().x - ((_shopOwnerHiSprite.getGlobalBounds().width - _shopOwner->getSprite().getGlobalBounds().width) / 4),
									_shopOwner->getSprite().getPosition().y - _shopOwnerHiSprite.getGlobalBounds().height + 20);

	_priceText.setFillColor(Color::White);
	_priceText.setString(to_string(_item->getPrice()));
	_priceText.setFont(_data->assets.getFont("pixel art font"));
	_priceText.setPosition(740, 210);
	_priceText.setScale(0.8f, 0.8f);

	_coinSprite.setTexture(_data->assets.getTexture("coin"));
	_coinSprite.setScale(2.0f, 2.0f);
	_coinSprite.setPosition(_priceText.getPosition().x - 50, _priceText.getPosition().y - 7);

	// Pop up
	_popUp.setTexture(_data->assets.getTexture("pop up"));
	_popUp.setScale(5.0f, 5.0f);
	_popUp.setPosition(SCREEN_WIDTH / 2 - _popUp.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - _popUp.getGlobalBounds().height / 2);

	_popUpText.setFillColor(Color::White);
	_popUpText.setFont(_data->assets.getFont("pixel art font"));
	_popUpText.setString("Voulez-vous acheter cet item?");
	_popUpText.setCharacterSize(15);
	_popUpText.setPosition(_popUp.getPosition().x + 50, _popUp.getPosition().y + 50);

	_buttonAccept.setTexture(_data->assets.getTexture("accept purchase"));
	_buttonAccept.setScale(4.0f, 4.0f);
	_buttonAccept.setPosition(SCREEN_WIDTH / 2 - _buttonAccept.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 + _buttonAccept.getGlobalBounds().height * 1.2f);

	// Liste de sprites
	_lstSprites.push_back(_mainCharacter->getSprite());
	_lstSprites.push_back(_shopOwner->getSprite());
	_lstSprites.push_back(_item->getSprite());

	_inItemFrame = false;

	if (!_healBuffer.loadFromFile(SOUND_HEAL)) 
		cout << "Erreur loading sound effect" << endl;

	_healSound.setBuffer(_healBuffer);

	if (!_popUpBuffer.loadFromFile(SOUND_POP_UP))
		cout << "Erreur loading sound effect" << endl;

	_popUpSound.setBuffer(_popUpBuffer);

	_gameState = gameStates::ready;
}

/// <summary>
/// Fenêtre qui reste ouverte tant qu’elle n’est pas fermée
/// Gestions des inputs de l'utilisateur
/// </summary>
void shopState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)					// Ferme la fenêtre
			_data->window.close();
		else if (event.type == Event::KeyReleased) {		// Idle
			_mainCharacter->setState(entityStates::IDLE);
			_usedItem = false;
		}
		else if (_inItemFrame && _data->input.isSpriteClicked(_buttonAccept, Mouse::Left, _data->window) && _hud->removeMoney(_item->getPrice())) { // Item present sur la page
			_item->wasBought();
			_inItemFrame = false;
			_healSound.play();
			_hud->addHeart(_item->getEffect());
		}
	}

	#pragma region Mouvement personnage
		_moveY = _moveX = 0;

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			_mainCharacter->move(Keyboard::D, SKELETON_WALK_TIME);
			_moveX += MOVEMENT_DISTANCE;
		}

		if (Keyboard::isKeyPressed(Keyboard::A)) {
			_mainCharacter->move(Keyboard::A, SKELETON_WALK_TIME);
			_moveX += -MOVEMENT_DISTANCE;
		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			_mainCharacter->move(Keyboard::W, SKELETON_WALK_TIME);
			_moveY += -MOVEMENT_DISTANCE;
		}

		if (Keyboard::isKeyPressed(Keyboard::S)) {
			_mainCharacter->move(Keyboard::S, SKELETON_WALK_TIME);
			_moveY += MOVEMENT_DISTANCE;
		}
	#pragma endregion
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void shopState::update(float dt)
{
	// Update les entitées
	_mainCharacter->update(dt);
	_shopOwner->update(dt);
	_cat->update(dt);

	for (int i = 0; i < _torches.size(); i++)	// Update les torches
		_torches[i].update(dt);

	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _door->getSprite(), 5.0f, 0.3f)) {				// Collision porte
		if (_door->getState() == CLOSED) {		// Si porte fermée, on ouvre
			_door->openDoor();
			_clock.restart();
		}
		else if (_clock.getElapsedTime().asSeconds() > 0.3f) {		// 
			_hud->addRoom();
			_data->machine.addState(stateRef(new gameState(_data, _hud)), true);
		}
	}
	
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 2.5f, 2.5f, _wall->getWallUp(), 1.0f, 0.1f)) {				// Collision mur du haut
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
	else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 3.0f, 5.0f, _cat->getSprite(), 3.0f, 0.05f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - _moveX, _mainCharacter->getSprite().getPosition().y - _moveY);
	}

	// Collision items
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 3.0f, 4.0f, _item->getSprite(), 4.0f, 0.05f) && !_item->isBought()) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - _moveX, _mainCharacter->getSprite().getPosition().y - _moveY);
	}
	else if (!_collision.checkSpriteCollision(_mainCharacter->getSprite(), 6.0f, 6.0f, _item->getSprite(), 6.0f, 4.0f) && !_item->isBought()) {
		_inItemFrame = false;
	}
	else if (!_inItemFrame && !_item->isBought()) {
		_inItemFrame = true;
		_selectedItem = _item->getSprite();
		_selectedItem.setScale(6.5f, 6.5f);
		_selectedItem.setPosition(SCREEN_WIDTH / 2 - _selectedItem.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 - _selectedItem.getGlobalBounds().height / 2);
		_popUpSound.play();
	}

	// Collision shop keeper
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 6.0f, 4.0f, _shopOwner->getSprite(), 9.0f, 4.0f))
		_showDialogue = true;
	else
		_showDialogue = false;

	_lstSprites.clear();
	_lstSprites.push_back(_shopOwner->getSprite());
	_lstSprites.push_back(_mainCharacter->getSprite());

	if (!_item->isBought())
		_lstSprites.push_back(_item->getSprite());

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
/// Clear, dessine le background et display la fenêtre
/// </summary>
/// <param name="dt"></param>
void shopState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_carpet);
	_wall->drawBackWall();	

	for (int i = 0; i < _torches.size(); i++)		// Torches
		_torches[i].draw();

	_cat->draw();

	_door->draw();

	for (int i = 0; i < _lstSprites.size(); i++)	// Vecteur de sprite
		_data->window.draw(_lstSprites[i]);

	if (!_item->isBought()) {						// Prix de l'item
		_data->window.draw(_priceText);
		_data->window.draw(_coinSprite);
	}

	_wall->draw();

	if (_showDialogue)								// Montre dialogue
		_data->window.draw(_shopOwnerHiSprite);

	_hud->draw();

	if (_inItemFrame) {								// Si permet d'acheté potion
		_data->window.draw(_popUp);
		_data->window.draw(_popUpText);
		_data->window.draw(_selectedItem);
		_data->window.draw(_buttonAccept);
	}

	_data->window.display();
}