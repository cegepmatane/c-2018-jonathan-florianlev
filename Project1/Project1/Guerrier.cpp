#include "Guerrier.h"
#include <iostream>
#include <sstream>


namespace JeuBaston {

	Guerrier::Guerrier(string nom, int force) : Personnage(nom)
	{
		this->x = 0;
		this->y = 0;
		this->force = force;
	}
	Guerrier::Guerrier(string nom, int force, int age) : Personnage(nom, age)
	{
		this->x = 0;
		this->y = 0;
		this->force = force;
	}

	Guerrier::~Guerrier()
	{
		delete this->arme;
	}

	string Guerrier::exporter()
	{
		stringstream xml;
		xml << "<Guerrier><nom>" << this->nom << "</nom><age>" << this->age << "</age><force>" << this->force << "</force></Guerrier>";
		return xml.str();
	}
}