#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
#pragma region Variables
	RenderWindow window;
	Event event;
	Texture background, armR, armL, legR, legL, head, body;
	Sprite sprite_background, sprite_armR, sprite_armL, sprite_legR, sprite_legL, sprite_head, sprite_body;
#pragma endregion Variables
	
#pragma region InfoCorps
	/*
	Body : x = 70, y = 130
	Head : x = 53, y = 53
	Leg Right : x = 53, y = 138
	Leg Left : x = 53, y = 128
	Arm Right : x = 23, y = 108
	Arm Left: x = 23, y = 108
	*/
#pragma endregion InfoCorps

#pragma region Window
	// Redimensionnage de la fenêtre en focntion de l'écran de l'ordinateur 
	VideoMode desktop = VideoMode::getDesktopMode();
	float dWidth = desktop.width;
	float dHeight = desktop.height;
	float dBPP = desktop.bitsPerPixel;
	window.create(VideoMode(dWidth, dHeight, dBPP), "Partie Solo", Style::Fullscreen);
#pragma endregion Window

	// Boucle principal de la partie solo
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed) {
				switch (event.key.code) {
				case(Keyboard::Escape):
					window.close();
					break;
				case(Keyboard::Up):
					// Fonction pour le mouvement du personnage
					for (int i = 0; i < 150; i++) {
						window.clear(Color::Black);

						sprite_body.move(i, 150);
						sprite_head.move(i, 150);
						sprite_armR.move(i, 150);
						sprite_armL.move(i, 150);
						sprite_legR.move(i,150);
						sprite_legL.move(i, 150);

						window.display();
					}
					break;
				}
			}
		}
		
		window.clear(Color::Black);

#pragma region Background
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
#pragma endregion Background

#pragma region Personnage
		/****************** Bras Droit *******************/
		// On vérifie l'existence de l'image du bras droit dans les ressources.
		if (!armR.loadFromFile("../images/armR.png")) {
			cout << "OU EST CE FOUTU BRAS DROIT ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_armR.setTexture(armR);
		// On dessine le sprite :
		window.draw(sprite_armR);
		// Position de test du bras droit :
		sprite_armR.setPosition(267, 375);

		/***************** Bras Gauche *******************/
		// On vérifie l'existence de l'image du bras gauche dans les ressources.
		if (!armL.loadFromFile("../images/armL.png")) {
			cout << "OU EST CE FOUTU BRAS GAUCHE ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_armL.setTexture(armL);
		// On dessine le sprite :
		window.draw(sprite_armL);
		// Position de test du bras gauche :
		sprite_armL.setPosition(180, 375);

		/*************** Jambes Gauche ******************/
		// On vérifie l'existence de l'image de la jambe gauche dans les ressources.
		if (!legL.loadFromFile("../images/legL.png")) {
			cout << "OU EST CETTE FOUTU JAMBE GAUCHE ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_legL.setTexture(legL);
		// On dessine le sprite :
		window.draw(sprite_legL);
		// Position de test de la jambe gauche :
		sprite_legL.setPosition(230, 495);

		/***************** Jambes Droites ****************/
		// On vérifie l'existence de l'image de la jambe droite dans les ressources.
		if (!legR.loadFromFile("../images/legR.png")) {
			cout << "OU EST CETTE FOUTU JAMBE DROITE ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_legR.setTexture(legR);
		// On dessine le sprite :
		window.draw(sprite_legR);
		// Position de test de la jambre droite
		sprite_legR.setPosition(200, 495);

		/********************** Tête **********************/
		// On vérifie l'existance de l'image de la tête dans les ressources.
		if (!head.loadFromFile("../images/head.png")) {
			cout << "OU EST CETTE FOUTU TÊTE ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_head.setTexture(head);
		// On dessine le sprite :
		window.draw(sprite_head);
		// Position de test de la tête :
		sprite_head.setPosition(207, 325);

		/******************* Corps *************************/
		// On vérifie l'existance de l'image du corps dans les ressources.
		if (!body.loadFromFile("../images/body.png")) {
			cout << "OU EST CE FOUTU CORPS ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_body.setTexture(body);
		// On dessine le sprite :
		window.draw(sprite_body);
		// Position de test du corps :
		sprite_body.setPosition(200, 375);

#pragma endregion Personnage

		window.display();
	}
}

