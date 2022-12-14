/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: state.hpp																		*
* Date		: 21/12/2022																	*
* Description : ...																			*
*********************************************************************************************/
#pragma once

class state
{
public:
	virtual void init() = 0;					// Init de state
	virtual void handleInput() = 0;				// Tous les input de la fen�tre
	virtual void update(float delta) = 0;		// Update la fen�tre apr�s le input
	virtual void draw(float delta)const = 0;	// Draw la fen�tre apr�s le update (delta est
												// la diff�rence de temps avec le frame rate)
	virtual void pause() {}						// Pause et resume le state
	virtual void resume() {}
};