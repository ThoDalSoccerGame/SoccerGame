#include "Ballon.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

/* Créateur et destructeur de la classe Ballon*/
Ballon::Ballon()
{
}

Ballon::~Ballon()
{
}


/* Création du visuel du ballon */
void Ballon::create_Ballon()
{
}

/* Renvoie d'une force auparavant reçu */
double Ballon::return_Force()
{
	return 0.0;
}

/* Recevoir une force par un autre objet */
double Ballon::receive_Force()
{
	return 0.0;
}

/* Vitesse du ballon */
double Ballon::vitesse()
{
	return 0.0;
}

/* Gestion de la collision */
void Ballon::collision()
{
}

/* Mouvement du ballon lorsqu'il reçoit une force */
void Ballon::mouvement_Indirect()
{
}

/* Savoir si le ballon est en l'air ou pas */
bool Ballon::pos_AirorTerre()
{
	return false;
}

/* Savoir si le ballon est dedans ou en dehors du terrain */
bool Ballon::pos_TerrainorNot()
{
	return false;
}

/* Savoir si le ballon est dans les cages ou pas */
bool Ballon::pos_CageorNot()
{
	return false;
}