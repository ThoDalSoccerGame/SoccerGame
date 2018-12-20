// Head de la classe Personnage du jeu soccer game 

#ifndef DEF_Personnage
#define DEF_Personnage

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Personnage
{
	public :
		Personnage();
		~Personnage();
		void createPersonnage(std::string link_body,
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
							  sf::Sprite sprite_legL
		);

		void jump();

	private :
		double xScale;
		double yScale;
		int x_body, y_body, x_head, y_head, x_armR, y_armR, x_armL, y_armL, x_legR, y_legR, x_legL, y_legL;

		RenderWindow fenetre;
		


};

#endif // !DEF_Personnage
