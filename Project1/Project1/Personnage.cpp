#include "Personnage.h"
#include <sstream>


namespace JeuBaston {

	Personnage::Personnage()
	{
		this->age = 0;
		this->nom = "Inconnu";
	}

	Personnage::Personnage(string nom)
	{
		this->age = 0;
		this->pv = 0;
		this->nom = nom;
	}
	Personnage::Personnage(string nom, int age) {
		this->age = age;
		this->pv = 0;
		this->nom = nom;
	}
	Personnage::Personnage(string nom, int age, int pv) {
		this->age = age;
		this->nom = nom;
		this->pv = pv;
	}

	Personnage::~Personnage() {
	}

	void Personnage::deplacer(float deplacementX, float deplacementY)
	{
		this->x += deplacementX;
		this->y += deplacementY;
		cout << deplacementX;
		cout << deplacementY;
	}

	string Personnage::exporter()
	{
		stringstream xml;
		xml << "<Personnage><nom>" << this->nom <<"</nom><age>"<< this->age <<"</age></Personnage>";
		return xml.str();

	}

	void Personnage::ajouterArme(Arme* nouvelleArme)
	{
		this->armesSecondaires.push_back(nouvelleArme);
	}

}