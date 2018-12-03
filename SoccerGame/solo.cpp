#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <Windows.h>

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

// Redimensionnage de la fenêtre en fonction de l'écran de l'ordinateur 
VideoMode desktop = VideoMode::getDesktopMode();
float dWidth = desktop.width;
float dHeight = desktop.height;
float dBPP = desktop.bitsPerPixel;

// On récupère la longueur du background en fonction de la taille de la fenêtre :
long double xScale = dWidth / 1920;
long double yScale = dHeight / 1080;

// Variables des sprites/draw
Texture background, armR, armL, legR, legL, head, body;
Sprite sprite_background, sprite_armR, sprite_armL, sprite_legR, sprite_legL, sprite_head, sprite_body;
int x_body = 200 * xScale, y_body = 495 * yScale,  
	x_head = 207 * xScale, y_head = 445 * yScale,
	x_legR = 200 * xScale, y_legR = 615 * yScale,
	x_legL = 230 * xScale, y_legL = 615 * yScale,
	x_armL = 180 * xScale, y_armL = 495 * yScale, 
	x_armR = 267 * xScale, y_armR = 495 * yScale;



#pragma endregion Variables globales

#pragma region Fonction

/* Cette fonction renvoie l'angle du personnage en fonction du sol */
double ReturnAngle()
{
#pragma region Variables

	double coefficient_directeur, coordonnee_sol_origin, hauteur_sol, facteur_rotation
		  ,ox_head, oy_head, ox_body, oy_body;

#pragma endregion Variables

	// On reprends les coordonnées du sol en fonction de l'origine original :
	coordonnee_sol_origin = 730 * xScale;

	// Soit la hauteur depuis l'origine du repère 0 avec comme origine le sol est à hauteur écran - coordonnee_sol_origin
	hauteur_sol = dHeight - coordonnee_sol_origin;

	// Calcul des coordonnées des deux repères pour l'horizontal du personnage en fonction du nouveau repère :
	ox_head = x_head;
	oy_head = dHeight - hauteur_sol - y_head;
	ox_body = x_body;
	oy_body = dHeight - hauteur_sol - y_body;

	// Définition du cooeficient directeur
	coefficient_directeur = (oy_head - oy_body) / (ox_head - ox_body);
	
	// Le rapport entre le coefficient directeur et la réference horizontale qui est de 7.
	facteur_rotation = 7 / coefficient_directeur;

	cout << facteur_rotation;

	return facteur_rotation ;
}

// Cette fonction permettra de faire un saut
void jump()
{
	for (int i = 0; i < 100; i += 10) {
		y_body -= 10; // BODY
		sprite_body.setPosition(x_body, y_body);
		//sprite_body.setRotation(45);
		y_head -= 10; // HEAD
		sprite_head.setPosition(x_head, y_head);
		//sprite_head.setRotation(45);
		y_armL -= 10; // ARM L
		sprite_armL.setPosition(x_armL, y_armL);
		//sprite_armL.setRotation(45);
		y_armR -= 10; // ARM R
		sprite_armR.setPosition(x_armR, y_armR);
		//sprite_armR.setRotation(45);
		y_legR -= 10; //LEG R
		sprite_legR.setPosition(x_legR, y_legR);
		//sprite_legR.setRotation(45);
		y_legL -= 10; // LEG L
		sprite_legL.setPosition(x_legL, y_legL);
		//sprite_legL.setRotation(45);
		Sleep(500);
	}
}

#pragma endregion Fonction

int main()
{

#pragma region Variables 
	int compteur_mouvement = 0;
#pragma endregion Variables

#pragma region Window

	window.create(VideoMode(dWidth, dHeight, dBPP), "Partie Solo", Style::Fullscreen);

/*	sf::Transform trans;
	sf::CircleShape c;
	c.setPosition(50, 50);
	c.setRadius(50);
	trans.rotate(centre);
	window.draw(c, trans); */
	
#pragma endregion Window

#pragma region Threads

	sf::Thread threadJump(&jump);

#pragma endregion Threads

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
				
					if (event.type == Event::KeyPressed) {
						if (event.key.code == Keyboard::Escape) {
							window.close();
						}
					}
				
					threadJump.launch();
					
					window.display();
						
					Sleep(100);
					
					ReturnAngle();
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