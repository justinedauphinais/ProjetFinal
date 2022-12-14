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
	Sprite _skeletonLoadingSprite;
	vector<Texture> _animationProgressBar;
	vector<Texture> _animationSkeletonLoading;
	Text _loadingText;

	int _frameIterator;
	int _frameSkeletonIterator;


	Clock _clock;
	Clock _clockSkeleton;

public:
	loadingState(gameDataRef data);
	~loadingState();

	void init();

	void handleInput();
	void update(float dt);

	void draw(float dt) const;
};