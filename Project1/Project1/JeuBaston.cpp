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


using namespace std;
using namespace JeuBaston;

int main() {
	cout << "Bonjour" << endl; // prints !!!Hello World!!!

	Arme* bouleGlace;
	bouleGlace = new BouleGlace(50);
	Arme* epee;
	epee = new Epee(200);

	Personnage* magicienGlace; // instance du pointeur vers un objet personnage
	magicienGlace = new Magicien("Gandalf", 100);
	cout << magicienGlace->exporter() ;
	magicienGlace->ajouterArme(bouleGlace);

	Personnage* guerrier;
	guerrier = new Guerrier("soldat", 100);
	guerrier->ajouterArme(epee);

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
	while (!fichierPersonnages.eof())
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

		delete bouleGlace;
		delete epee;
		delete magicienGlace;
		delete guerrier;

		//Boucle jeu
		int tour = 0;
		int touche;
		bool gameIsRunning = true;
		while (gameIsRunning)
		{
			// PREMIER PROBLEME-SOLUTION : dormir sans occuper les ressources
			this_thread::sleep_for(chrono::milliseconds(1000 / 60));
			// SECOND PROBLEME-SOLUTION : lire les entrées sans bloquer la boucle
			if (_kbhit())
			{
				touche = _getch();
				cout << "touche " << touche << " " << tour << endl;
				switch (touche)
				{
				case 'q':
					gameIsRunning = false;
					break;
				}
			}
			while (_kbhit()) _getch();
			//cout << "tour " << tour << endl;
			tour++;
		}

		//system("pause");
		return 0;



	}
}