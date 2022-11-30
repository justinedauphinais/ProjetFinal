#include <SFML/Graphics.hpp>
using namespace sf;	//en mettant ce namespace, ça évite des sf::
int main() {
	RenderWindow window(VideoMode(800, 600), "Lost");
	Event event;
	RectangleShape fondEcran;

	fondEcran.setSize(Vector2f(100, 100));
	fondEcran.setFillColor(Color::Green);

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(fondEcran);
		window.display();
	}

	return 0;
}
