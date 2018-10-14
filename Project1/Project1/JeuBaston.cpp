#include <fstream>
#include <iostream>
#include "Personnage.h"
#include "Magicien.h"
#include "Guerrier.h"


using namespace std;
using namespace JeuBaston;

int main() {
	cout << "Bonjour" << endl; // prints !!!Hello World!!!

	Personnage personnageSansPointeur;
	Magicien objetMagicien("LaLa", 200);
	personnageSansPointeur = (Personnage)objetMagicien;
	cout << personnageSansPointeur.exporter() << endl; // Quelle fonction ??? Personnage::exporter()

	Personnage* personnage; // instance du pointeur vers un objet personnage
	personnage = new Magicien("Lolo", 100);
	cout << personnage->exporter() << endl; // Quelle fonction ??? Magicien::exporter

	return 0;
	
}