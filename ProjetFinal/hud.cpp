#include "hud.h"

/// <summary>
/// 
/// </summary>
/// <param name="score"></param>
hud::hud(gameDataRef data, int score) : _data(data)
{
	_score = score;

	_scoreSprite = Text(to_string(_score), _data->assets.getFont("pixel art font"), 50);
	_scoreSprite.setFillColor(Color::White);
	_scoreSprite.setPosition((SCREEN_WIDTH - _scoreSprite.getGlobalBounds().width - 60), 50);
}

/// <summary>
/// 
/// </summary>
void hud::setScore(int score)
{
	_score = score;
	_scoreSprite.setString(to_string(_score));
}

/// <summary>
/// 
/// </summary>
/// <param name="score"></param>
void hud::addScore(int score)
{
	_score += score;
	_scoreSprite.setString(to_string(_score));
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int hud::getScore() const
{
	return _score;
}

/// <summary>
/// 
/// </summary>
void hud::draw() const
{
	_data->window.draw(_scoreSprite);
}