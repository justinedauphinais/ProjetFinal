/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: loadingState.h																*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "state.hpp"
#include "game.h"
#include "gameState.h"

/// <summary>
/// 
/// </summary>
class loadingState : public state
{
private:
	gameDataRef _data;

	RectangleShape _backgroundSprite;
	Sprite _progressBarSprite;
	vector<Texture> _animationProgressBar;
	Text _loadingText;

	int _frameIterator;

	Clock _clock;

public:
	loadingState(gameDataRef data);
	~loadingState();

	void init();

	void handleInput();
	void update(float dt);

	void draw(float dt) const;
};