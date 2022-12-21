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
/// Initialise les diff�rents objets du state
/// </summary>
void gameState::init()
{
	_background.setTexture(_data->assets.getTexture("game background 1"));

	// Pointeurs
	if (_hud == nullptr) 
		_hud = new hud(_data, 1, 0);

	int nbrEnemies = (rand() % _hud->getRoom() + 1);		// Cr�e nombre al�atoire d'ennemis selon nbr salle
	for (int i = 0; i < nbrEnemies; i++) {
		_gardes.push_back(gardeEnemy(_data, rand() % 1500 + 150, rand() % 500 + 150));
		_lstSprites.push_back(_gardes[i].getSprite());
	}

	// Initialisation des pointeurs
	_wall = new wall(_data);
	_door = new door(_data);
	_mainCharacter = new mainCharacter(_data, _hud->getNbrVies());

	// Key
	_key.setTexture(_data->assets.getTexture("key"));
	_key.setPosition(SCREEN_WIDTH - 275, 40);
	_key.setScale(3.0f, 3.0f);

	// Son
	if (!_enemyDeadBuffer.loadFromFile(SOUND_ENEMY_DEAD))
		cout << "Erreur loading sound effect" << endl;

	_enemyDeadSound.setBuffer(_enemyDeadBuffer);

	if (!_enemyHitBuffer.loadFromFile(SOUND_HIT))
		cout << "Erreur loading sound effect" << endl;

	_enemyHitSound.setBuffer(_enemyHitBuffer);

	if (!_MCHitBuffer.loadFromFile(SOUND_MC_HIT))
		cout << "Erreur loading sound effect" << endl;

	_MCHitSound.setBuffer(_MCHitBuffer);

	_gameState = gameStates::ready;
}

/// <summary>
/// R�agit aux diff�rents inputs de l'utilisateur
/// </summary>
void gameState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)	// Ferme la fen�tre
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
/// Mets-�-jour les objets du state
/// </summary>
/// <param name="dt"></param>
void gameState::update(float dt)
{
	for (int i = 0; i < _gardes.size(); i++) {	// Update les gardes
		_gardes[i].update(dt);
		_gardes[i].move(_collision.getDistance(_mainCharacter->getSprite(), _gardes[i].getSprite()), dt, 175, 125);
	}

	_mainCharacter->update(dt);	

	if (_mainCharacter->getState() != ATTACKING) {		// Si MC attaque pas
		_hit = false;

		// Collision porte
		if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _door->getSprite(), 5.0f, 0.3f) && _hasKey) {
			if (_door->getState() == CLOSED) {		// Si porte ferm�e, ouvre porte
				_door->openDoor();
				_clock.restart();
			}
			else if (_clock.getElapsedTime().asSeconds() > 0.2f) {
				_hud->addRoom();
				if (_hud->getRoom() == 3) {		// Shop state
					_data->machine.addState(stateRef(new shopState(_data, _hud)), true);
				}
				else if (_hud->getRoom() == 5) {	// Boss room state
					_data->machine.addState(stateRef(new bossRoomState(_data, _hud)), true);
				}
				else {								// Prochaine salle
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

	for (int i = 0; i < _gardes.size(); i++) {		// Collisions gardes
		if (_mainCharacter->getState() == ATTACKING && _collision.checkSpriteCollision(_mainCharacter->getSprite(), 7.0f, 4.0f, _gardes[i].getSprite(), 5.0f, 5.0f)		// Si est attaqu� par MC
			&& !_hit && _gardes[i].getState() != DEAD) {
			_hit = true;

			if (_gardes[i].removeHearts()) {		// Si est mort
				_enemyDeadSound.play();
				_gardes[i].setState(DYING);
				_hud->addScore();
				_hud->addMoney(2);
				_hasKey = true;
			}
			else {
				_enemyHitSound.play();
				_gardes[i].setState(HIT);
			}
		}
		else if (_gardes[i].getState() == ATTACKING && !_wasHit && _mainCharacter->getState() != HIT && _collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 3.0f, _gardes[i].getSprite(), 6.0f, 3.0f)) {	// Si attaque MC
			_wasHit = true;
			_mainCharacter->setState(HIT);
			_hud->removeHeart();
			_MCHitSound.play();
		}
		else if (_gardes[i].getState() != ATTACKING) {		// Si passif
			_wasHit = false;
		}
	}

	_lstSprites.clear();
	_lstSprites.push_back(_mainCharacter->getSprite());

	for (int i = 0; i < _gardes.size(); i++) {	// Ajoute garde au vecteur de sprites 
		if (_gardes[i].getState() != DEAD)
			_lstSprites.push_back(_gardes[i].getSprite());
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
	if (_hud->getNbrVies() <= 0)
		_data->machine.addState(stateRef(new gameOverState(_data, _hud->getScore(), false)), true);
}

/// <summary>
/// Clear, dessine et display la fen�tre
/// </summary>
/// <param name="dt"></param>
void gameState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_wall->drawBackWall();
	_door->draw();

	for (int i = 0; i < _lstSprites.size(); i++)
		_data->window.draw(_lstSprites[i]);

	_wall->draw();
	_hud->draw();

	if (_hasKey)		// Si a cl�
		_data->window.draw(_key);

	_data->window.display();
}