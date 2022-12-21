/********************************************************************************************
* Auteur	: Justine Dauphinais & Jimmi Lancelot											*
* Nom		: hud.h																			*
* Date		: 21/12/2022																	*
* Description : Gestion des objets affichés par dessus le jeu, tels que la vie, le score,	*
				l'argent et le nombre de chambres.											*
*********************************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "entity.h"
#include "Inventaire.h"

using namespace sf;

class hud {
private:
	gameDataRef _data;

	int _score;
	Sprite _scoreSprite;
	Text _scoreText;

	int _money;
	Sprite _moneySprite;
	Text _moneyText;
	
	vector<Sprite> _hearts;		// Les coeurs
	Sprite _heart;

	int _nbrRoom;
	Text _roomText;

public:
	hud(gameDataRef data, int nbrRoom, int score = 0, int money = 0, int nbCoeurs = NBR_LIVES);

	void setScore(int score);
	void addScore(int score = 1);

	bool removeHeart(int nb = 1);
	void addHeart(int nb = 1);

	void setMoney(int nb);
	void addMoney(int nb = 1);
	bool removeMoney(int nb);

	void addRoom();

	int getScore() const;
	int getNbrVies() const;
	int getRoom() const;

	void draw() const;
};