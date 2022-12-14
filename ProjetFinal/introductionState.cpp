#include "introductionState.h"
#include "loadingState.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
/// <param name="score"></param>
introductionState::introductionState(gameDataRef data):_data(data)
{
	_color = 0;
}

/// <summary>
/// Destructeur
/// </summary>
introductionState::~introductionState()
{
}

void introductionState::init()
{
	_data->assets.loadFont("pixel art font", PIXEL_ART_FONT);

	// titre de l'introduction du jeu.
	_titreText = Text("Bienvenue, dans les catacombes de Yharnam !",_data->assets.getFont("pixel art font"), 40);
	_titreText.setFillColor(Color::Color(255, 0, 0, _color));
	_titreText.setPosition((SCREEN_WIDTH / 2) - (_titreText.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_titreText.getGlobalBounds().height / 2 + 400));

	// Narration du jeu.
	_introparagragh1Text = Text("Le brave héros Scalet se vit jeter une malédiction, lors de la disparition de son fils ",_data->assets.getFont("pixel art font"),17 );
	_introparagragh1Text.setFillColor(Color::Color(255,0,0,_color));
	_introparagragh1Text.setPosition((SCREEN_WIDTH / 2 )- (_introparagragh1Text.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2 )- (_introparagragh1Text.getGlobalBounds().height/2+ 250));

	_introparagragh2Text = Text("mort au combat de Shanteldam par la hache de son ennemi Trusta, Minotorus.", _data->assets.getFont("pixel art font"), 17);
	_introparagragh2Text.setFillColor(Color::Color(255, 0, 0, _color));
	_introparagragh2Text.setPosition((SCREEN_WIDTH / 2) - (_introparagragh2Text.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_introparagragh2Text.getGlobalBounds().height / 2 + 210));

	_introparagragh3Text = Text("La malédiction de Scalet le plongea dans un sommeil tourmenté et cauchemardesque.", _data->assets.getFont("pixel art font"), 17);
	_introparagragh3Text.setFillColor(Color::Color(255, 0, 0, _color));
	_introparagragh3Text.setPosition((SCREEN_WIDTH / 2) - (_introparagragh3Text.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_introparagragh3Text.getGlobalBounds().height / 2 + 170));


	_introparagragh4Text = Text("Au fil du temps, sa chair commença à laisser peu à peu la place à son squelette.", _data->assets.getFont("pixel art font"), 17);
	_introparagragh4Text.setFillColor(Color::Color(255, 0, 0, _color));
	_introparagragh4Text.setPosition((SCREEN_WIDTH / 2) - (_introparagragh4Text.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_introparagragh4Text.getGlobalBounds().height / 2 + 100));

	_introparagragh5Text = Text("Aprés des décennies Scalet se remet enfin de sa malédiction qui tourmente encore et encore.", _data->assets.getFont("pixel art font"), 17);
	_introparagragh5Text.setFillColor(Color::Color(255, 0, 0, _color));
	_introparagragh5Text.setPosition((SCREEN_WIDTH / 2) - (_introparagragh5Text.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_introparagragh5Text.getGlobalBounds().height / 2 + 60));

	_introparagragh6Text = Text("Scalet, lui qui s'est fait déposséder de tous c'est bien est prés,", _data->assets.getFont("pixel art font"), 17);
	_introparagragh6Text.setFillColor(Color::Color(255, 0, 0, _color));
	_introparagragh6Text.setPosition((SCREEN_WIDTH / 2) - (_introparagragh6Text.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_introparagragh6Text.getGlobalBounds().height / 2 + 0));
	
	_introparagragh7Text = Text("mais surtout déterminé à venger son fils dans la taninère de son ennemi.", _data->assets.getFont("pixel art font"), 17);
	_introparagragh7Text.setFillColor(Color::Color(255, 0, 0, _color));
	_introparagragh7Text.setPosition((SCREEN_WIDTH / 2) - (_introparagragh7Text.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_introparagragh7Text.getGlobalBounds().height / 2 + -40));

	
}


/// <summary>
/// Initialise les différents objets du state
/// </summary>
void introductionState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)	// Si ferme fenêtre
			_data->window.close();
		else if (_data->input.isSpriteClicked(_suivantButton, Mouse::Left, _data->window))
		{
			_data->machine.addState(stateRef(new loadingState(_data)), true);
		}
		else if (Mouse::isButtonPressed(Mouse::Left)) {
			_data->assets.loadTexture("main continuer button", NEXT_BUTTON_FILEPATH);
			_suivantButton.setTexture(_data->assets.getTexture("main continuer button"));
			_suivantButton.setScale(5.0f, 5.0f);
			_suivantButton.setPosition(((SCREEN_WIDTH / 2) - (_suivantButton.getGlobalBounds().width) / 2 + 600), ((SCREEN_HEIGHT / 2) - (_suivantButton.getGlobalBounds().height / 2 - 400)));
		}
		//else if (Mouse::isButtonPressed(Mouse::Left)) {		// Si clique, skip le temps pour faire apparaître les textes et boutons
		//	_color = 255;
		//	_titreText.setFillColor(Color::Color(255, 0, 0, _color));
		//	_introparagragh1Text.setFillColor(Color::Color (255,0,0,_color));
		//	_introparagragh2Text.setFillColor(Color::Color (255,0,0,_color));
		//	_introparagragh3Text.setFillColor(Color::Color (255,0,0,_color));
		//	_introparagragh4Text.setFillColor(Color::Color (255,0,0,_color));
		//	_introparagragh5Text.setFillColor(Color::Color (255,0,0,_color));
		//	_introparagragh6Text.setFillColor(Color::Color (255,0,0,_color));
		//	_introparagragh7Text.setFillColor(Color::Color (255,0,0,_color));
		//}
		
	}
}

void introductionState::update(float dt)
{
	if (_color < 255) {
		_titreText.setFillColor(Color::Color(255, 0, 0, _color++));
		_introparagragh1Text.setFillColor(Color::Color(255, 0, 0, _color++));
		_introparagragh2Text.setFillColor(Color::Color(255, 0, 0, _color++));
		_introparagragh3Text.setFillColor(Color::Color(255, 0, 0, _color++));
		_introparagragh4Text.setFillColor(Color::Color(255, 0, 0, _color++));
		_introparagragh5Text.setFillColor(Color::Color(255, 0, 0, _color++));
		_introparagragh6Text.setFillColor(Color::Color(255, 0, 0, _color++));
		_introparagragh7Text.setFillColor(Color::Color(255, 0, 0, _color++));

	}

	// Affiche le suivant apres 6 secondes
	if (_clock.getElapsedTime().asSeconds() > 6.0f) {

		_data->assets.loadTexture("main continuer button", NEXT_BUTTON_FILEPATH);
		_suivantButton.setTexture(_data->assets.getTexture("main continuer button"));
		_suivantButton.setScale(5.0f, 5.0f);
		_suivantButton.setPosition(((SCREEN_WIDTH / 2) - (_suivantButton.getGlobalBounds().width) / 2 + 600 ), ((SCREEN_HEIGHT / 2) - (_suivantButton.getGlobalBounds().height / 2 - 400)));
	}
}

void introductionState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_titreText);
	_data->window.draw(_introparagragh1Text);
	_data->window.draw(_introparagragh2Text);
	_data->window.draw(_introparagragh3Text);
	_data->window.draw(_introparagragh4Text);
	_data->window.draw(_introparagragh5Text);
	_data->window.draw(_introparagragh6Text);
	_data->window.draw(_introparagragh7Text);
	_data->window.draw(_suivantButton);

	_data->window.display();
}
