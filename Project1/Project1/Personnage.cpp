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
		this->pv = 50;
		this->nom = nom;
	}
	Personnage::Personnage(string nom, int age) {
		this->age = age;
		this->pv = 50;
		this->nom = nom;
	}
	Personnage::Personnage(string nom, int age, int pv) {
		this->age = age;
		this->nom = nom;
		this->pv = pv;
	}
	Personnage::~Personnage() {
		delete this->illustration;
		delete this->texture;
	}


	void Personnage::setPositions(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void Personnage::deplacer(float deplacementX, float deplacementY)
	{
		this->x += deplacementX;
		this->y += deplacementY;
		this->illustration->setPosition(this->x, this->y);
	}

	void Personnage::attaquer(Arme * arme) {
		int degats = arme->getDegats();
		this->pv -= degats;
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
		this->arme = arme;
	}

	void Personnage::ajouterAccessoire(Accessoire* nouvelleAccessoire) {
		this->accessoireSecondaire.push_back(nouvelleAccessoire);
		this->accessoire = accessoire;
	}

	void Personnage::afficher(RenderWindow& fenetre)
	{
		fenetre.draw(*illustration);
	}

}	