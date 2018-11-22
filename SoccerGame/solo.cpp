#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf; 
using namespace std;

int main()
{

	RenderWindow window;
	Event event;
	Texture background, armR, armL, legR, legL, head, body;
	Sprite sprite_background, sprite_armR, sprite_armL, sprite_legR, sprite_legL, sprite_head, sprite_body;

	// Redimensionnage de la fenêtre en focntion de l'écran de l'ordinateur 
	VideoMode desktop = VideoMode::getDesktopMode();
	float dWidth = desktop.width;
	float dHeight = desktop.height;
	float dBPP = desktop.bitsPerPixel;
	window.create(VideoMode(dWidth, dHeight, dBPP), "Partie Solo", Style::Fullscreen);

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
		
		window.clear(Color::Black);

		// On va vérifier L'existence du background dans les ressources
		if (!background.loadFromFile("../images/background.jpg")) {
			cout << "OU EST CE FOUTU BACKGROUND ???" << endl;
		}
		// On récupère la longueur du background en fonction de la taille de la fenêtre :
		long double xScale = dWidth / 1920;
		long double yScale = dHeight / 1080;

		// On applique la texture sur une sprite :
		sprite_background.setTexture(background);
		// On met le sprite à l'échelle de la fenetre :
		sprite_background.setScale(xScale, yScale);
		// On dessine le sprite :
		window.draw(sprite_background);

		/****************** Bras Droit *******************/
		// On vérifie l'existence de l'image du bras droit dans les ressources.
		if (!armR.loadFromFile("../images/armR.png")) {
			cout << "OU EST CE FOUTU BRAS DROIT ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_armR.setTexture(armR);
		// On dessine le sprite :
		window.draw(sprite_armR);

		/***************** Bras Gauche *******************/
		// On vérifie l'existence de l'image du bras gauche dans les ressources.
		if (!armL.loadFromFile("../images/armL.png")) {
			cout << "OU EST CE FOUTU BRAS GAUCHE ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_armL.setTexture(armL);
		// On dessine le sprite :
		window.draw(sprite_armL);


	}
}