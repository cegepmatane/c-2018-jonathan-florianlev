#include "Arme.h"
#include <iostream>

#include "Arme.h"
#include "sstream"

namespace JeuBaston {

	Arme::Arme()
	{
		this->degats = 0;
		this->nom = "Inconnu";
	}
	Arme::Arme(string nom)
	{
		this->degats = 0;
		this->nom = nom;
	}
	Arme::Arme(string nom, int degats)
	{
		this->degats = degats;
		this->nom = nom;
	}

	Arme::~Arme()
	{
	}

	string Arme::exporter() {
		stringstream xml;
		xml << "<arme><nom>" << nom << "</nom>";
		xml << "<degat>" << nom << "</degat></arme>";
		return xml.str();

	}

}

