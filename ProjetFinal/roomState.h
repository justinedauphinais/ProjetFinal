#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "gameState.h"
#include <iostream>

using namespace sf;
using namespace std;

// Chaque state repr�sentera une vraie fen�tre et h�rite de state, car on impl�mentera
// un init, update, draw et handleInput diff�rent pour chaque fen�tre.
class gameOverState : public state
{
private:
	gameDataRef _data;

}