#include "Guerrier.h"
#include <iostream>


namespace JeuBaston {

	Guerrier::Guerrier(string nom, int force) : Personnage(nom)
	{
		this->force = force;
	}
	Guerrier::Guerrier(string nom, int force, int age) : Personnage(nom, age)
	{
		this->force = force;
	}

	Guerrier::~Guerrier()
	{
		delete this->arme;
	}
}