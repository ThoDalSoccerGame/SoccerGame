#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
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

// Variables sys :
RenderWindow window;
Event event;

// Redimensionnage de la fenêtre en fonction de l'écran de l'ordinateur :
VideoMode desktop = VideoMode::getDesktopMode();
float dWidth = desktop.width;
float dHeight = desktop.height;
float dBPP = desktop.bitsPerPixel;

// On récupère la longueur du background en fonction de la taille de la fenêtre :
long double xScale = dWidth / 1920;
long double yScale = dHeight / 1080;

// Variables des sprites/draw :
Texture background, armR, armL, legR, legL, head, body;
Sprite sprite_background, sprite_armR, sprite_armL, sprite_legR, sprite_legL, sprite_head, sprite_body, sprite_sol;
int x_body = 200 * xScale, y_body = 495 * yScale,  
	x_head = 207 * xScale, y_head = 445 * yScale,
	x_legR = 200 * xScale, y_legR = 615 * yScale,
	x_legL = 230 * xScale, y_legL = 615 * yScale,
	x_armL = 180 * xScale, y_armL = 495 * yScale, 
	x_armR = 267 * xScale, y_armR = 495 * yScale;

// Variables des boudingbox pour la collision :
FloatRect boudingboxBody = sprite_body.getGlobalBounds();
FloatRect boudingboxHead = sprite_head.getGlobalBounds();
FloatRect boudingboxLegR = sprite_legR.getGlobalBounds();
FloatRect boudingboxLegL = sprite_legL.getGlobalBounds();
FloatRect boudingboxArmR = sprite_armR.getGlobalBounds();
FloatRect boudingboxArmL = sprite_armL.getGlobalBounds();
FloatRect boudingboxSol = sprite_sol.getGlobalBounds();

#pragma endregion Variables globales

#pragma region Fonction

/* Cette fonction renvoie l'angle du personnage en fonction du sol */
double ReturnAngle()
{
#pragma region Variables
	
	double coordonnee_sol_origin, hauteur_sol , anglePersoSol
		  ,ox_legR, oy_legR, ox_body, oy_body
		  ,x_legRBody, y_legRBody, x_SolBody, y_SolBody, Norme_legRBody, Norme_SolBody
		  ,scalaire_coordonnee, cosAngle, AngleHaut, AngleSol;

#pragma endregion Variables

/****************** INITIALISATION CALCUL DES VECTEURS POUR LE CALCUL D'ANGLE **********************/

	// On reprends les coordonnées du sol en fonction de l'origine original :
	coordonnee_sol_origin = 730 * xScale;

	// Soit la hauteur depuis l'origine du repère 0 avec comme origine le sol est à hauteur écran - coordonnee_sol_origin
	hauteur_sol = dHeight - coordonnee_sol_origin;

	// On prends deux points du corps qui sont toujours alignées et ont les mets dans le nouveau repère.
	ox_legR = x_legR;
	oy_legR = dHeight - hauteur_sol - y_legR;
	ox_body = x_body;
	oy_body = dHeight - hauteur_sol - y_body;

	// On va calculer les coordonnées du vecteur legR/Body :
	x_legRBody = ox_legR - ox_body;
	y_legRBody = oy_legR - oy_body;
	// On calcul au passage la norme de ce vecteur :
	Norme_legRBody = sqrt(x_legRBody*x_legRBody + y_legRBody * y_legRBody);

	// On calcul le vecteur Sol/Body partant du principe que les coordonnées du sol pris en compte seront ox_body et 0 en y 
	x_SolBody = ox_body - ox_body;
	y_SolBody = 0 - oy_body;
	// On calcul au passage la norme de ce vecteur :
	Norme_SolBody = sqrt(x_SolBody * x_SolBody + y_SolBody * y_SolBody);

/***************************** CALCUL DES SCALAIRES POUR TROUVER L'ANGLE ********************************/

	// Calcul du produit scalaire des deux angles par coordonnées.
	scalaire_coordonnee = x_legRBody * x_SolBody + y_legRBody * y_SolBody;
	cosAngle = scalaire_coordonnee / (Norme_legRBody*Norme_SolBody);
	AngleHaut = acos(cosAngle);

	// Somme des angles d'un triangle = 180 :
	AngleSol = 180 - 90 - AngleHaut;

	cout << AngleSol;
	return AngleSol;
}

