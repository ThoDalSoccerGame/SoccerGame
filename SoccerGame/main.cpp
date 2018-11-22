#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


int main()
{
#pragma region VARIABLES
		RenderWindow window;
		Event event;
		Texture background, button_login, button_login_push, button_sign, button_sign_push;
		Sprite sprite_background, sprite_login, sprite_login_push, sprite_sign, sprite_sign_push;
#pragma endregion VARIABLES	

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
		

#pragma region VISUEL
		if (!background.loadFromFile("../images/background.jpg")) {
			std::cout << "OU EST CE FOUTU BACKGROUND ??" << std::endl;
		}
		if (!button_login.loadFromFile("../images/login.png")) {
			std::cout << "OU EST CE FOUTU BOUTON LOGIN ??" << std::endl;
		}
		if (!button_login_push.loadFromFile("../images/login_push.png")) {
			std::cout << "OU EST CE FOUTU BOUTON LOGIN_PUSH ??" << std::endl;
		}
		if (!button_sign.loadFromFile("../images/sign.png")) {
			std::cout << "OU EST CE FOUTU BOUTON SIGN ??" << std::endl;
		}
		if (!button_sign_push.loadFromFile("../images/sign_push.png")) {
			std::cout << "OU EST CE FOUTU BOUTON SIGN_PUSH ??" << std::endl;
		}

		// On recupere le facteur d'echelle du BG par rapport à la fenetre
		long double xScale = dWidth / 1920;
		long double yScale = dHeight / 1080;

		// On recupere la taille de l'image du bouton login (et sign)
		Vector2u Size = button_login.getSize();
		double xSize = Size.x;
		double ySize = Size.y;

		// On applique les textures sur des sprite
		sprite_background.setTexture(background);
		sprite_login.setTexture(button_login);
		sprite_login_push.setTexture(button_login_push);
		sprite_sign.setTexture(button_sign);
		sprite_sign_push.setTexture(button_sign_push);

		// On met à l'echelle les sprite
		sprite_background.setScale(xScale, yScale);
		sprite_login.setScale(xScale, yScale);
		sprite_login_push.setScale(xScale, yScale);
		sprite_sign.setScale(xScale, yScale);
		sprite_sign_push.setScale(xScale, yScale);

		// La reference de facteur pour la position des boutons (valeur de mon pc)
		long double fact_position_X= float(705) / 1366;
		long double fact_position_Y = float(233) / 768;
		double posX_multi = fact_position_X_login * dWidth;
		double posX_solo = fact_position_X_sign * dWidth;
		double posY = fact_position_Y * dHeight;

		// On positione les sprite
		sprite_multi.setPosition(posX_multi, posY);
		sprite_solo.setPosition(posX_solo, posY);
		sprite_solo_push.setPosition(posX_solo, posY);
		sprite_multi_push.setPosition(posX_multi, posY);
		// On dessine la sprite
		window.draw(sprite_background);
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
#pragma endregion VISUEL

		window.display();
	}

	return 0;
}