#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace sf;
using namespace std;

#pragma region VARIABLES
RenderWindow window;
Event event;
Font main_font, arial_font;
Text pseudo, password;
Texture background, bg_login, button_login, button_login_push, button_sign, button_sign_push;
Sprite sprite_background, sprite_bg_login, sprite_login, sprite_login_push, sprite_sign, sprite_sign_push;
int isLogin = 0, isSign = 0, is_form = 0;
VideoMode desktop = VideoMode::getDesktopMode();
float dWidth = desktop.width;
float dHeight = desktop.height;
float dBPP = desktop.bitsPerPixel;
#pragma endregion VARIABLES	

/*char Cle[] = "MUSIQUE"; // Formé de caractères de 'A' à 'Z' uniquement !
char Ori[] = "J'ADORE EC_OUTER LA RADIO TOUTE LA JOURNEE";
char Cry[100], Dec[100]; // Au moins aussi longs que Ori
int nCle = strlen(Cle), nTxt = strlen(Ori);*/

#pragma region RESSOURCES
void LoadGameImage() {
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

void LoadFont() {
	if (!main_font.loadFromFile("../ressources/fonts/Players.ttf")) {
		std::cout << "OU EST CETTE FOUTU POLICE PLAYERS ??" << std::endl;
	}
	if (!arial_font.loadFromFile("../ressources/fonts/arial.ttf")) {
		std::cout << "OU EST CETTE FOUTU POLICE ARIAL ??" << std::endl;
	}
}

void TextFont() {
	pseudo.setFont(main_font);
	password.setFont(arial_font);
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
#pragma endregion RESSOURCES	

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

string form(Text stringF, Text otherString, string stringForm) {
	int stop = 0;

	while (stop == 0) {
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case  Event::MouseButtonPressed: {
				if (event.mouseButton.button == Mouse::Left
					&& event.mouseButton.x > 0
					&& event.mouseButton.x < (dWidth)
					&& event.mouseButton.y > 0
					&& event.mouseButton.y < (dHeight)
				){
					return stringForm;
				}
			} break;

			case  Event::TextEntered: {
				if (event.text.unicode < 128 && event.text.unicode != 27 && event.text.unicode != 8) {
					if (stringForm.length() < 15) {
						stringF.setString("");
						stringForm = stringForm + static_cast<char>(event.text.unicode);
					}
				}

				if (event.text.unicode == 8 && stringForm != "") {
					stringForm.pop_back();
				}

				if (event.text.unicode == 27) {
					return stringForm;
				}
			} break;

			default:
				break;
			}
		}

		stringF.setString(stringForm);
		window.clear();
		window.draw(sprite_bg_login);
		window.draw(otherString);
		window.draw(stringF);
		window.display();
	}
}

vector<string> formPass(Text stringF, Text otherString, string stringForm, string stringPassPoint) {
	int stop = 0;
	string stringPass = stringPassPoint;

	while (stop == 0) {
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case  Event::MouseButtonPressed: {
				if (event.mouseButton.button == Mouse::Left
					&& event.mouseButton.x > 0
					&& event.mouseButton.x < (dWidth)
					&& event.mouseButton.y > 0
					&& event.mouseButton.y < (dHeight)
					) {

					vector<string> result;
					result.push_back(stringForm);
					result.push_back(stringPass);
					return result;
				}
			} break;

			case  Event::TextEntered: {
				if (event.text.unicode < 128 && event.text.unicode != 27 && event.text.unicode != 8) {
					if (stringForm.length() < 25) {
						stringForm = stringForm + static_cast<char>(event.text.unicode);
						stringPass = stringPass + static_cast<char>(183);
					}
				}
				
				if (event.text.unicode == 8 && stringForm != "") {
					stringPass.pop_back();
					stringForm.pop_back();
				}
		
				if (event.text.unicode == 27) {
					vector<string> result;
					result.push_back(stringForm);
					result.push_back(stringPass);
					return result;
				}
			} break;

			default:
				break;
			}
		}

		stringF.setString(stringPass);
		window.clear();
		window.draw(sprite_bg_login);
		window.draw(otherString);
		window.draw(stringF);
		window.display();
	}
}

void login() {
	bool login = true;
	string stringPseudo = "";
	vector<string> stringPassword;
	string stringPass = "";
	string stringPassPoint = "";

	while (login)
	{
#pragma region EVENT
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::Escape) {
					login = false;
				}
			} break;

			case  Event::MouseButtonPressed: {
				if (event.mouseButton.button == Mouse::Left
					&& event.mouseButton.x > 0
					&& event.mouseButton.x < (100)
					&& event.mouseButton.y > 0
					&& event.mouseButton.y < (100)
				){
					login = false;
					isLogin = 0;
					isSign = 0;
				}

				if (event.mouseButton.button == Mouse::Left
					&& event.mouseButton.x > 553
					&& event.mouseButton.x < (553 + 609)
					&& event.mouseButton.y > 250
					&& event.mouseButton.y < (250 + 68)
				){
					pseudo.setCharacterSize(24);
					pseudo.setFillColor(Color::Black);
					pseudo.setPosition(560, 257);
					stringPseudo = form(pseudo, password, stringPseudo);
				}

				if (event.mouseButton.button == Mouse::Left
					&& event.mouseButton.x > 630
					&& event.mouseButton.x < (630 + 609)
					&& event.mouseButton.y > 354
					&& event.mouseButton.y < (354 + 68)
				){
					password.setLetterSpacing(0.2);
					password.setCharacterSize(50);
					password.setFillColor(Color::Black);
					password.setPosition(637, 348);

					stringPassword = formPass(password, pseudo, stringPass, stringPassPoint);
					stringPass = stringPassword[0];
					stringPassPoint = stringPassword[1];
				}
			} break;

			default:
				break;
			}
		}
#pragma endregion EVENT

		window.clear(Color::Black);
		window.draw(sprite_bg_login);
		pseudo.setString(stringPseudo);
		password.setString(stringPassPoint);
		window.draw(password);
		window.draw(pseudo);
		window.display();
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
	window.create(VideoMode(dWidth, dHeight, dBPP), "GameSoccer", Style::Fullscreen);
#pragma endregion WINDOW

	while (window.isOpen())
	{		
		window.clear(Color::Black);

#pragma region VISUEL

		LoadGameImage();
		LoadFont();
		TextFont();

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

#pragma endregion VISUEL

#pragma region EVENT
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			} break;

			case  Event::MouseButtonPressed: {
				if (event.mouseButton.button == Mouse::Left
					&& event.mouseButton.x > posX
					&& event.mouseButton.x < (posX + xSize)
					&& event.mouseButton.y > posY_login
					&& event.mouseButton.y < (posY_login + ySize)
					) {
					isLogin = 1;
					window.clear(Color::Black);
					window.draw(sprite_background);
					window.draw(sprite_sign);
					window.draw(sprite_login_push);
				}

				if (event.mouseButton.button == Mouse::Left
					&& event.mouseButton.x > posX
					&& event.mouseButton.x < (posX + xSize)
					&& event.mouseButton.y > posY_sign
					&& event.mouseButton.y < (posY_sign + ySize)
					) {
					isSign = 1;
					window.clear(Color::Black);
					window.draw(sprite_background);
					window.draw(sprite_login);
					window.draw(sprite_sign_push);
				}
			} break;

			case sf::Event::MouseButtonReleased: {
				if (isLogin == 1 && event.mouseButton.button == sf::Mouse::Left) {
					login();
				}
			} break;

			default:
				break;
			}
		}
#pragma endregion EVENT

		window.display();
	}

	return 0;
}