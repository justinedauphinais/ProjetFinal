/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: entity.h																		*
* Date		: 21/12/2022																	*
* Description : Classe utilis�e pour la base de toutes les entit�s. Contient tous les		*
				vecteurs d'animations, l'�tat de l'entit�, sa direction et					*
				et son nombre de vie.														*
*********************************************************************************************/
#pragma once

#include "drawable.h"

class entity : public drawable {
protected:
	int _animationIterator;
	vector<Texture> _animationFramesWalkingRight;
	vector<Texture> _animationFramesWalkingLeft;
	vector<Texture> _animationFramesFightingRight;
	vector<Texture> _animationFramesFightingLeft;
	vector<Texture> _animationFramesIdleRight;
	vector<Texture> _animationFramesIdleLeft;
	vector<Texture> _animationFramesDamagedLeft;
	vector<Texture> _animationFramesDamagedRight;
	vector<Texture> _animationFramesDyingLeft;
	vector<Texture> _animationFramesDyingRight;

	entityStates _state;
	directions _dir;

	int _nbrLives;
	int _totalLives;

	Clock _attackClock;

public:
	int getNbrLives() const;
	entityStates getState() const;
	directions getDirection() const;

	void setState(entityStates state);
	bool removeHearts(int nbr = 1);

	void move(Keyboard::Key key, float time);
};