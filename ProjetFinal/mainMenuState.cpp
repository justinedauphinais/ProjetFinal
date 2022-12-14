#include "mainMenuState.h"
#include "loadingState.h"

#include "introductionState.h"

/// <summary>
/// Le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
/// </summary>
/// <param name="data"></param>
mainMenuState::mainMenuState(gameDataRef data) : _data(data)
{
}

/// <summary>
/// Load les sprites à l’aide du assetManager ds _data et la set au Sprite
/// </summary>
void mainMenuState::init()
{
	// Background
	_data->assets.loadTexture("main menu background", MAIN_MENU_BACKGROUND);
	_background.setTexture(_data->assets.getTexture("main menu background"));

	// Play button
	_data->assets.loadTexture("main menu play button", PLAY_BUTTON_FILEPATH);
	_playButton.setTexture(_data->assets.getTexture("main menu play button"));
	_playButton.setScale(6.0f, 6.0f);
	_playButton.setPosition(((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width) - 15),
		((SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2)));

	// Stop button
	_data->assets.loadTexture("main menu stop button", STOP_BUTTON_FILEPATH);
	_stopButton.setTexture(_data->assets.getTexture("main menu stop button"));
	_stopButton.setScale(6.0f, 6.0f);
	_stopButton.setPosition(((SCREEN_WIDTH / 2) + 15),
		((SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2)));

	// Title
	_data->assets.loadFont("main menu font", MAIN_MENU_FONT);

	_title = Text("The Catacombs of Yharnam", _data->assets.getFont("main menu font"), 300);
	_title.setFillColor(Color::Color(206, 196, 188));
	_title.setPosition(((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2)), 100);
}

/// <summary>
/// Fenêtre qui reste ouverte tant qu’elle n’est pas fermée
/// </summary>
void mainMenuState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
		else if (_data->input.isSpriteClicked(_playButton, Mouse::Left, _data->window)) {
			// Create the new state main screen
			//_data->machine.addState(stateRef(new loadingState(_data)), true);
			_data->machine.addState(stateRef(new introductionState(_data)), true);
		}
		else if (_data->input.isSpriteClicked(_stopButton, Mouse::Left, _data->window)) {
			_data->window.close();
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void mainMenuState::update(float dt)
{
}

/// <summary>
/// Clear, dessine le background et display la fenêtre
/// </summary>
/// <param name="dt"></param>
void mainMenuState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_title);
	_data->window.draw(_playButton);
	_data->window.draw(_stopButton);
	_data->window.display();
}
