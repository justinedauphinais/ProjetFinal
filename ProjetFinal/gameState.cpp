#include "gameState.h"

/// <summary>
/// Le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
/// </summary>
/// <param name="data"></param>
gameState::gameState(gameDataRef data) : _data(data)
{
	_mainCharacter = nullptr;
	_hearts = nullptr;
	_wall = nullptr;
}

/// <summary>
/// 
/// </summary>
gameState::~gameState()
{
	delete _mainCharacter;
	delete _hearts;
	delete _wall;
}

/// <summary>
/// Load les sprites à l’aide du assetManager ds _data et la set au Sprite
/// </summary>
void gameState::init()
{

	// Background
	_data->assets.loadTexture("game background", GAME_BACKGROUND_TEMP);
	_background.setTexture(_data->assets.getTexture("game background"));

	// Foreground
	//_data->assets.loadTexture("game foreground", GAME_FOREGROUND_TEMP);
	//_foreground.setTexture(_data->assets.getTexture("game foreground"));
	//_foreground.setPosition(47, 916);

	//Walls
	_data->assets.loadTexture("wall up", GAME_FOREGROUND_UP_DOWN_TEMP);
	_data->assets.loadTexture("wall down", GAME_FOREGROUND_UP_DOWN_TEMP);
	_data->assets.loadTexture("wall left", GAME_FOREGROUND_LEFT_RIGHT_TEMP);
	_data->assets.loadTexture("wall right", GAME_FOREGROUND_LEFT_RIGHT_TEMP);

	// Main character
	#pragma region Main Character assets
		// Idle
		_data->assets.loadTexture("skeleton idle frame1", SKELETON_IDLE_FRAME_1);
		_data->assets.loadTexture("skeleton idle frame2", SKELETON_IDLE_FRAME_2);
		_data->assets.loadTexture("skeleton idle frame3", SKELETON_IDLE_FRAME_3);
		_data->assets.loadTexture("skeleton idle frame4", SKELETON_IDLE_FRAME_4);
		_data->assets.loadTexture("skeleton idle frame5", SKELETON_IDLE_FRAME_5);
		_data->assets.loadTexture("skeleton idle frame6", SKELETON_IDLE_FRAME_6);
		_data->assets.loadTexture("skeleton idle frame7", SKELETON_IDLE_FRAME_7);
		_data->assets.loadTexture("skeleton idle frame8", SKELETON_IDLE_FRAME_8);
		_data->assets.loadTexture("skeleton idle frame9", SKELETON_IDLE_FRAME_9);
		_data->assets.loadTexture("skeleton idle frame10", SKELETON_IDLE_FRAME_10);
		_data->assets.loadTexture("skeleton idle frame11", SKELETON_IDLE_FRAME_11);

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

	// Pointeurs
	_mainCharacter = new mainCharacter(_data);
	_hearts = new hearts(_data, NBR_LIVES);
	_wall = new wall(_data);
	_gameState = gameStates::ready;
	// Murs
	/*_wall->spawnLeftWall();
	_wall->spawnRightWall();
	_wall->spawnUpWall();
	_wall->spawnDownWall();*/
}

/// <summary>
/// Fenêtre qui reste ouverte tant qu’elle n’est pas fermée
/// </summary>
void gameState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
		else if (event.type == Event::KeyPressed) {

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
		else if (Mouse::isButtonPressed(Mouse::Left)) {
			_mainCharacter->attack();
		}
		else if (event.type == Event::KeyReleased) {
			_mainCharacter->setState(entityStates::IDLE);
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void gameState::update(float dt)
{
	_mainCharacter->update(dt);
	
	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 2.5f, 2.5f, _wall->getWallUp(), 1.0f, 0.1f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y + 20);
	}

	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 3.5f, _wall->getWallDown(), 1.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x, _mainCharacter->getSprite().getPosition().y - 20);
	}

	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 5.0f, 5.0f, _wall->getWallLeft(), 0.7f, 1.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x + 20, _mainCharacter->getSprite().getPosition().y);
	}

	if (_collision.checkSpriteCollision(_mainCharacter->getSprite(), 4.0f, 5.0f, _wall->getWallRight(), 1.0f, 1.0f)) {
		_mainCharacter->setPosition(_mainCharacter->getSprite().getPosition().x - 20, _mainCharacter->getSprite().getPosition().y);
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
	_mainCharacter->draw();
	_wall->draw();
	_hearts->draw();

	// Le reste va ici

	//_data->window.draw(_foreground);
	_data->window.display();
}
