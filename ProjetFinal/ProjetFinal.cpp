#include "game.h"
#include "DEFINITIONS.hpp"

using namespace sf;	//en mettant ce namespace, �a �vite des sf::
int main() {
	game flappy(SCREEN_WIDTH, SCREEN_HEIGHT, "The Catacombs of Yharnam");
	return EXIT_SUCCESS;
}
