#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf ; 
using namespace std;

int main()
{
#pragma region Variables 
	RenderWindow window;
	Event event;
	Texture background, armR, armL, legR, legL, head, body;
	Sprite sprite_background, sprite_armR, sprite_armL, sprite_legR, sprite_legL, sprite_head, sprite_body;
#pragma endregion Variables

#pragma region Windows
	// Redimensionnage de la fen�tre en focntion de l'�cran de l'ordinateur 
	VideoMode desktop = VideoMode::getDesktopMode();
	float dWidth = desktop.width;
	float dHeight = desktop.height;
	float dBPP = desktop.bitsPerPixel;
	window.create(VideoMode(dWidth, dHeight, dBPP), "Partie Solo", Style::Fullscreen);
#pragma endregion Windows 
	// Boucle principal de la partie solo
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) {
					window.close();
				}
			}
		}
#pragma region Background
		// On va v�rifier L'existence du background dans les ressources
		if (!background.loadFromFile("../image/background.jpg")) {
			cout << "OU EST CE FOUTU BACKGROUND ???" << endl;
		}
		// On r�cup�re la longueur du background en fonction de la taille de la fen�tre :
		long double xScale = dWidth / 1920;
		long double yScale = dHeight / 1080;

		// On applique la texture sur une sprite :
		sprite_background.setTexture(background);
		// On met le sprite � l'�chelle de la fenetre :
		sprite_background.setScale(xScale, yScale);
		// On dessine le sprite :
		window.draw(sprite_background);
#pragma endregion Background

	}
}