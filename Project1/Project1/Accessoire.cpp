#include "Accessoire.h"
#include <sstream>

namespace JeuBaston {


	Accessoire::Accessoire(string nom, int protection)
	{
		this->nom = nom;
		this->protection = protection;
	}


	Accessoire::~Accessoire()
	{
	}
}