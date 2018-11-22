#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


int main()
{
#pragma region VARIABLES
		RenderWindow window;
		Event event;
		Texture background, button_multi, button_solo, button_multi_push, button_solo_push;
		Sprite sprite_background, sprite_multi, sprite_solo, sprite_setting, sprite_solo_push, sprite_multi_push;
#pragma endregion VARIABLES	
		// TEST
#pragma region WINDOW
	// Creer une fenetre avec le même mode de video que celui du Desktop
	VideoMode desktop = VideoMode::getDesktopMode();
	float dWidth = desktop.width;
	float dHeight = desktop.height;
	float dBPP = desktop.bitsPerPixel;
	window.create(VideoMode(dWidth, dHeight, dBPP), "GameSoccer", Style::Fullscreen);
#pragma endregion WINDOW

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}

		window.clear(Color::Black);
		
#pragma region BACKGROUND
		// On charge la texture background
		if (!background.loadFromFile("images/background.jpg"))
		{
			// On affiche une erreur dans la console si le BG n'est pas chargé
			std::cout << "OU EST CE FOUTU BACKGROUND ??" << std::endl;
		}
		// On recupere le facteur d'echelle du BG par rapport à la fenetre
		long double xScale = dWidth / 1920;
		long double yScale = dHeight / 1080;

		// On applique la texture sur une sprite...
		sprite_background.setTexture(background);
		// On met à l'echelle la sprite pour qu'elle rentre dans la fenetre
		sprite_background.setScale(xScale, yScale);
		// On dessine la sprite
		window.draw(sprite_background);
#pragma endregion BACKGROUND

#pragma region BUTTON
		// On charge les textures des boutons
		if (!button_solo.loadFromFile("images/button_solo.png"))
		{
			// On affiche une erreur dans la console si les boutons ne sont pas chargés
			std::cout << "OU EST CE FOUTU BOUTON ??" << std::endl;
		}
		if (!button_multi.loadFromFile("images/button_multi.png"))
		{
			// On affiche une erreur dans la console si les boutons ne sont pas chargés
			std::cout << "OU EST CE FOUTU BOUTON ??" << std::endl;
		}
		if (!button_multi_push.loadFromFile("images/button_multi_push.png"))
		{
			// On affiche une erreur dans la console si les boutons ne sont pas chargés
			std::cout << "OU EST CE FOUTU BOUTON ??" << std::endl;
		}
		if (!button_solo_push.loadFromFile("images/button_solo_push.png"))
		{
			// On affiche une erreur dans la console si les boutons ne sont pas chargés
			std::cout << "OU EST CE FOUTU BOUTON ??" << std::endl;
		}

		Vector2u Size = button_solo_push.getSize();
		double xSize = Size.x;
		double ySize = Size.y;

		// On applique les textures sur des sprite...
		sprite_multi.setTexture(button_multi);
		sprite_solo.setTexture(button_solo);
		sprite_solo_push.setTexture(button_solo_push);
		sprite_multi_push.setTexture(button_multi_push);
		// On met à l'echelle les sprite
		sprite_multi.setScale(xScale, yScale);
		sprite_solo.setScale(xScale, yScale);
		sprite_solo_push.setScale(xScale, yScale);
		sprite_multi_push.setScale(xScale, yScale);

		// Reference de facteur pour la position des boutons
		long double fact_position_X_multi = float(705) / 1366;
		long double fact_position_X_solo = float(278) / 1366;
		long double fact_position_Y = float(233) / 768;
		double posX_multi = fact_position_X_multi * dWidth;
		double posX_solo = fact_position_X_solo * dWidth;
		double posY = fact_position_Y * dHeight;

		// On positione les sprite
		sprite_multi.setPosition(posX_multi, posY);
		sprite_solo.setPosition(posX_solo, posY);
		sprite_solo_push.setPosition(posX_solo, posY);
		sprite_multi_push.setPosition(posX_multi, posY);
		// On dessine la sprite
		window.draw(sprite_multi);
		window.draw(sprite_solo);

		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left 
				&& event.mouseButton.x > 278 
				&& event.mouseButton.x < (278+ xSize)
				&& event.mouseButton.y > 233
				&& event.mouseButton.y < (233 + ySize)
			){
				window.clear(Color::Black);
				window.draw(sprite_background);
				window.draw(sprite_multi);
				window.draw(sprite_solo_push);
			}

			if (event.mouseButton.button == Mouse::Left
				&& event.mouseButton.x > 705
				&& event.mouseButton.x < (705 + xSize)
				&& event.mouseButton.y > 233
				&& event.mouseButton.y < (233 + ySize)
				) {
				window.clear(Color::Black);	
				window.draw(sprite_background);
				window.draw(sprite_solo);
				window.draw(sprite_multi_push);
			}
		}
#pragma endregion BUTTON

		window.display();
	}

	return 0;
}