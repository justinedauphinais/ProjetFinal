#include "gameState.h"

/// <summary>
/// Le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
/// </summary>
/// <param name="data"></param>
gameState::gameState(gameDataRef data) : _data(data)
{
	_mainCharacter = nullptr;
}

/// <summary>
/// 
/// </summary>
gameState::~gameState()
{
	delete _mainCharacter;
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
	_data->assets.loadTexture("game foreground", GAME_FOREGROUND_TEMP);
	_foreground.setTexture(_data->assets.getTexture("game foreground"));
	_foreground.setPosition(47, 916);

	// Main character
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

	// Pointeurs
	_mainCharacter = new mainCharacter(_data);
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
				_mainCharacter->move(directions::RIGHT);
			}
			else if (Keyboard::isKeyPressed(Keyboard::A)) {
				_mainCharacter->move(directions::LEFT);
			}
			else if (Keyboard::isKeyPressed(Keyboard::W)) {
				_mainCharacter->move(directions::TOP);
			}
			else if (Keyboard::isKeyPressed(Keyboard::S)) {
				_mainCharacter->move(directions::BOTTOM);
			}
		}
		else if (event.type == Event::KeyReleased) {

		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void gameState::update(float dt)
{
}

/// <summary>
/// Clear, dessine le background et display la fenêtre
/// </summary>
/// <param name="dt"></param>
void gameState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_mainCharacter->draw();

	// Le reste va ici

	_data->window.draw(_foreground);
	_data->window.display();
}
