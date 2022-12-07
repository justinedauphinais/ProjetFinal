#include "gameState.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
gameState::gameState(gameDataRef data) : _data(data)
{
	_mainCharacter = nullptr;
	_enemys = nullptr;
	_wall = nullptr;
	_hud = nullptr;
	_door = nullptr;
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
	delete _enemys;
	delete _wall;
	delete _door;
}

/// <summary>
/// Initilisae les diff�rents objets du state
/// </summary>
void gameState::init()
{
	// Background
	_data->assets.loadTexture("game background", GAME_BACKGROUND_TEMP);
	_background.setTexture(_data->assets.getTexture("game background"));

	// Walls
	_data->assets.loadTexture("wall up", GAME_FOREGROUND_UP_DOWN_TEMP);
	_data->assets.loadTexture("wall down", GAME_FOREGROUND_UP_DOWN_TEMP);
	_data->assets.loadTexture("wall left", GAME_FOREGROUND_LEFT_RIGHT_TEMP);
	_data->assets.loadTexture("wall right", GAME_FOREGROUND_LEFT_RIGHT_TEMP);

	// Hud
	_data->assets.loadTexture("life hearts", GAME_HEARTS_FILEPATH);
	_data->assets.loadFont("pixel art font", PIXEL_ART_FONT);			// A ENLEVER LORSQUE LE JEU EST COMPLET

	// Main character
	#pragma region Main Character assets
	// Idle
	_data->assets.loadTexture("skeleton idle frame right 1", SKELETON_IDLE_FRAME_RIGHT_1);
	_data->assets.loadTexture("skeleton idle frame right 2", SKELETON_IDLE_FRAME_RIGHT_2);
	_data->assets.loadTexture("skeleton idle frame right 3", SKELETON_IDLE_FRAME_RIGHT_3);
	_data->assets.loadTexture("skeleton idle frame right 4", SKELETON_IDLE_FRAME_RIGHT_4);
	_data->assets.loadTexture("skeleton idle frame right 5", SKELETON_IDLE_FRAME_RIGHT_5);
	_data->assets.loadTexture("skeleton idle frame right 6", SKELETON_IDLE_FRAME_RIGHT_6);
	_data->assets.loadTexture("skeleton idle frame right 7", SKELETON_IDLE_FRAME_RIGHT_7);
	_data->assets.loadTexture("skeleton idle frame right 8", SKELETON_IDLE_FRAME_RIGHT_8);
	_data->assets.loadTexture("skeleton idle frame right 9", SKELETON_IDLE_FRAME_RIGHT_9);
	_data->assets.loadTexture("skeleton idle frame right 10", SKELETON_IDLE_FRAME_RIGHT_10);
	_data->assets.loadTexture("skeleton idle frame right 11", SKELETON_IDLE_FRAME_RIGHT_11);

	_data->assets.loadTexture("skeleton idle frame left 1", SKELETON_IDLE_FRAME_LEFT_1);
	_data->assets.loadTexture("skeleton idle frame left 2", SKELETON_IDLE_FRAME_LEFT_2);
	_data->assets.loadTexture("skeleton idle frame left 3", SKELETON_IDLE_FRAME_LEFT_3);
	_data->assets.loadTexture("skeleton idle frame left 4", SKELETON_IDLE_FRAME_LEFT_4);
	_data->assets.loadTexture("skeleton idle frame left 5", SKELETON_IDLE_FRAME_LEFT_5);
	_data->assets.loadTexture("skeleton idle frame left 6", SKELETON_IDLE_FRAME_LEFT_6);
	_data->assets.loadTexture("skeleton idle frame left 7", SKELETON_IDLE_FRAME_LEFT_7);
	_data->assets.loadTexture("skeleton idle frame left 8", SKELETON_IDLE_FRAME_LEFT_8);
	_data->assets.loadTexture("skeleton idle frame left 9", SKELETON_IDLE_FRAME_LEFT_9);
	_data->assets.loadTexture("skeleton idle frame left 10", SKELETON_IDLE_FRAME_LEFT_10);
	_data->assets.loadTexture("skeleton idle frame left 11", SKELETON_IDLE_FRAME_LEFT_11);

	// Walking
	_data->assets.loadTexture("skeleton walking frame left1", SKELETON_WALK_FRAME_LEFT_1);
	_data->assets.loadTexture("skeleton walking frame left2", SKELETON_WALK_FRAME_LEFT_2);
	_data->assets.loadTexture("skeleton walking frame left3", SKELETON_WALK_FRAME_LEFT_3);
	_data->assets.loadTexture("skeleton walking frame left4", SKELETON_WALK_FRAME_LEFT_4);
	_data->assets.loadTexture("skeleton walking frame left5", SKELETON_WALK_FRAME_LEFT_5);
	_data->assets.loadTexture("skeleton walking frame left6", SKELETON_WALK_FRAME_LEFT_6);
	_data->assets.loadTexture("skeleton walking frame left7", SKELETON_WALK_FRAME_LEFT_7);
	_data->assets.loadTexture("skeleton walking frame left8", SKELETON_WALK_FRAME_LEFT_8);
	_data->assets.loadTexture("skeleton walking frame left9", SKELETON_WALK_FRAME_LEFT_9);
	_data->assets.loadTexture("skeleton walking frame left10", SKELETON_WALK_FRAME_LEFT_10);
	_data->assets.loadTexture("skeleton walking frame left11", SKELETON_WALK_FRAME_LEFT_11);
	_data->assets.loadTexture("skeleton walking frame left12", SKELETON_WALK_FRAME_LEFT_12);
	_data->assets.loadTexture("skeleton walking frame right1", SKELETON_WALK_FRAME_RIGHT_1);
	_data->assets.loadTexture("skeleton walking frame right2", SKELETON_WALK_FRAME_RIGHT_2);
	_data->assets.loadTexture("skeleton walking frame right3", SKELETON_WALK_FRAME_RIGHT_3);
	_data->assets.loadTexture("skeleton walking frame right4", SKELETON_WALK_FRAME_RIGHT_4);
	_data->assets.loadTexture("skeleton walking frame right5", SKELETON_WALK_FRAME_RIGHT_5);
	_data->assets.loadTexture("skeleton walking frame right6", SKELETON_WALK_FRAME_RIGHT_6);
	_data->assets.loadTexture("skeleton walking frame right7", SKELETON_WALK_FRAME_RIGHT_7);
	_data->assets.loadTexture("skeleton walking frame right8", SKELETON_WALK_FRAME_RIGHT_8);
	_data->assets.loadTexture("skeleton walking frame right9", SKELETON_WALK_FRAME_RIGHT_9);
	_data->assets.loadTexture("skeleton walking frame right10", SKELETON_WALK_FRAME_RIGHT_10);
	_data->assets.loadTexture("skeleton walking frame right11", SKELETON_WALK_FRAME_RIGHT_11);
	_data->assets.loadTexture("skeleton walking frame right12", SKELETON_WALK_FRAME_RIGHT_12);

	// Attacking
	_data->assets.loadTexture("skeleton attacking frame right1", SKELETON_ATTAQUE_FRAME_RIGHT_1);
	_data->assets.loadTexture("skeleton attacking frame right2", SKELETON_ATTAQUE_FRAME_RIGHT_2);
	_data->assets.loadTexture("skeleton attacking frame right3", SKELETON_ATTAQUE_FRAME_RIGHT_3);
	_data->assets.loadTexture("skeleton attacking frame right4", SKELETON_ATTAQUE_FRAME_RIGHT_4);
	_data->assets.loadTexture("skeleton attacking frame right5", SKELETON_ATTAQUE_FRAME_RIGHT_5);
	_data->assets.loadTexture("skeleton attacking frame right6", SKELETON_ATTAQUE_FRAME_RIGHT_6);
	_data->assets.loadTexture("skeleton attacking frame right7", SKELETON_ATTAQUE_FRAME_RIGHT_7);
	_data->assets.loadTexture("skeleton attacking frame right8", SKELETON_ATTAQUE_FRAME_RIGHT_8);
	_data->assets.loadTexture("skeleton attacking frame right9", SKELETON_ATTAQUE_FRAME_RIGHT_9);
	_data->assets.loadTexture("skeleton attacking frame right10", SKELETON_ATTAQUE_FRAME_RIGHT_10);
	_data->assets.loadTexture("skeleton attacking frame right11", SKELETON_ATTAQUE_FRAME_RIGHT_11);
	_data->assets.loadTexture("skeleton attacking frame right12", SKELETON_ATTAQUE_FRAME_RIGHT_12);
	_data->assets.loadTexture("skeleton attacking frame right13", SKELETON_ATTAQUE_FRAME_RIGHT_13);
	_data->assets.loadTexture("skeleton attacking frame right14", SKELETON_ATTAQUE_FRAME_RIGHT_14);
	_data->assets.loadTexture("skeleton attacking frame right15", SKELETON_ATTAQUE_FRAME_RIGHT_15);
	_data->assets.loadTexture("skeleton attacking frame right16", SKELETON_ATTAQUE_FRAME_RIGHT_16);
	_data->assets.loadTexture("skeleton attacking frame right17", SKELETON_ATTAQUE_FRAME_RIGHT_17);
	_data->assets.loadTexture("skeleton attacking frame right18", SKELETON_ATTAQUE_FRAME_RIGHT_18);
	_data->assets.loadTexture("skeleton attacking frame left1", SKELETON_ATTAQUE_FRAME_LEFT_1);
	_data->assets.loadTexture("skeleton attacking frame left2", SKELETON_ATTAQUE_FRAME_LEFT_2);
	_data->assets.loadTexture("skeleton attacking frame left3", SKELETON_ATTAQUE_FRAME_LEFT_3);
	_data->assets.loadTexture("skeleton attacking frame left4", SKELETON_ATTAQUE_FRAME_LEFT_4);
	_data->assets.loadTexture("skeleton attacking frame left5", SKELETON_ATTAQUE_FRAME_LEFT_5);
	_data->assets.loadTexture("skeleton attacking frame left6", SKELETON_ATTAQUE_FRAME_LEFT_6);
	_data->assets.loadTexture("skeleton attacking frame left7", SKELETON_ATTAQUE_FRAME_LEFT_7);
	_data->assets.loadTexture("skeleton attacking frame left8", SKELETON_ATTAQUE_FRAME_LEFT_8);
	_data->assets.loadTexture("skeleton attacking frame left9", SKELETON_ATTAQUE_FRAME_LEFT_9);
	_data->assets.loadTexture("skeleton attacking frame left10", SKELETON_ATTAQUE_FRAME_LEFT_10);
	_data->assets.loadTexture("skeleton attacking frame left11", SKELETON_ATTAQUE_FRAME_LEFT_11);
	_data->assets.loadTexture("skeleton attacking frame left12", SKELETON_ATTAQUE_FRAME_LEFT_12);
	_data->assets.loadTexture("skeleton attacking frame left13", SKELETON_ATTAQUE_FRAME_LEFT_13);
	_data->assets.loadTexture("skeleton attacking frame left14", SKELETON_ATTAQUE_FRAME_LEFT_14);
	_data->assets.loadTexture("skeleton attacking frame left15", SKELETON_ATTAQUE_FRAME_LEFT_15);
	_data->assets.loadTexture("skeleton attacking frame left16", SKELETON_ATTAQUE_FRAME_LEFT_16);
	_data->assets.loadTexture("skeleton attacking frame left17", SKELETON_ATTAQUE_FRAME_LEFT_17);
	_data->assets.loadTexture("skeleton attacking frame left18", SKELETON_ATTAQUE_FRAME_LEFT_18);
#pragma endregion
		// Attacking
		_data->assets.loadTexture("skeleton attacking frame right1", SKELETON_ATTAQUE_FRAME_RIGHT_1);
		_data->assets.loadTexture("skeleton attacking frame right2", SKELETON_ATTAQUE_FRAME_RIGHT_2);
		_data->assets.loadTexture("skeleton attacking frame right3", SKELETON_ATTAQUE_FRAME_RIGHT_3);
		_data->assets.loadTexture("skeleton attacking frame right4", SKELETON_ATTAQUE_FRAME_RIGHT_4);
		_data->assets.loadTexture("skeleton attacking frame right5", SKELETON_ATTAQUE_FRAME_RIGHT_5);
		_data->assets.loadTexture("skeleton attacking frame right6", SKELETON_ATTAQUE_FRAME_RIGHT_6);
		_data->assets.loadTexture("skeleton attacking frame right7", SKELETON_ATTAQUE_FRAME_RIGHT_7);
		_data->assets.loadTexture("skeleton attacking frame right8", SKELETON_ATTAQUE_FRAME_RIGHT_8);
		_data->assets.loadTexture("skeleton attacking frame right9", SKELETON_ATTAQUE_FRAME_RIGHT_9);
		_data->assets.loadTexture("skeleton attacking frame right10", SKELETON_ATTAQUE_FRAME_RIGHT_10);
		_data->assets.loadTexture("skeleton attacking frame right11", SKELETON_ATTAQUE_FRAME_RIGHT_11);
		_data->assets.loadTexture("skeleton attacking frame right12", SKELETON_ATTAQUE_FRAME_RIGHT_12);
		_data->assets.loadTexture("skeleton attacking frame right13", SKELETON_ATTAQUE_FRAME_RIGHT_13);
		_data->assets.loadTexture("skeleton attacking frame right14", SKELETON_ATTAQUE_FRAME_RIGHT_14);
		_data->assets.loadTexture("skeleton attacking frame right15", SKELETON_ATTAQUE_FRAME_RIGHT_15);
		_data->assets.loadTexture("skeleton attacking frame right16", SKELETON_ATTAQUE_FRAME_RIGHT_16);
		_data->assets.loadTexture("skeleton attacking frame right17", SKELETON_ATTAQUE_FRAME_RIGHT_17);
		_data->assets.loadTexture("skeleton attacking frame right18", SKELETON_ATTAQUE_FRAME_RIGHT_18);
		_data->assets.loadTexture("skeleton attacking frame left1", SKELETON_ATTAQUE_FRAME_LEFT_1);
		_data->assets.loadTexture("skeleton attacking frame left2", SKELETON_ATTAQUE_FRAME_LEFT_2);
		_data->assets.loadTexture("skeleton attacking frame left3", SKELETON_ATTAQUE_FRAME_LEFT_3);
		_data->assets.loadTexture("skeleton attacking frame left4", SKELETON_ATTAQUE_FRAME_LEFT_4);
		_data->assets.loadTexture("skeleton attacking frame left5", SKELETON_ATTAQUE_FRAME_LEFT_5);
		_data->assets.loadTexture("skeleton attacking frame left6", SKELETON_ATTAQUE_FRAME_LEFT_6);
		_data->assets.loadTexture("skeleton attacking frame left7", SKELETON_ATTAQUE_FRAME_LEFT_7);
		_data->assets.loadTexture("skeleton attacking frame left8", SKELETON_ATTAQUE_FRAME_LEFT_8);
		_data->assets.loadTexture("skeleton attacking frame left9", SKELETON_ATTAQUE_FRAME_LEFT_9);
		_data->assets.loadTexture("skeleton attacking frame left10", SKELETON_ATTAQUE_FRAME_LEFT_10);
		_data->assets.loadTexture("skeleton attacking frame left11", SKELETON_ATTAQUE_FRAME_LEFT_11);
		_data->assets.loadTexture("skeleton attacking frame left12", SKELETON_ATTAQUE_FRAME_LEFT_12);
		_data->assets.loadTexture("skeleton attacking frame left13", SKELETON_ATTAQUE_FRAME_LEFT_13);
		_data->assets.loadTexture("skeleton attacking frame left14", SKELETON_ATTAQUE_FRAME_LEFT_14);
		_data->assets.loadTexture("skeleton attacking frame left15", SKELETON_ATTAQUE_FRAME_LEFT_15);
		_data->assets.loadTexture("skeleton attacking frame left16", SKELETON_ATTAQUE_FRAME_LEFT_16);
		_data->assets.loadTexture("skeleton attacking frame left17", SKELETON_ATTAQUE_FRAME_LEFT_17);
		_data->assets.loadTexture("skeleton attacking frame left18", SKELETON_ATTAQUE_FRAME_LEFT_18);
	#pragma endregion
 #pragma region enemy asset

		_data->assets.loadTexture("enemy idle frame left1", ENEMY_IDLE_FRAME_LEFT_1);
		_data->assets.loadTexture("enemy idle frame left2", ENEMY_IDLE_FRAME_LEFT_2);
		_data->assets.loadTexture("enemy idle frame left3", ENEMY_IDLE_FRAME_LEFT_3);
		_data->assets.loadTexture("enemy idle frame left4", ENEMY_IDLE_FRAME_LEFT_4);
		_data->assets.loadTexture("enemy idle frame left5", ENEMY_IDLE_FRAME_LEFT_5);

		_data->assets.loadTexture("enemy idle frame right1", ENEMY_IDLE_FRAME_RIGHT_1);
		_data->assets.loadTexture("enemy idle frame right2", ENEMY_IDLE_FRAME_RIGHT_2);
		_data->assets.loadTexture("enemy idle frame right3", ENEMY_IDLE_FRAME_RIGHT_3);
		_data->assets.loadTexture("enemy idle frame right4", ENEMY_IDLE_FRAME_RIGHT_4);
		_data->assets.loadTexture("enemy idle frame right5", ENEMY_IDLE_FRAME_RIGHT_5);

		_data->assets.loadTexture("enemy attack frame left1", ENEMY_ATTACK_FRAME_LEFT_1);
		_data->assets.loadTexture("enemy attack frame left2", ENEMY_ATTACK_FRAME_LEFT_2);
		_data->assets.loadTexture("enemy attack frame left3", ENEMY_ATTACK_FRAME_LEFT_3);
		_data->assets.loadTexture("enemy attack frame left4", ENEMY_ATTACK_FRAME_LEFT_4);
		_data->assets.loadTexture("enemy attack frame left5", ENEMY_ATTACK_FRAME_LEFT_5);
		_data->assets.loadTexture("enemy attack frame left6", ENEMY_ATTACK_FRAME_LEFT_6);

		_data->assets.loadTexture("enemy attack frame right1", ENEMY_ATTACK_FRAME_RIGHT_1);
		_data->assets.loadTexture("enemy attack frame right2", ENEMY_ATTACK_FRAME_RIGHT_2);
		_data->assets.loadTexture("enemy attack frame right3", ENEMY_ATTACK_FRAME_RIGHT_3);
		_data->assets.loadTexture("enemy attack frame right4", ENEMY_ATTACK_FRAME_RIGHT_4);
		_data->assets.loadTexture("enemy attack frame right5", ENEMY_ATTACK_FRAME_RIGHT_5);
		_data->assets.loadTexture("enemy attack frame right6", ENEMY_ATTACK_FRAME_RIGHT_6);
#pragma endregion

	// Porte
	_data->assets.loadTexture("closed door", GAME_DOOR_CLOSED);
	_data->assets.loadTexture("opened door", GAME_DOOR_OPEN);


	// Pointeurs
	if (_hud == nullptr) 
		_hud = new hud(_data, 1, 0);

	_mainCharacter = new mainCharacter(_data);
	_enemys = new enemys(_data);
	_wall = new wall(_data);
	_door = new door(_data);
	_mainCharacter = new mainCharacter(_data, _hud->getNbrVies());

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
		else if (event.type == Event::KeyPressed) {			// Mouvement

			if (Keyboard::isKeyPressed(Keyboard::D)) {
				_mainCharacter->move(Keyboard::D);
			}

			if (Keyboard::isKeyPressed(Keyboard::A)) {
				_mainCharacter->move(Keyboard::A);
			}

			if (Keyboard::isKeyPressed(Keyboard::W)) {
				_mainCharacter->move(Keyboard::W);
			}

			if (Keyboard::isKeyPressed(Keyboard::S)) {
				_mainCharacter->move(Keyboard::S);
			}
		}
		else if (Mouse::isButtonPressed(Mouse::Left)) {		// Attaque
			_mainCharacter->attack();
		}
		else if (event.type == Event::KeyReleased) {		// Idle
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
	_mainCharacter->update(dt);
	_enemys->setState(IDLE);

	// Collision porte
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _door->getSprite(), 1.0f, 0.2f)) {
		_hud->addRoom();
		_hud->removeHeart(2);
		_data->machine.addState(stateRef(new gameState(_data, _hud)), true);
	}

	_enemys->update(dt);
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
	_mainCharacter->draw();
	_wall->draw();
	_enemys->draw();
	_hud->draw();
	_data->window.display();
}
