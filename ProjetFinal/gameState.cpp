#include "gameState.h"

/// <summary>
/// Le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
/// </summary>
/// <param name="data"></param>
gameState::gameState(gameDataRef data) : _data(data)
{
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

	// Le reste va ici

	_data->window.draw(_foreground);
	_data->window.display();
}
