#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

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

#pragma region Variables globales

// Variables sys
RenderWindow window;
Event event;

// Variables des sprites/draw
Texture background, armR, armL, legR, legL, head, body;
Sprite sprite_background, sprite_armR, sprite_armL, sprite_legR, sprite_legL, sprite_head, sprite_body;
int x_body = 200, y_body = 375, x_head = 207, y_head = 325, x_legR = 200, y_legR = 495, x_legL = 230, y_legL = 495, x_armL = 180 , y_armL = 375, x_armR = 267, y_armR = 375;

// Redimensionnage de la fenêtre en fonction de l'écran de l'ordinateur 
VideoMode desktop = VideoMode::getDesktopMode();
float dWidth = desktop.width;
float dHeight = desktop.height;
float dBPP = desktop.bitsPerPixel;

// On récupère la longueur du background en fonction de la taille de la fenêtre :
long double xScale = dWidth / 1920;
long double yScale = dHeight / 1080;

#pragma endregion Variables globales

#pragma region Fonction

/* Cette fonction renvoie l'angle du personnage en fonction du sol */
double ReturnAngle()
{
	// Coordonnée de la tête : x_head, y_head
	// Coordonnée du corps : x_body, y_body
#pragma region Variables
	double coefficient_directeur, horizontal_personnage;
#pragma endregion Variables

	coefficient_directeur = (y_head - y_body) / (x_head - x_body);
	
	// Le rapport entre le coefficient directeur du personnage et son horizontal est de -1/7 
	horizontal_personnage = coefficient_directeur * (-1) ;
	horizontal_personnage /= 7;

	return horizontal_personnage ;
}

#pragma endregion Fonction

int main()
{

#pragma region Variables 

#pragma endregion Variables

#pragma region Window

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
					for (int i = 0; i < 100 ; i++) {
						if (event.type == Event::KeyPressed) {
							if (event.key.code == Keyboard::Escape) {
								window.close();
							}
						}
						x_body += 1; // BODY
						sprite_body.setPosition(x_body, y_body);
						x_head += 1; // HEAD
						sprite_head.setPosition(x_head, y_head);
						x_armL += 1; // ARM L
						sprite_armL.setPosition(x_armL, y_armL);
						x_armR += 1; // ARM R
						sprite_armR.setPosition(x_armR, y_armR);
						x_legR += 1; //LEG R
						sprite_legR.setPosition(x_legR, y_legR);
						x_legL += 1; // LEG L
						sprite_legL.setPosition(x_legL, y_legL);
						
						window.display();
					}
					returnAngle();
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
		// On applique la texture sur une sprite :
		sprite_background.setTexture(background);
		// On met le sprite à l'échelle de la fenetre :
		sprite_background.setScale(xScale, yScale);
		// On dessine le sprite :
		window.draw(sprite_background);

#pragma endregion Background

#pragma region Personnage
		/******************* Corps *************************/
		// On vérifie l'existance de l'image du corps dans les ressources.
		if (!body.loadFromFile("../images/body.png")) {
			cout << "OU EST CE FOUTU CORPS ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_body.setTexture(body);
		// On redimensionne le personnage par rapport à la résolution de l'écran 
		sprite_body.setScale(xScale, yScale);
		// On dessine le sprite :
		window.draw(sprite_body);
		// Position de test du corps :
		sprite_body.setPosition(x_body, y_body);

		/********************** Tête **********************/
		// On vérifie l'existance de l'image de la tête dans les ressources.
		if (!head.loadFromFile("../images/head.png")) {
			cout << "OU EST CETTE FOUTU TÊTE ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_head.setTexture(head);
		// On redimensionne le personnage par rapport à la résolution de l'écran 
		sprite_head.setScale(xScale, yScale);
		// On dessine le sprite :
		window.draw(sprite_head);
		// Position de test de la tête :
		sprite_head.setPosition(x_head, y_head);

		/*************** Jambes Gauche ******************/
		// On vérifie l'existence de l'image de la jambe gauche dans les ressources.
		if (!legL.loadFromFile("../images/legL.png")) {
			cout << "OU EST CETTE FOUTU JAMBE GAUCHE ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_legL.setTexture(legL);
		// On redimensionne le personnage par rapport à la résolution de l'écran 
		sprite_legL.setScale(xScale, yScale);
		// On dessine le sprite :
		window.draw(sprite_legL);
		// Position de test de la jambe gauche :
		sprite_legL.setPosition(x_legL, y_legL);

		/***************** Jambes Droites ****************/
		// On vérifie l'existence de l'image de la jambe droite dans les ressources.
		if (!legR.loadFromFile("../images/legR.png")) {
			cout << "OU EST CETTE FOUTU JAMBE DROITE ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_legR.setTexture(legR);
		// On redimensionne le personnage par rapport à la résolution de l'écran 
		sprite_legR.setScale(xScale, yScale);
		// On dessine le sprite :
		window.draw(sprite_legR);
		// Position de test de la jambre droite
		sprite_legR.setPosition(x_legR, y_legR);

		/***************** Bras Gauche *******************/
		// On vérifie l'existence de l'image du bras gauche dans les ressources.
		if (!armL.loadFromFile("../images/armL.png")) {
			cout << "OU EST CE FOUTU BRAS GAUCHE ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_armL.setTexture(armL);
		// On redimensionne le personnage par rapport à la résolution de l'écran 
		sprite_armL.setScale(xScale, yScale);
		// On dessine le sprite :
		window.draw(sprite_armL);
		// Position de test du bras gauche :
		sprite_armL.setPosition(x_armL, y_armL);

		/****************** Bras Droit *******************/
		// On vérifie l'existence de l'image du bras droit dans les ressources.
		if (!armR.loadFromFile("../images/armR.png")) {
			cout << "OU EST CE FOUTU BRAS DROIT ???" << endl;
		}
		// On applique la texture sur un sprite :
		sprite_armR.setTexture(armR);
		// On redimensionne le personnage par rapport à la résolution de l'écran 
		sprite_armR.setScale(xScale, yScale);
		// On dessine le sprite :
		window.draw(sprite_armR);
		// Position de test du bras droit :
		sprite_armR.setPosition(x_armR, y_armR);
		
#pragma endregion Personnage

		window.display();
	}
}

