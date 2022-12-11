#include "gameState.h"
#include "shopState.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
gameState::gameState(gameDataRef data) : _data(data)
{
	_mainCharacter = nullptr;
	_garde = nullptr;
	_wall = nullptr;
	_hud = nullptr;
	_door = nullptr;
	_minotaur = nullptr;
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
	_garde = nullptr;
}

/// <summary>
/// Destructeur
/// </summary>
gameState::~gameState()
{
	delete _mainCharacter;
	delete _garde;
	delete _wall;
	delete _door;
	delete _minotaur;
}

/// <summary>
/// Initilisae les diff�rents objets du state
/// </summary>
void gameState::init()
{
	_background.setTexture(_data->assets.getTexture("game background 1"));

	// Pointeurs
	if (_hud == nullptr) 
		_hud = new hud(_data, 1, 0);

	_mainCharacter = new mainCharacter(_data);
	_garde = new gardeEnemy(_data);
	_wall = new wall(_data);
	_door = new door(_data);
	_minotaur = new minotaur(_data);
	_mainCharacter = new mainCharacter(_data, _hud->getNbrVies());

	_lstSprites.push_back(_mainCharacter->getSprite());
	_lstSprites.push_back(_minotaur->getSprite());
	_lstSprites.push_back(_garde->getSprite());

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
}

/// <summary>
/// Mets-�-jour les objets du state
/// </summary>
/// <param name="dt"></param>
void gameState::update(float dt)
{
	/*Vector2f distance = _collision.getDistance(_mainCharacter->getSprite(), _minotaur->getSprite());

	if (abs(distance.x) > abs(distance.y) && distance.x < 0) {
		_minotaur->move(Keyboard::A, MINOTAUR_WALK_TIME);
	}
	else if (abs(distance.x) > abs(distance.y)) {
		_minotaur->move(Keyboard::D, MINOTAUR_WALK_TIME);
	}
	else if (distance.y < 0) {
		_minotaur->move(Keyboard::W, MINOTAUR_WALK_TIME);
	}
	else if (distance.y > 0) {
		_minotaur->move(Keyboard::S, MINOTAUR_WALK_TIME);
	}
	else {
		_minotaur->setState(IDLE);
	}*/

	/*Vector2f distance = _collision.getDistance(_mainCharacter->getSprite(), _garde->getSprite());

	if (abs(distance.x) > abs(distance.y) && distance.x < 5 ) {
		_garde->move(Keyboard::A, ENEMY_WALK_TIME);
	}
	if (abs(distance.x) > abs(distance.y) && distance.x > 5) {
		_garde->move(Keyboard::D, ENEMY_WALK_TIME);
	}
	if (distance.y < 0 && distance.y < 5) {
		_garde->move(Keyboard::W, ENEMY_WALK_TIME);
	}
	if (distance.y > 0 && distance.y > 5) {
		_garde->move(Keyboard::S, ENEMY_WALK_TIME);
	}
	else {
		_garde->setState(IDLE);
	}*/


	if (Keyboard::isKeyPressed(Keyboard::D)) 
		cout << "D" << endl;
		_mainCharacter->move(Keyboard::D, SKELETON_WALK_TIME);

	if (Keyboard::isKeyPressed(Keyboard::A))
		_mainCharacter->move(Keyboard::A, SKELETON_WALK_TIME);

	if (Keyboard::isKeyPressed(Keyboard::W))
		_mainCharacter->move(Keyboard::W, SKELETON_WALK_TIME);

	if (Keyboard::isKeyPressed(Keyboard::S))
		_mainCharacter->move(Keyboard::S, SKELETON_WALK_TIME);

	_mainCharacter->update(dt);
	_garde->update(dt);
	_minotaur->update(dt);

	// Collision porte
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _door->getSprite(), 5.0f, 0.3f)) {
		_hud->addRoom();
		_data->machine.addState(stateRef(new shopState(_data, _hud)), true);
	}

	// Collision mur du haut
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 2.5f, 2.5f, _wall->getWallUp(), 1.0f, 0.1f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y + MOVEMENT_DISTANCE);
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

	_lstSprites[0] = _mainCharacter->getSprite();
	_lstSprites[1] = _garde->getSprite();
	_lstSprites[2] = _minotaur->getSprite();

	// Collision mur droit
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 4.0f, 5.0f, _wall->getWallRight(), 1.0f, 1.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - 20, _mainCharacter->getSprite().getPosition().y);
	}

	// Collision ennemis

	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _garde->getSprite(), 3.0f, 10.0f))
	{
		//enleve heart
		_toucher = true;
		if (!_toucher)
		{
			_toucher = true;
			_hud->removeHeart(1);
			if (_hud->getNbrVies() == 0)
			{
				cout << " mort";
			}
		}
		else
		{
			_toucher =false ;
		}

	// Gestion de l'ordre d'affichage 
	for (int i = 0; i < _lstSprites.size() - 1; i++) {
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
/// Clear, dessine le background et display la fen�tre
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

	//_minotaur->draw();
	_garde->draw();
	_mainCharacter->draw();
	_wall->draw();
	_garde->draw();
	_minotaur->draw();
	_hud->draw();
	_data->window.display();
}
