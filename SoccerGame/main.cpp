#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

using namespace sf;
using namespace std;

#pragma region VARIABLES
RenderWindow window;
Event event;
Texture background, bg_login, button_login, button_login_push, button_sign, button_sign_push;
Sprite sprite_background, sprite_bg_login, sprite_login, sprite_login_push, sprite_sign, sprite_sign_push;
#pragma endregion VARIABLES	

/*char Cle[] = "MUSIQUE"; // Formé de caractères de 'A' à 'Z' uniquement !
char Ori[] = "J'ADORE EC_OUTER LA RADIO TOUTE LA JOURNEE";
char Cry[100], Dec[100]; // Au moins aussi longs que Ori
int nCle = strlen(Cle), nTxt = strlen(Ori);*/

#pragma region IMAGE
void LoadImage() {
	if (!background.loadFromFile("../images/background.jpg")) {
		std::cout << "OU EST CE FOUTU BACKGROUND ??" << std::endl;
	}
	if (!bg_login.loadFromFile("../images/bg_login.jpg")) {
		std::cout << "OU EST CE FOUTU BACKGROUND ??" << std::endl;
	}
	if (!button_login.loadFromFile("../images/login.png")) {
		std::cout << "OU EST CE FOUTU BOUTON LOGIN ??" << std::endl;
	}
	if (!button_login_push.loadFromFile("../images/login_push.png")) {
		std::cout << "OU EST CE FOUTU BOUTON LOGIN_PUSH ??" << std::endl;
	}
	if (!button_sign.loadFromFile("../images/sign.png")) {
		std::cout << "OU EST CE FOUTU BOUTON SIGN ??" << std::endl;
	}
	if (!button_sign_push.loadFromFile("../images/sign_push.png")) {
		std::cout << "OU EST CE FOUTU BOUTON SIGN_PUSH ??" << std::endl;
	}
}

void SpriteTexture(){
	sprite_background.setTexture(background);
	sprite_login.setTexture(button_login);
	sprite_login_push.setTexture(button_login_push);
	sprite_sign.setTexture(button_sign);
	sprite_sign_push.setTexture(button_sign_push);
	sprite_bg_login.setTexture(bg_login);
}

void SpriteScale(double xScale, double yScale) {
	sprite_background.setScale(xScale, yScale);
	sprite_login.setScale(xScale, yScale);
	sprite_login_push.setScale(xScale, yScale);
	sprite_sign.setScale(xScale, yScale);
	sprite_sign_push.setScale(xScale, yScale);
	sprite_bg_login.setScale(xScale, yScale);
}

void SpritePosition(double posX, double posY_login, double posY_sign) {
	sprite_login.setPosition(posX, posY_login);
	sprite_login_push.setPosition(posX, posY_login);
	sprite_sign.setPosition(posX, posY_sign);
	sprite_sign_push.setPosition(posX, posY_sign);
}
#pragma endregion IMAGE	

/*
void Crypter() { // Ori ==> Cry
	for (int i = 0, k = -1; i < nTxt; ++i) {
		int c = (int)Ori[i];
		Cry[i] = ((c < 'A') || (c > 'Z')) ? c : 'A' + (c + Cle[(++k) % nCle]) % 26;
	} Cry[nTxt] = 0;
}

void Decrypter() { // Cry ==> Dec
	for (int i = 0, k = -1; i < nTxt; ++i) {
		int c = (int)Cry[i];
		Dec[i] = ((c < 'A') || (c > 'Z')) ? c : 'A' + (78 + c - Cle[(++k) % nCle]) % 26;
	} Dec[nTxt] = 0;
}*/

void login() {
	window.clear(Color::Black);
	bool login = true;
	while (login)
	{
		window.draw(sprite_bg_login);
		cout << "test" << endl;
		/*if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left
				&& event.mouseButton.x > 0
				&& event.mouseButton.x < (100)
				&& event.mouseButton.y > 0
				&& event.mouseButton.y < (100)
			){
				login = false;
			}
		}*/
	}
}

int main()
{
	/*printf("Alphabet: A..Z; Clef: %sn", Cle);
	printf("Texte original: %sn", Ori);
	Crypter();
	printf("Texte crypte  : %sn", Cry);
	Decrypter();
	printf("Texte decrypte: %sn", Dec);*/

#pragma region WINDOW
	// Creer une fenetre avec le même mode de video que celui du Desktop
	VideoMode desktop = VideoMode::getDesktopMode();
	float dWidth = desktop.width;
	float dHeight = desktop.height;
	float dBPP = desktop.bitsPerPixel;
	window.create(VideoMode(dWidth, dHeight, dBPP), "GameSoccer", Style::Fullscreen);
#pragma endregion WINDOW

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}
		
		window.clear(Color::Black);

#pragma region VISUEL

		LoadImage();

		// On recupere le facteur d'echelle du BG par rapport à la fenetre
		long double xScale = dWidth / 1920;
		long double yScale = dHeight / 1080;

		// On recupere la taille de l'image du bouton login (et sign)
		Vector2u Size = button_login.getSize();
		double xSize = Size.x;
		double ySize = Size.y;

		SpriteTexture();
		SpriteScale(xScale, yScale);

		// La reference de facteur pour la position des boutons (valeur de mon pc)
		long double fact_position_X = float(390) / 1366;
		long double fact_position_Y_login = float(245) / 768;
		long double fact_position_Y_sign = float(437) / 768;
		double posX = fact_position_X * dWidth;
		double posY_login = fact_position_Y_login * dHeight;
		double posY_sign = fact_position_Y_sign * dHeight;

		SpritePosition(posX, posY_login, posY_sign);

		// On dessine les sprite
		window.draw(sprite_background);
		window.draw(sprite_login);
		window.draw(sprite_sign);

		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left 
				&& event.mouseButton.x > posX
				&& event.mouseButton.x < (posX + xSize)
				&& event.mouseButton.y > posY_login
				&& event.mouseButton.y < (posY_login + ySize)
			){
				window.clear(Color::Black);
				window.draw(sprite_background);
				window.draw(sprite_sign);
				window.draw(sprite_login_push);
				login();
			}

			if (event.mouseButton.button == Mouse::Left
				&& event.mouseButton.x > posX
				&& event.mouseButton.x < (posX + xSize)
				&& event.mouseButton.y > posY_sign
				&& event.mouseButton.y < (posY_sign + ySize)
				) {
				window.clear(Color::Black);	
				window.draw(sprite_background);
				window.draw(sprite_login);
				window.draw(sprite_sign_push);
			}
		}
#pragma endregion VISUEL

		window.display();
	}

	return 0;
}

