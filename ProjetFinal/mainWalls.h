#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <list>
#include "game.h"

using namespace sf;

class wall
{

private:
	gameDataRef _data;
	list<Sprite>_wallSprite;

public:
	wall(gameDataRef data);
	~wall();
	void draw();
	void spawnLeftWall();
	void spawnRightWall();
	void spawnDownWall();
	void spawnUpWall();
	list<Sprite>& getSprites();



};

