#pragma once
#ifndef ARME_H_
#define ARME_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace JeuBaston {
	class Arme
	{
	public:
		Arme();
		Arme(string nom);
		Arme(string nom, int degats);

		virtual ~Arme();
		virtual string exporter();


		int getDegats() const {
			return degats;
		}

		void setDegats(int degats) {
			this->degats = degats;
		}

		const string& getNom() const {
			return nom;
		}

		void setNom(const string& nom) {
			this->nom = nom;
		}

	protected:
		string nom;
		int degats;
	};
}
#endif 