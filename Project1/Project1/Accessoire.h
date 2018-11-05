#pragma once
#ifndef ACCESSOIRE_H_
#define ACCESSOIRE_H_
#include <iostream>
#include <fstream>
using namespace std;

namespace JeuBaston {

	class Accessoire
	{
	public:
		Accessoire(string nom, int protection);


		virtual ~Accessoire();

		const string& getNom() const {
			return nom;
		}

	protected:
		string nom;
		int protection;
	};


}
#endif