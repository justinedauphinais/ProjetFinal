#include "splashState.h"

/// <summary>
/// Le constructeur utilise les : pour initialiser _data avant même l’exécution du contenu{}
/// </summary>
/// <param name="data"></param>
splashState::splashState(gameDataRef data) : _data(data)
{
}

/// <summary>
/// Load l’image du background à l’aide du assetManager ds _data et la set au Sprite
/// </summary>
void splashState::init()
{
	// Background
	_data->assets.loadTexture("logo state background", SPLASH_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.getTexture("logo state background"));

	// Meow
	_data->assets.loadTexture("meow splash screen", SPLASH_STATE_MEOW);

	// Nom de Jimmi
	_data->assets.loadFont("pixel art font", PIXEL_ART_FONT);
	_nomJimmi = Text("Jimmi Lancelot", _data->assets.getFont("pixel art font"), 50);
	_nomJimmi.setOrigin(_nomJimmi.getGlobalBounds().width / 2, _nomJimmi.getGlobalBounds().height / 2);
	_nomJimmi.setPosition(SCREEN_WIDTH / 2 + 200, 600);
	_nomJimmi.setFillColor(Color::Black);

	// Nom de Justine
	_nomJustine = Text("Justine Dauphinais", _data->assets.getFont("pixel art font"), 50);
	_nomJustine.setOrigin(_nomJimmi.getGlobalBounds().width / 2, _nomJimmi.getGlobalBounds().height / 2);
	_nomJustine.setPosition(SCREEN_WIDTH / 2 + 200, 500);
	_nomJustine.setFillColor(Color::Black);
}

/// <summary>
/// Fenêtre qui reste ouverte tant qu’elle n’est pas fermée
/// </summary>
void splashState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
	}
}

/// <summary>
/// Gère le délai, après 3 secondes, on veut afficher la prochaine fenêtre
/// </summary>
/// <param name="dt"></param>
void splashState::update(float dt)
{
	if (_clockMeow.getElapsedTime().asSeconds() > 1) {
		_meow.setTexture(_data->assets.getTexture("meow splash screen"));
		_meow.setPosition(448, 314);
	}

	if (_clock.getElapsedTime().asSeconds() > LOGO_STATE_SHOW_TIME)
	{
		//todo call the menu state
		_data->machine.addState(stateRef(new mainMenuState(_data)), true);
	}
}

/// <summary>
/// Clear, dessine le background et display la fenêtre. (dt n’est pas utilisé ici)
/// </summary>
/// <param name="dt"></param>
void splashState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_nomJimmi);
	_data->window.draw(_nomJustine);
	_data->window.draw(_meow);
	_data->window.display();
}