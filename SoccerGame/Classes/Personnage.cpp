#include "Personnage.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

/* Constructeur de la classe Personnage */
Personnage::Personnage()
{
}

/* Destructeur de la classe Personnage */
Personnage::~Personnage()
{
}

void Personnage::createPersonnage(std::string link_body,
	std::string link_head,
	std::string link_armR,
	std::string link_armL,
	std::string link_legR,
	std::string link_legL,
	sf::Texture texture_body,
	sf::Texture texture_head,
	sf::Texture texture_armR,
	sf::Texture texture_armL,
	sf::Texture texture_legR,
	sf::Texture texture_legL,
	sf::Sprite sprite_body,
	sf::Sprite sprite_head,
	sf::Sprite sprite_armR,
	sf::Sprite sprite_armL,
	sf::Sprite sprite_legR,
	sf::Sprite sprite_legL)
{
	/******************* Corps *************************/
	// On vérifie l'existance de l'image du corps dans les ressources.
	if (!texture_body.loadFromFile(link_body)) {
		cout << "OU EST CE FOUTU CORPS ???" << endl;
	}
	// On applique la texture sur un sprite :
	sprite_body.setTexture(texture_body);
	// On redimensionne le personnage par rapport à la résolution de l'écran 
	sprite_body.setScale(xScale, yScale);
	// On dessine le sprite :
	fenetre.draw(sprite_body);
	// Position de test du corps :
	sprite_body.setPosition(x_body, y_body);

	/********************** Tête **********************/
	// On vérifie l'existance de l'image de la tête dans les ressources.
	if (!texture_head.loadFromFile("../Ressources/images/head.png")) {
		cout << "OU EST CETTE FOUTU TÊTE ???" << endl;
	}
	// On applique la texture sur un sprite :
	sprite_head.setTexture(texture_head);
	// On redimensionne le personnage par rapport à la résolution de l'écran 
	sprite_head.setScale(xScale, yScale);
	// On dessine le sprite :
	fenetre.draw(sprite_head);
	// Position de test de la tête :
	sprite_head.setPosition(x_head, y_head);

	/*************** Jambes Gauche ******************/
// On vérifie l'existence de l'image de la jambe gauche dans les ressources.
	if (!texture_legL.loadFromFile("../Ressources/images/legL.png")) {
		cout << "OU EST CETTE FOUTU JAMBE GAUCHE ???" << endl;
	}
	// On applique la texture sur un sprite :
	sprite_legL.setTexture(texture_legL);
	// On redimensionne le personnage par rapport à la résolution de l'écran 
	sprite_legL.setScale(xScale, yScale);
	// On dessine le sprite :
	fenetre.draw(sprite_legL);
	// Position de test de la jambe gauche :
	sprite_legL.setPosition(x_legL, y_legL);

	/***************** Jambes Droites ****************/
	// On vérifie l'existence de l'image de la jambe droite dans les ressources.
	if (!texture_legR.loadFromFile("../Ressources/images/legR.png")) {
		cout << "OU EST CETTE FOUTU JAMBE DROITE ???" << endl;
	}
	// On applique la texture sur un sprite :
	sprite_legR.setTexture(texture_legR);
	// On redimensionne le personnage par rapport à la résolution de l'écran 
	sprite_legR.setScale(xScale, yScale);
	// On dessine le sprite :
	fenetre.draw(sprite_legR);
	// Position de test de la jambre droite
	sprite_legR.setPosition(x_legR, y_legR);

	/***************** Bras Gauche *******************/
	// On vérifie l'existence de l'image du bras gauche dans les ressources.
	if (!texture_armL.loadFromFile("../Ressources/images/armL.png")) {
		cout << "OU EST CE FOUTU BRAS GAUCHE ???" << endl;
	}
	// On applique la texture sur un sprite :
	sprite_armL.setTexture(texture_armL);
	// On redimensionne le personnage par rapport à la résolution de l'écran 
	sprite_armL.setScale(xScale, yScale);
	// On dessine le sprite :
	fenetre.draw(sprite_armL);
	// Position de test du bras gauche :
	sprite_armL.setPosition(x_armL, y_armL);

	/****************** Bras Droit *******************/
	// On vérifie l'existence de l'image du bras droit dans les ressources.
	if (!texture_armR.loadFromFile("../Ressources/images/armR.png")) {
		cout << "OU EST CE FOUTU BRAS DROIT ???" << endl;
	}
	// On applique la texture sur un sprite :
	sprite_armR.setTexture(texture_armR);
	// On redimensionne le personnage par rapport à la résolution de l'écran 
	sprite_armR.setScale(xScale, yScale);
	// On dessine le sprite :
	fenetre.draw(sprite_armR);
	// Position de test du bras droit :
	sprite_armR.setPosition(x_armR, y_armR);
}

void Personnage::jump()
{

}

