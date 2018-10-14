#include "Magicien.h"
#include <iostream>


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
		return "<Magicien><nom></nom><age></age><magie></magie></Magicien>";
	}
}