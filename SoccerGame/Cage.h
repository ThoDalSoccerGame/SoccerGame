/* Head de la classe Cage du jeu soccer game */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Cage
{
	public :

		/************* Créateur et destructeur de la classe Cage **************/
		Cage();
		~Cage();

		/********************** Méthode de la classe Cage **********************/
		/* Création du visuel de la cage */
		void create_Cage();

		/* Renvoie une force auparavant reçu */
		double return_Force();

		/* Recevoir une force par un autre objet */
		double receive_Force();

		/* Gestion de la collision */
		void collision();

	private :

		// Les attributs seront évalué plus tard /!\ Gwendal réfléchit à la collision !!!!!!
};