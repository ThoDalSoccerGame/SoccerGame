/* Head de la classe Ballon du jeu soccer game */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Ballon
{
	public:

		/************* Cr�ateur et destructeur de la classe Ballon **************/
		Ballon();
		~Ballon();

		/********************** M�thode de la classe Ballon **********************/
		/* Cr�ation du visuel de la Balle */
		void create_Ballon();

		/* Renvoie une force auparavant re�u */
		double return_Force();

		/* Recevoir une force par un autre objet */
		double receive_Force();

		/* Vitesse actuelle du ballon */
		double vitesse();

		/* Gestion de la collision */
		void collision();

		/* Mouvement du ballon lorsqu'il re�oit une force */
		void mouvement_Indirect();

		/* Savoir si le ballon est en l'air ou pas */
		bool pos_AirorTerre();

		/* Savoir si le ballon est dedans ou en dehors du terrain */
		bool pos_TerrainorNot();

		/* Savoir si le ballon est dans les cages ou pas */
		bool pos_CageorNot();

	private:

		// Les attributs seront �valu� plus tard /!\ Gwendal r�fl�chit � la collision !!!!!!
};