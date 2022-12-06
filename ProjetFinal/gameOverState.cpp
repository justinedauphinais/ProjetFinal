#include "gameOverState.h"

/// <summary>
/// 
/// </summary>
/// <param name="data"></param>
/// <param name="score"></param>
gameOverState::gameOverState(gameDataRef data, int score) : _data(data)
{
	_score = score;
	_color = 0;
}

/// <summary>
/// 
/// </summary>
gameOverState::~gameOverState()
{
}

/// <summary>
/// 
/// </summary>
void gameOverState::init()
{
	_data->assets.loadFont("pixel art font", PIXEL_ART_FONT);

	// You died
	_youDiedText = Text("You Died", _data->assets.getFont("pixel art font"), 150);
	_youDiedText.setFillColor(Color::Color(255, 0, 0, _color));
	_youDiedText.setPosition((SCREEN_WIDTH / 2) - (_youDiedText.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_youDiedText.getGlobalBounds().height / 2));

	// Score
	_scoreText = Text("Score : " + to_string(_score), _data->assets.getFont("pixel art font"), 50);
	_scoreText.setFillColor(Color::Black);
	_scoreText.setPosition((SCREEN_WIDTH / 2 - (_scoreText.getGlobalBounds().width / 2)), (SCREEN_HEIGHT / 2 + 100));

	// High score
	_highScoreText = Text("High score : " + to_string(_score), _data->assets.getFont("pixel art font"), 50);
	_highScoreText.setFillColor(Color::Black);
	_highScoreText.setPosition((SCREEN_WIDTH / 2 - (_highScoreText.getGlobalBounds().width / 2)), (SCREEN_HEIGHT / 2 + 175));
}

/// <summary>
/// 
/// </summary>
void gameOverState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
		else if (Mouse::isButtonPressed(Mouse::Left)) {
			_color = 255;
			_youDiedText.setFillColor(Color::Color(255, 0, 0, _color));
			_scoreText.setFillColor(Color::Red);
			_highScoreText.setFillColor(Color::Red);
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void gameOverState::update(float dt)
{
	if (_color < 255) {
		_youDiedText.setFillColor(Color::Color(255, 0, 0, _color++));
	}

	if (_clock.getElapsedTime().asSeconds() > 3.0f) {
		_scoreText.setFillColor(Color::Red);
		_highScoreText.setFillColor(Color::Red);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="dt"></param>
void gameOverState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_youDiedText);
	_data->window.draw(_scoreText);
	_data->window.draw(_highScoreText);
	_data->window.display();
}
