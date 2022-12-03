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
	
	void spawnLeftWall();
	void spawnRightWall();
	void spawnDownWall();
	void spawnUpWall();
	void draw();
	list<Sprite>& getSprites();



};

