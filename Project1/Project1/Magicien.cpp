#include "Magicien.h"
#include <iostream>
#include <sstream>


namespace JeuBaston {

	Magicien::Magicien()
	{
	}
	Magicien::Magicien(string nom, int magie) : Personnage(nom)
	{
		this->magie = magie;
	}
	Magicien::Magicien(string nom, int magie, int age) : Personnage(nom, age)
	{
		this->magie = magie;
	}


	Magicien::~Magicien()
	{
		delete this->arme;
	}

	string Magicien::exporter()
	{
		stringstream xml;
		xml << "<Magicien><nom>" << this->nom << "</nom><age>" << this->age << "</age><magie>" << this->magie << "</magie></Magicien>";
		return xml.str();
	}
}