#include "bossRoomState.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
/// <param name="hud"></param>
bossRoomState::bossRoomState(gameDataRef data, hud*& hud) : _data(data)
{
	_hud = hud;
	_mainCharacter = nullptr;
	_wall = nullptr;
	_minotaur = nullptr;
}

/// <summary>
/// Destructeur
/// </summary>
bossRoomState::~bossRoomState()
{
	delete _mainCharacter;
	delete _minotaur;
	delete _wall;
}

/// <summary>
/// 
/// </summary>
void bossRoomState::init()
{
	_background.setTexture(_data->assets.getTexture("game background 2"));

	_mainCharacter = new mainCharacter(_data);
	_minotaur = new minotaur(_data);
	_wall = new wall(_data, 2);
	_mainCharacter = new mainCharacter(_data, _hud->getNbrVies());

	_wasHit = false;
	_hit = false;

	// Son
	if (!_enemyDeadBuffer.loadFromFile(SOUND_BOSS_DEAD))
		cout << "Erreur loading sound effect" << endl;

	_enemyDeadSound.setBuffer(_enemyDeadBuffer);

	if (!_enemyHitBuffer.loadFromFile(SOUND_HIT))
		cout << "Erreur loading sound effect" << endl;

	_enemyHitSound.setBuffer(_enemyHitBuffer);

	if (!_MCHitBuffer.loadFromFile(SOUND_MC_HIT))
		cout << "Erreur loading sound effect" << endl;

	_MCHitSound.setBuffer(_MCHitBuffer);
}

/// <summary>
/// 
/// </summary>
void bossRoomState::handleInput()
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
/// 
/// </summary>
/// <param name="dt"></param>
void bossRoomState::update(float dt)
{
	_minotaur->move(_collision.getDistance(_mainCharacter->getSprite(), _minotaur->getSprite()), dt, 300, 100);

	_mainCharacter->update(dt);
	_minotaur->update(dt);

	if (_mainCharacter->getState() != ATTACKING) {
		_hit = false;

		if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 2.5f, 2.5f, _wall->getWallUp(), 1.0f, 0.1f))			// Collision mur du haut
			_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y + MOVEMENT_DISTANCE);
		else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 3.5f, _wall->getWallDown(), 1.0f))				// Collision mur du bas
			_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y - MOVEMENT_DISTANCE);
		else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _wall->getWallLeft(), 0.7f, 1.0f))	// Collision mur gauche
			_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x + MOVEMENT_DISTANCE, _mainCharacter->getSprite().getPosition().y);
		else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 4.0f, 5.0f, _wall->getWallRight(), 1.0f, 1.0f))	// Collision mur droit
			_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - MOVEMENT_DISTANCE, _mainCharacter->getSprite().getPosition().y);
	}
	else if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), _minotaur->getSprite()) && 
				_minotaur->getState() != HIT && _minotaur->getState() != DEAD && _minotaur->getState() != DYING && !_hit) {
		_hit = true;

		_enemyHitSound.play();
		
		if (_minotaur->removeHearts()) {
			_hud->addScore(5);
			_enemyDeadSound.play();
		}
		
		_minotaur->setState(HIT);
	}

	if (_minotaur->getState() == ATTACKING && !_wasHit && _mainCharacter->getState() != HIT && _collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, 0, 0, _minotaur->getSprite(), 5.0f, 5.0f, 100, 100)) {
		_wasHit = true;
		_mainCharacter->setState(HIT);
		_hud->removeHeart();
		_MCHitSound.play();
	}
	else if (_minotaur->getState() != ATTACKING) {
		_wasHit = false;
	}

	_lstSprites.clear();
	_lstSprites.push_back(_mainCharacter->getSprite());
	
	if (_minotaur->getState() != DEAD) 
		_lstSprites.push_back(_minotaur->getSprite());

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
	else if (_minotaur->getState() == DEAD) 
		_data->machine.addState(stateRef(new gameOverState(_data, _hud->getScore(), true)), true);
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void bossRoomState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_wall->drawBackWall();

	for (int i = 0; i < _lstSprites.size(); i++) {
		_data->window.draw(_lstSprites[i]);
	}

	_wall->draw();
	_hud->draw();
	_data->window.display();
}