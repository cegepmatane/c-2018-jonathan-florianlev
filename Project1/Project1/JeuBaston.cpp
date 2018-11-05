#include <fstream>
#include <iostream>
#include "Personnage.h"
#include "Arme.h"
#include "AccessoireVide.h"

#include "BouleGlace.h"
#include "Epee.h"
#include "Marteau.h"
#include "Magicien.h"
#include "Guerrier.h"
#include "Accessoire.h"
#include "Bouclier.h"

#include <conio.h>;
#include <chrono>;
#include <thread>;
#include <SFML/Graphics.hpp>;


using namespace sf;

using namespace std;
using namespace JeuBaston;

int main() {
	cout << "COUCOU POUR GAGNER SORTEZ DE L'ECRAN VERS LE HAUT \n POUR PERDRE APPUYER SUR J \n" << endl; // prints !!!Hello World!!!
	cout << "POUR CHANGER DE PERSONNAGE APPUYER SUR ESPACE \n" << endl;
	cout << "POUR ACTIVER LE BOUCLIER APPUYEZ SUR J \n" << endl;


	vector<Personnage*> listePersonnages;
	vector<Arme*> listeArmes;
	vector<sf::Texture> listeTexture;
	vector<sf::Texture> listeTextureAccessoire;
	vector<Accessoire*> listeAccessoire;


	sf::Texture textureGuerrier;
	sf::Texture textureMagicien;
	sf::Texture textureBouclier;
	sf::Texture textureVide;


	if (!textureGuerrier.loadFromFile("C:\\Users\\florian\\Documents\\c++\\projet-cpp-2018-florianlev\\Project1\\images\\guerrier.png"))
	{
		cout << "File not successfully loaded" << endl;
	}

	if (!textureMagicien.loadFromFile("C:\\Users\\florian\\Documents\\c++\\projet-cpp-2018-florianlev\\Project1\\images\\magicien.png"))
	{
		cout << "File not successfully loaded" << endl;
	}
	if (!textureBouclier.loadFromFile("C:\\Users\\florian\\Documents\\c++\\projet-cpp-2018-florianlev\\Project1\\images\\bouclier.png"))
	{
		cout << "File not successfully loaded" << endl;
	}
	int position = 0;
	int positionAccessoire = 0;

	Accessoire* aucunAccessoire;
	aucunAccessoire = new AccessoireVide();
	listeAccessoire.push_back(aucunAccessoire);

	textureVide.create(50, 50);
	listeTextureAccessoire.push_back(textureVide);

	Accessoire* bouclier;
	bouclier = new Bouclier();
	listeAccessoire.push_back(bouclier);

	Arme* bouleGlace;
	bouleGlace = new BouleGlace(50);
	listeArmes.push_back(bouleGlace);

	Arme* epee;
	epee = new Epee(200);
	listeArmes.push_back(epee);

	Personnage* magicienGlace; // instance du pointeur vers un objet personnage
	magicienGlace = new Magicien("Gandalf", 100);
	magicienGlace->ajouterArme(bouleGlace);
	magicienGlace->setPositions(100, 100);
	listePersonnages.push_back(magicienGlace);
	//cout << magicienGlace->exporter() ;

	Personnage* guerrier;
	guerrier = new Guerrier("soldat", 100);
	guerrier->ajouterArme(epee);
	guerrier->setPositions(300, 300);
	listePersonnages.push_back(guerrier);

	listeTexture.push_back(textureMagicien);
	listeTexture.push_back(textureGuerrier);
	listeTextureAccessoire.push_back(textureBouclier);

	sf::Sprite spriteBouclier;
	spriteBouclier.setTexture(listeTextureAccessoire.at(positionAccessoire));

	sf::Sprite spriteJoueur;
	spriteJoueur.setTexture(listeTexture.at(position));
	spriteJoueur.setPosition(550.0f, 600.0f);

	sf::Vector2f* vecteurHaut = new sf::Vector2f(0, -20);
	sf::Vector2f* vecteurBas = new sf::Vector2f(0, 20);
	sf::Vector2f* vecteurDroite = new sf::Vector2f(20, 0);
	sf::Vector2f* vecteurGauche = new sf::Vector2f(-20, 0);
	

	ofstream fichierBaston;
	fichierBaston.open("../data/baston.xml");
	fichierBaston << "<baston>" << magicienGlace->exporter() << guerrier->exporter() << "</baston>";
	fichierBaston.close();

	ifstream fichierPersonnages;
	fichierPersonnages.open("../data/baston.csv");
	string ligne;
	//getline(fichierPersonnages, ligne);
	//cout << "Première ligne : " << ligne;
	unsigned int dernierePosition = 0;
	unsigned int positionPointVirgule = 0;
	/*while (!fichierPersonnages.eof())
	{
		getline(fichierPersonnages, ligne);
		cout << "Ligne : " << ligne << endl;
		//int trouvaille = ligne.find(";", 6);
		//cout << "test trouvaille " << trouvaille;
		dernierePosition = 0;
		do
		{
			positionPointVirgule = ligne.find(";", dernierePosition); // find retourne la position du prochain ;
			//cout << " positionPointVirgule : " << positionPointVirgule;
			string valeur = ligne.substr(dernierePosition, positionPointVirgule - dernierePosition); // substr prend la position de départ + le nombre de char
			//cout << " position : " << positionPointVirgule;
			cout << " valeur : " << valeur;
			//cout << " positionPointVirgule avant +1: " << positionPointVirgule;
			dernierePosition = positionPointVirgule + 1;
			//cout << " derniere position apres +1: " << dernierePosition;
			//cout << endl;
		}
		//while(ligne.length() > dernierePosition && dernierePosition > 0);
		//while(string::npos != dernierePosition);
		while (0 != dernierePosition); // 0 car -1 de find +1 = 0
		cout << endl;
		*/
		

		//Boucle jeu


		sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
		string cheminImageBackground = "C:\\Users\\florian\\Documents\\c++\\projet-cpp-2018-florianlev\\Project1\\images\\background.jpg";
		Texture ambianceHerbe;
		Sprite * scene = NULL;
		if (ambianceHerbe.loadFromFile(cheminImageBackground)) {
			scene = new Sprite(ambianceHerbe);
		}
		bool gameIsRunning = true;
		int tour = 0;
		int touche;

		bool victoire;
		bool defaite;
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();

			this_thread::sleep_for(chrono::milliseconds(1000 / 60));
			if (_kbhit())
			{

				touche = _getch();
				switch (touche)
				{
				case 27:
					gameIsRunning = false;
					break;
				
				
				case 'z':
					spriteJoueur.move(*vecteurHaut);
					break;
				

				case 'q':
					spriteJoueur.move(*vecteurGauche);
					break;

				case 's':
					spriteJoueur.move(*vecteurBas);
					break;

				case 'd':
					spriteJoueur.move(*vecteurDroite);
					break;
				

				case 32: //espace
					cout << "On change de perso !" << endl;
					position++;
					if (position >= listePersonnages.size()) {
						position = 0;
					}
					cout << "Le personnage : " << listePersonnages.at(position)->getNom();
					cout << "en baston!" << endl;
					cout << "PV : " << listePersonnages.at(position)->getPv();

					spriteJoueur.setTexture(listeTexture.at(position));

					break;

				

				case 'g':
					cout << " BOUCLIER !!! " << endl;
					positionAccessoire++;
					if (positionAccessoire >= listeAccessoire.size()) {
						positionAccessoire = 0;
					}
					cout << positionAccessoire;
					listePersonnages.at(position)->ajouterAccessoire(listeAccessoire.at(positionAccessoire));
					cout << listeAccessoire.at(positionAccessoire)->getNom() << endl;
					spriteBouclier.setTexture(listeTextureAccessoire.at(positionAccessoire));
					spriteBouclier.setPosition(200.0f, 200.0f);
					window.draw(spriteBouclier);

					break;


				case 'j':
					defaite = true;
					window.close();

				}

			

					
			}
			while (_kbhit()) {
				_getch();
			}

			if (spriteJoueur.getPosition().y == -160) {
				victoire = true;
				window.close();
			}
			tour++;
			if (scene) window.draw(*scene);
			window.draw(spriteJoueur);
			//window.draw(spriteBouclier);

			window.display();

		}

		if (victoire) {
			cout << "C'EST GAGNER !!" << endl;
		}
		else if (defaite) {
			cout << "PERDUUU" << endl;
		}
		_getch();
	
		

		float pas = 10;

		delete bouleGlace;
		delete epee;
		delete magicienGlace;
		delete guerrier;


		//system("pause");
		return 0;



}