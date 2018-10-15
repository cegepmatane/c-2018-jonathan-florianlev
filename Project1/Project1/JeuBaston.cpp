#include <fstream>
#include <iostream>
#include "Personnage.h"
#include "Arme.h"
#include "BouleGlace.h"
#include "Epee.h"
#include "Marteau.h"
#include "Magicien.h"
#include "Guerrier.h"


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
	//cout << magicienGlace->exporter() << endl; // Quelle fonction ??? Magicien::exporter
	magicienGlace->ajouterArme(bouleGlace);

	Personnage* guerrier;
	guerrier = new Guerrier("soldat", 100);
	guerrier->ajouterArme(epee);

	delete bouleGlace;
	delete epee;
	delete magicienGlace;
	delete guerrier;
	

	return 0;
	
}