#include "Personnage.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

/* Créateur et destructeur de la classe Personnage */
Personnage::Personnage()
{
}

Personnage::~Personnage()
{
}

/* Création du visuel du Personnage */
void Personnage::create_Personnage()
{
}

/* Renvoie une force auparavant reçu */
double Personnage::return_Force()
{
	return 0.0;
}

/* Recevoir une force par un autre objet */
double Personnage::receive_Force()
{
	return 0.0;
}

/* Vitesse du personnage */
double Personnage::vitesse()
{
	return 0.0;
}

/* Gestion de la collision */
void Personnage::collision()
{
}

/* Lever le pied du personnage => envoie une force */
void Personnage::lever_Pied()
{
}

/* Mouvement direct par l'appuye du bouton */
void Personnage::mouvement_Direct()
{
}

/* Mouvement indirect par acquisition de force */
void Personnage::mouvement_Indirect()
{
}

/* Savoir comment est incliner le personnage par rapport au sol */
double Personnage::angle_PersonnageSol()
{
	return 0.0;
}

/* Savoir si le Personnage est en l'air ou pas */
bool Personnage::pos_AirorTerre()
{
	return false;
}

/* Savoir si le Personnage est attaquant ou défenseur */
bool Personnage::attaquantOrdefenseur()
{
	return false;
}
