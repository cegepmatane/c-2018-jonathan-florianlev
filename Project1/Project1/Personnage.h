
#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_
#include <iostream>
#include "Arme.h"
#include <vector>

using namespace std;

namespace JeuBaston {

	class Personnage
	{
	public:
		Personnage();
		Personnage(string nom);
		Personnage(string nom, int age);
		Personnage(string nom, int age, int pv);

		

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

		void ajouterArme(Arme * nouvelleArme);


	protected:
		string nom;
		int age;
		int pv;
		Arme * arme;
		vector<Arme *> armesSecondaires;
	};
}

#endif /* PERSONNAGE_H_ */
