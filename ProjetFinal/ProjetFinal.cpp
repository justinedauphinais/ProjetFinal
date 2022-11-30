#include "game.h"
#include "DEFINITIONS.hpp"

using namespace sf;	//en mettant ce namespace, ça évite des sf::
int main() {
	game flappy(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
	return EXIT_SUCCESS;
}
