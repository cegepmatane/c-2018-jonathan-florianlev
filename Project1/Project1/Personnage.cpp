#include "Personnage.h"
#include <iostream>


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

	string Personnage::exporter()
	{
		return "<Personnage><nom></nom><age></age></Personnage>";
	}

}