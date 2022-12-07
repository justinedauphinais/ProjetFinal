#include "hud.h"

/// <summary>
/// 
/// </summary>
/// <param name="score"></param>
hud::hud(gameDataRef data, int score, int nbCoeurs) : _data(data)
{
	_score = score;

	// Score
	_scoreSprite = Text(to_string(_score), _data->assets.getFont("pixel art font"), 50);
	_scoreSprite.setFillColor(Color::White);
	_scoreSprite.setPosition((SCREEN_WIDTH - _scoreSprite.getGlobalBounds().width - 60), 50);

	// Coeurs
	_heart = Sprite(_data->assets.getTexture("life hearts"));
	_heart.setPosition(50, 50);
	_heart.setScale(4, 4);

	for (int i = 0; i < nbCoeurs; i++) {		// Ajoute les coeurs
		_hearts.push_back(_heart);
		_heart.move(80, 0);
	}
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
/// <param name="nb"></param>
/// <returns></returns>
bool hud::removeHeart(int nb)
{
	for (int i = 0; i < nb; i++) {	// Enlève le coeur et replace le dernier
		_hearts.pop_back();
		_heart.move(-80, 0);
	}

	return _hearts.size() == 0;
}

/// <summary>
/// 
/// </summary>
/// <param name="nb"></param>
void hud::addHeart(int nb)
{
	for (int i = 0; i < nb; i++) {
		_hearts.push_back(_heart);
		_heart.move(80, 0);
	}
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
	for (int i = 0; i < _hearts.size(); i++) {
		_data->window.draw(_hearts[i]);
	}
}