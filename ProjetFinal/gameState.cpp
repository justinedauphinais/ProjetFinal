#include "gameState.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
gameState::gameState(gameDataRef data) : _data(data)
{
	_mainCharacter = nullptr;
	_wall = nullptr;
	_hud = nullptr;
	_door = nullptr;
	_gameState = gameStates::loading;
}

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
/// <param name="character"></param>
gameState::gameState(gameDataRef data, hud*& hud) : _data(data)
{
	_hud = hud;
	_mainCharacter = nullptr;
	_wall = nullptr;
	_door = nullptr;
}

/// <summary>
/// Destructeur
/// </summary>
gameState::~gameState()
{
	delete _mainCharacter;
	delete _wall;
	delete _door;
	
}

/// <summary>
/// Initilisae les différents objets du state
/// </summary>
void gameState::init()
{
	_background.setTexture(_data->assets.getTexture("game background 1"));
	_hasKey = true;

	// Pointeurs
	if (_hud == nullptr) 
		_hud = new hud(_data, 1, 0);

	int nbrEnemies = (rand() % _hud->getRoom() + 1);
	for (int i = 0; i < nbrEnemies; i++) {
		_gardes.push_back(gardeEnemy(_data, rand() % 1500 + 150, rand() % 750 + 150));
		_lstSprites.push_back(_gardes[i].getSprite());
	}

	nbrEnemies = (rand() % 2);
	for (int i = 0; i < nbrEnemies; i++) {
		_archers.push_back(archerEnemy(_data, rand() % 1500 + 150, rand() % 750 + 150));
	}

	_mainCharacter = new mainCharacter(_data);
	_wall = new wall(_data);
	_door = new door(_data);
	_mainCharacter = new mainCharacter(_data, _hud->getNbrVies());

	_lstSprites.push_back(_mainCharacter->getSprite());


	_gameState = gameStates::ready;
}

/// <summary>
/// Réagit aux différents inputs de l'utilisateur
/// </summary>
void gameState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)	// Ferme la fenêtre
			_data->window.close();
		else if (Mouse::isButtonPressed(Mouse::Left)) {		// Attaque
			_mainCharacter->attack();
		}
		else if (event.type == Event::KeyReleased && _mainCharacter->getState() == WALKING) {		// Idle
			_mainCharacter->setState(entityStates::IDLE);
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
/// Mets-à-jour les objets du state
/// </summary>
/// <param name="dt"></param>
void gameState::update(float dt)
{
	for (int i = 0; i < _gardes.size(); i++) {
		if (_gardes[i].getState() != DEAD) {
			_gardes[i].update(dt);

			if (_gardes[i].move(_collision.getDistance(_mainCharacter->getSprite(), _gardes[i].getSprite()), dt, 175, 125))
				_gardes[i].attack();
		}
	}

	for (int i = 0; i < _archers.size(); i++) {
		if (_archers[i].getState() != DEAD) {
			_archers[i].update(dt);

			if (_archers[i].move(_collision.getDistance(_mainCharacter->getSprite(), _archers[i].getSprite()), dt, 175, 125))
				_archers[i].attack();
		}
	}

	_mainCharacter->update(dt);

	if (_mainCharacter->getState() != ATTACKING) {
		_hit = false;

		// Collision porte
		if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _door->getSprite(), 5.0f, 0.3f) && _hasKey) {
			if (_door->getState() == CLOSED) {
				_door->openDoor();
				_clock.restart();
			}
			else if (_clock.getElapsedTime().asSeconds() > 0.3f) {
				_hud->addRoom();
				if (_hud->getRoom() == 3) {
					_data->machine.addState(stateRef(new shopState(_data, _hud)), true);
				}
				else if (_hud->getRoom() == 5) {
					_data->machine.addState(stateRef(new bossRoomState(_data, _hud)), true);
				}
				else {
					_data->machine.addState(stateRef(new gameState(_data, _hud)), true);
				}
			}
		}

		if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 2.5f, 2.5f, _wall->getWallUp(), 1.0f, 0.1f))			// Collision mur du haut
			_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y + MOVEMENT_DISTANCE);
		else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 3.5f, _wall->getWallDown(), 1.0f))				// Collision mur du bas
			_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y - MOVEMENT_DISTANCE);
		else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _wall->getWallLeft(), 0.7f, 1.0f))	// Collision mur gauche
			_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x + MOVEMENT_DISTANCE, _mainCharacter->getSprite().getPosition().y);
		else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 4.0f, 5.0f, _wall->getWallRight(), 1.0f, 1.0f))	// Collision mur droit
			_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - MOVEMENT_DISTANCE, _mainCharacter->getSprite().getPosition().y);
	}

	for (int i = 0; i < _gardes.size(); i++) {
		if (_mainCharacter->getState() == ATTACKING && _collision.checkSpriteCollision(_mainCharacter->getSprite(), 7.0f, 4.0f, _gardes[i].getSprite(), 2.0f, 5.0f) 
			&& !_hit && _gardes[i].getState() != DEAD) {
			_hit = true;

			if (_gardes[i].removeHearts()) {
				_gardes[i].setState(DYING);
				_hud->addScore();
				_hud->addMoney(2);
				_hasKey = true;
			}
			else {
				_gardes[i].setState(HIT);
			}
		}
		else if (_gardes[i].getState() == ATTACKING && _mainCharacter->getState() != HIT && _collision.checkSpriteCollision(_mainCharacter->getSprite(), 4.0f, 3.0f, _gardes[i].getSprite(), 3.0f, 2.0f)) {
			_mainCharacter->setState(HIT);
			_hud->removeHeart();
		}
	}

	_lstSprites.clear();
	_lstSprites.push_back(_mainCharacter->getSprite());

	for (int i = 0; i < _gardes.size(); i++) {
		if (_gardes[i].getState() != DEAD) {
			_lstSprites.push_back(_gardes[i].getSprite());
		}
	}

	for (int i = 0; i < _archers.size(); i++) {
		if (_gardes[i].getState() != DEAD) {
			_lstSprites.push_back(_archers[i].getSprite());
		}
	}

	// Gestion de l'ordre d'affichage 
	for (int i = 0; i < (_lstSprites.size() - 1); i++) {
		if (_collision.isPast(_lstSprites[i], _lstSprites[i + 1])) {
			Sprite temp = _lstSprites[i];
			_lstSprites[i] = _lstSprites[i + 1];
			_lstSprites[i + 1] = temp;
		}
	}

	// Si mort
	if (_hud->getNbrVies() <= 0) {
		_data->machine.addState(stateRef(new gameOverState(_data, _hud->getScore(), false)), true);
	}
}

/// <summary>
/// Clear, dessine le background et display la fenêtre
/// </summary>
/// <param name="dt"></param>
void gameState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_wall->drawBackWall();
	_door->draw();

	for (int i = 0; i < _lstSprites.size(); i++) {
		_data->window.draw(_lstSprites[i]);
	}

	_wall->draw();
	_hud->draw();
	_data->window.display();
}
