#include <fstream>
#include <iostream>
#include "Personnage.h"
#include "Arme.h"
#include "BouleGlace.h"
#include "Epee.h"
#include "Marteau.h"
#include "Magicien.h"
#include "Guerrier.h"
#include <conio.h>;
#include <chrono>;
#include <thread>;
#include <SFML/Graphics.hpp>;


using namespace sf;

using namespace std;
using namespace JeuBaston;

int main() {
	cout << "Bonjour" << endl; // prints !!!Hello World!!!


	vector<Personnage*> listePersonnages;
	vector<Arme*> listeArmes;


	Arme* bouleGlace;
	bouleGlace = new BouleGlace(50);
	listeArmes.push_back(bouleGlace);
	Arme* epee;
	epee = new Epee(200);
	listeArmes.push_back(epee);

	Personnage* magicienGlace; // instance du pointeur vers un objet personnage
	magicienGlace = new Magicien("Gandalf", 100);
	magicienGlace->ajouterArme(bouleGlace);
	listePersonnages.push_back(magicienGlace);
	//cout << magicienGlace->exporter() ;

	Personnage* guerrier;
	guerrier = new Guerrier("soldat", 100);
	guerrier->ajouterArme(epee);
	listePersonnages.push_back(guerrier);


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
		
		cout << "TEST";

		/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(shape);
			window.display();
		}*/
		int tour = 0;
		int touche;
		bool gameIsRunning = true;
		int position = 0;

		float pas = 10;

		while (gameIsRunning)
		{
			
			this_thread::sleep_for(chrono::milliseconds(1000 / 60));
			if (_kbhit())
			{
				touche = _getch();
				//cout << "touche " << touche << " " << tour << endl;

					switch (touche)
					{
					case 'a':
						gameIsRunning = false;
						break;
					case 'z':
						guerrier->deplacer(0, -pas);
						break;
					
					case 32: //espace
						cout << "On change de perso !" << endl;
						position++;
						if (position >= listePersonnages.size()) {
							position = 0;
						}
						;
						cout << "Le personnage : " << listePersonnages.at(position)->getNom();
						cout << "entre en jeu!" << endl;
						break;
					}
			}
				
		}
			while (_kbhit()) _getch();
			//cout << "tour " << tour << endl;
			tour++;
		
		delete bouleGlace;
		delete epee;
		delete magicienGlace;
		delete guerrier;


		//system("pause");
		return 0;



}