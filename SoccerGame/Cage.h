/* Head de la classe Cage du jeu soccer game */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Cage
{
	public :

		/************* Cr�ateur et destructeur de la classe Cage **************/
		Cage();
		~Cage();

		/********************** M�thode de la classe Cage **********************/
		/* Cr�ation du visuel de la cage */
		void create_Cage();

		/* Renvoie une force auparavant re�u */
		double return_Force();

		/* Recevoir une force par un autre objet */
		double receive_Force();

		/* Gestion de la collision */
		void collision();

	private :

		// Les attributs seront �valu� plus tard /!\ Gwendal r�fl�chit � la collision !!!!!!
};