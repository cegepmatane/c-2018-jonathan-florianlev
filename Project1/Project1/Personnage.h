
#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_
#include <iostream>
#include "Arme.h"

using namespace std;

namespace JeuBaston {

	class Personnage
	{
	public:
		Personnage();
		Personnage(Arme* arme);
		Personnage(string nom);
		Personnage(string nom, int age);
		Personnage(string nom, int age, int pv);

		Arme arme;

		virtual ~Personnage();

		virtual string exporter();

		int getPv() const {
			return pv;
		}

		void setPv(int pv) {
			this->pv = pv;
		}

		int getAge() const {
			return age;
		}

		void setAge(int age) {
			this->age = age;
		}

		const string& getNom() const {
			return nom;
		}

		void setNom(const string& nom) {
			this->nom = nom;
		}

	protected:
		string nom;
		int age;
		int pv;
	};
}

#endif /* PERSONNAGE_H_ */
