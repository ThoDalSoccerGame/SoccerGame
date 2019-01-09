/* Head de la classe Personnage du jeu soccer game */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Personnage
{
	public :

		/************* Créateur et destructeur de la classe Personnage **************/
		Personnage();
		~Personnage();

		/********************** Méthode de la classe Personnage **********************/
		/* Création du visuel du Personnage */
		void create_Personnage();

		/* Renvoie une force auparavant reçu */
		double return_Force();

		/* Recevoir une force par un autre objet */
		double receive_Force();

		/* Vitesse du personnage */
		double vitesse();

		/* Gestion de la collision */
		void collision();

		/* Lever le pied du personnage => envoie une force */
		void lever_Pied();

		/* Mouvement direct par l'appuye du bouton */
		void mouvement_Direct();

		/* Mouvement indirect par acquisition de force */
		void mouvement_Indirect();

		/* Savoir comment est incliner le personnage par rapport au sol */
		double angle_PersonnageSol();

		/* Savoir si le Personnage est en l'air ou pas */
		bool pos_AirorTerre();

		/* Savoir si le Personnage est attaquant ou défenseur */
		bool attaquantOrdefenseur();

	private :

		// Les attributs seront évalué plus tard /!\ Gwendal réfléchit à la collision !!!!!!
};