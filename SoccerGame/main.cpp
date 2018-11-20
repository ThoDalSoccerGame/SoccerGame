#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


int main()
{
	#pragma region VARIABLES
		RenderWindow window;
		Texture background;
		Sprite sprite;
	#pragma endregion VARIABLES	

	// Creer une fenetre avec le même mode de video que celui du Desktop
	VideoMode desktop = VideoMode::getDesktopMode();
	float dWidth = desktop.width;
	float dHeight = desktop.height;
	float dBPP = desktop.bitsPerPixel;
	window.create(VideoMode(dWidth, dHeight, dBPP), "GameSoccer", Style::Fullscreen);

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

		window.clear(Color::Black);
		
		// On charge la texture background
		if (!background.loadFromFile("background.jpg"))
		{
			// On affiche une erreur dans la console si le BG n'est pas chargé
			std::cout << "OU EST CE FOUTU BACKGROUND ??" << std::endl;
		}
		// On recupere le facteur d'echelle du BG par rapport à la fenetre
		long double xScale = dWidth / 1920;
		long double yScale = dHeight / 1080;
	
		// On applique la texture sur une sprite...
		sprite.setTexture(background);
		// On met à l'echelle la sprite pour qu'elle rentre dans la fenetre
		sprite.setScale(xScale, yScale);
		// On dessine la sprite
		window.draw(sprite);

		window.display();
	}

	return 0;
}