/* Cette fonction renverra un booléen avec comme entrée les membres du corps du personnages pour vérifier si il touche le sol */
bool touchSol(FloatRect head, FloatRect body, FloatRect legR, FloatRect legL, FloatRect armR, FloatRect armL)
{
	// Vérification pour le head :
	if (head.intersects(boudingboxSol)) {
		cout << "false";
		return false;
	}

	// Vérification pour le body :
	if (body.intersects(boudingboxSol)) {
		cout << "false";
		return false;
	}

	// Vérification pour le legR :
	if (legR.intersects(boudingboxSol)) {
		cout << "false";
		return false;
	}

	// Vérification pour le legL :
	if (legL.intersects(boudingboxSol)) {
		cout << "false";
		return false;
	}

	// Vérification pour le armR :
	if (armR.intersects(boudingboxSol)) {
		cout << "false";
		return false;
	}

	// Vérification pour le armL :
	if (armL.intersects(boudingboxSol)) {
		cout << "false";
		return false;
	}
	cout << "true";
	return true;
}

/* Cette fonction permettra de faire un saut */
void jump()
{
	int PositionInitial = 1;
	int angle = ReturnAngle();
	int vitesse = 40;

	while (touchSol(boudingboxHead,boudingboxBody,boudingboxLegR,boudingboxLegL,boudingboxArmR,boudingboxArmL) != false )
	{
		y_body += (-9.81 / ( 2* vitesse * vitesse * cos(angle)) * (PositionInitial * PositionInitial) + tan(angle) * PositionInitial ); // BODY
		sprite_body.setPosition(x_body, y_body);
		//sprite_body.setRotation(45);
		y_head += (-9.81 / (2 * vitesse * vitesse * cos(angle)) * (PositionInitial * PositionInitial) + tan(angle) * PositionInitial ); // HEAD
		sprite_head.setPosition(x_head, y_head);
		//sprite_head.setRotation(45);
		y_armL += (-9.81 / (2 * vitesse * vitesse * cos(angle)) * (PositionInitial * PositionInitial) + tan(angle) * PositionInitial ); // ARM L
		sprite_armL.setPosition(x_armL, y_armL);
		//sprite_armL.setRotation(45);
		y_armR += (-9.81 / (2 * vitesse * vitesse * cos(angle)) * (PositionInitial * PositionInitial) + tan(angle) * PositionInitial ); // ARM R
		sprite_armR.setPosition(x_armR, y_armR);
		//sprite_armR.setRotation(45);
		y_legR += (-9.81 / (2 * vitesse * vitesse * cos(angle)) * (PositionInitial * PositionInitial) + tan(angle) * PositionInitial ); //LEG R
		sprite_legR.setPosition(x_legR, y_legR);
		//sprite_legR.setRotation(45);
		y_legL += (-9.81 / (2 * vitesse * vitesse * cos(angle)) * (PositionInitial * PositionInitial) + tan(angle) * PositionInitial ); // LEG L
		sprite_legL.setPosition(x_legL, y_legL);

		Sleep(200);
		PositionInitial += 50;
		x_body += 50; x_head += 50; x_armL += 50; x_armR += 50; x_legR += 50; x_legL += 50;
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

		/**************** Sprite pour le sol ************/
		sprite_sol.setScale(dWidth, dHeight - 720 * yScale);
		// Position du sprite :
		sprite_sol.setPosition(0, 720 * yScale);

#pragma endregion Personnage

		window.display();
	}
}