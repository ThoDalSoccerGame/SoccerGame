#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
	Window window;
	window.create(VideoMode(), "GameSoccer", Style::Fullscreen);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}
	}

	return 0;
}