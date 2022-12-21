#include "gameOverState.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
/// <param name="score"></param>
gameOverState::gameOverState(gameDataRef data, int score, bool gagne) : _data(data)
{
	_score = score;
	_color = 0;
	_gagne = gagne;
}

/// <summary>
/// Destructeur
/// </summary>
gameOverState::~gameOverState()
{
}

/// <summary>
/// Initialise les différents objets du state
/// </summary>
void gameOverState::init()
{
	_data->assets.loadFont("pixel art font", PIXEL_ART_FONT);

	// Outcome
	if (_gagne) {
		_outcomeText = Text("survécu", _data->assets.getFont("pixel art font"), 150);
	}
	else {
		_outcomeText = Text("péri", _data->assets.getFont("pixel art font"), 150);
	}

	_outcomeText.setFillColor(Color::Color(255, 0, 0, _color));
	_outcomeText.setPosition((SCREEN_WIDTH / 2) - (_outcomeText.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_outcomeText.getGlobalBounds().height / 2));

	// Vous êtes
	_vousEtesText = Text("Vous avez", _data->assets.getFont("pixel art font"), 125);
	_vousEtesText.setFillColor(Color::Color(255, 0, 0));
	_vousEtesText.setPosition((SCREEN_WIDTH / 2) - (_vousEtesText.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_outcomeText.getGlobalBounds().height / 2) - 225);

	// Score
	_scoreText = Text("Score : " + to_string(_score), _data->assets.getFont("pixel art font"), 50);
	_scoreText.setFillColor(Color::Black);
	_scoreText.setPosition((SCREEN_WIDTH / 2 - (_scoreText.getGlobalBounds().width / 2)), (SCREEN_HEIGHT / 2 + 100));

	// High score
	int highScore;
	ifstream myfile;
	myfile.open("Ressources/highScore.txt");
	myfile >> highScore;
	myfile.close();

	if (_score > highScore) {
		ofstream myfile;
		myfile.open("Ressources/highScore.txt");
		myfile << _score;
		highScore = _score;
		myfile.close();
	}

	_highScoreText = Text("High score : " + to_string(highScore), _data->assets.getFont("pixel art font"), 50);
	_highScoreText.setFillColor(Color::Black);
	_highScoreText.setPosition((SCREEN_WIDTH / 2 - (_highScoreText.getGlobalBounds().width / 2)), (SCREEN_HEIGHT / 2 + 175));

	// Boutons
	_rejouerSprite.setTexture(_data->assets.getTexture("rejouer"));
	_rejouerSprite.setScale(6.0f, 6.0f);
	_rejouerSprite.setPosition(((SCREEN_WIDTH / 2) - (_rejouerSprite.getGlobalBounds().width) - 50), 800);
	_quitterSprite.setTexture(_data->assets.getTexture("quitter rouge"));
	_quitterSprite.setScale(6.0f, 6.0f);
	_quitterSprite.setPosition(((SCREEN_WIDTH / 2) + 50), 800);

	if (_gagne) {
		if (!_gameOverBuffer.loadFromFile(SOUND_GAME_WON))
			cout << "Erreur loading sound effect" << endl;
	}
	else {
		if (!_gameOverBuffer.loadFromFile(SOUND_GAME_OVER))
			cout << "Erreur loading sound effect" << endl;
	}

	_gameOverSound.setBuffer(_gameOverBuffer);
	_gameOverSound.play();
}

/// <summary>
/// Réagit aux différents inputs de l'utilisateur
/// </summary>
void gameOverState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)	// Si ferme fenêtre
			_data->window.close();
		else if (_data->input.isSpriteClicked(_rejouerSprite, Mouse::Left, _data->window))	// Si rejouer
			_data->machine.addState(stateRef(new gameState(_data)), true);
		else if (_data->input.isSpriteClicked(_quitterSprite, Mouse::Left, _data->window))	// Si fermer
			_data->window.close();
		else if (Mouse::isButtonPressed(Mouse::Left)) {		// Si clique, skip le temps pour faire apparaître les textes et boutons
			_color = 255;
			_outcomeText.setFillColor(Color::Color(255, 0, 0, _color));
			_scoreText.setFillColor(Color::Red);
			_highScoreText.setFillColor(Color::Red);
		}
	}
}

/// <summary>
/// Mets-à-jour les objets du state
/// </summary>
/// <param name="dt"></param>
void gameOverState::update(float dt)
{
	if (_color < 255) {
		_outcomeText.setFillColor(Color::Color(255, 0, 0, _color++));
	}

	if (_clock.getElapsedTime().asSeconds() > 3.0f) {
		_scoreText.setFillColor(Color::Red);
		_highScoreText.setFillColor(Color::Red);
	}
}

/// <summary>
/// Clear, dessine le background et display la fenêtre
/// </summary>
/// <param name="dt"></param>
void gameOverState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_outcomeText);
	_data->window.draw(_vousEtesText);
	_data->window.draw(_scoreText);
	_data->window.draw(_highScoreText);
	_data->window.draw(_rejouerSprite);
	_data->window.draw(_quitterSprite);
	_data->window.display();
}
