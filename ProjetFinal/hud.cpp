#include "hud.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="score"></param>
hud::hud(gameDataRef data, int nbrRoom, int score, int money, int nbCoeurs) : _data(data)
{
	_score = score;
	_nbrRoom = nbrRoom;
	_money = money;

	// Score
	_scoreText = Text(to_string(_score), _data->assets.getFont("pixel art font"), 50);
	_scoreText.setFillColor(Color::White);
	_scoreText.setPosition((SCREEN_WIDTH - _scoreText.getGlobalBounds().width - 60), 50);

	_scoreSprite.setTexture(_data->assets.getTexture("kills"));
	_scoreSprite.setScale(4.0f, 4.0f);
	_scoreSprite.setPosition(_scoreText.getPosition().x - 100, _scoreText.getPosition().y - 7);

	// Argent
	_moneyText = Text(to_string(_score), _data->assets.getFont("pixel art font"), 50);
	_moneyText.setFillColor(Color::White);
	_moneyText.setPosition((SCREEN_WIDTH - _moneyText.getGlobalBounds().width - 60), 150);

	_moneySprite.setTexture(_data->assets.getTexture("coin"));
	_moneySprite.setScale(4.0f, 4.0f);
	_moneySprite.setPosition(_moneyText.getPosition().x - 100, _moneyText.getPosition().y - 15);

	// Coeurs
	_heart = Sprite(_data->assets.getTexture("life hearts"));
	_heart.setPosition(50, 50);
	_heart.setScale(4, 4);

	for (int i = 0; i < nbCoeurs; i++) {		// Ajoute les coeurs
		_hearts.push_back(_heart);
		_heart.move(80, 0);
	}

	// Room
	_roomText = Text(to_string(_nbrRoom), _data->assets.getFont("pixel art font"), 50);
	_roomText.setFillColor(Color::Red);
	_roomText.setPosition(((SCREEN_WIDTH / 2) - (_roomText.getGlobalBounds().width / 2)), (SCREEN_HEIGHT - _roomText.getGlobalBounds().height - 50));
}

/// <summary>
/// Set le score
/// </summary>
void hud::setScore(int score)
{
	_score = score;
	_scoreText.setString(to_string(_score));
}

/// <summary>
/// Ajoute du score
/// </summary>
/// <param name="score"></param>
void hud::addScore(int score)
{
	_score += score;
	_scoreText.setString(to_string(_score));
}

/// <summary>
/// Enlève un ou plusieurs coeurs
/// </summary>
/// <param name="nb"></param>
/// <returns></returns>
bool hud::removeHeart(int nb)
{
	for (int i = 0; i < nb && _hearts.size() != 0; i++) {	// Enlève le coeur et replace le dernier
		_hearts.pop_back();
		_heart.move(-80, 0);
	}

	return _hearts.size() == 0;
}

/// <summary>
/// Ajoute un ou plusieurs coeurs
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
/// Set l'argent
/// </summary>
/// <param name="nb"></param>
void hud::setMoney(int nb)
{
	_money = nb;
	_moneyText.setString(to_string(_money));
}

/// <summary>
/// Ajoute de l'argent
/// </summary>
/// <param name="nb"></param>
void hud::addMoney(int nb)
{
	_money += nb;
	_moneyText.setString(to_string(_money));
}

/// <summary>
/// Enlève de l'argent
/// </summary>
/// <param name="nb"></param>
bool hud::removeMoney(int nb)
{
	if (nb > _money)
		return false;

	_money -= nb;
	_moneyText.setString(to_string(_money));

	return true;
}

/// <summary>
/// Ajoute une chambre
/// </summary>
void hud::addRoom()
{
	_nbrRoom++;
	_roomText.setString(to_string(_nbrRoom));
}

/// <summary>
/// Va chercher le score
/// </summary>
/// <returns></returns>
int hud::getScore() const
{
	return _score;
}

/// <summary>
/// Va chercher le nombre de vie
/// </summary>
/// <returns></returns>
int hud::getNbrVies() const
{
	return _hearts.size();
}

/// <summary>
/// Get le numéro de la chambre
/// </summary>
/// <returns></returns>
int hud::getRoom() const
{
	return _nbrRoom;
}

/// <summary>
/// Affiche à l'écran l'objet
/// </summary>
void hud::draw() const
{
	_data->window.draw(_scoreSprite);
	_data->window.draw(_scoreText);
	_data->window.draw(_moneySprite);
	_data->window.draw(_moneyText);

	for (int i = 0; i < _hearts.size(); i++) {
		_data->window.draw(_hearts[i]);
	}

	_data->window.draw(_roomText);
}