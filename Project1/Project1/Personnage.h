
#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_
#include <iostream>
#include "Arme.h"
#include "Accessoire.h"

#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
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
			cout << nom << endl;

			return nom;
		}

		void setNom(const string& nom) {
			this->nom = nom;
		}

		const Arme* getArme() const {
			return arme;
		}
		void setArme(Arme* arme) {
			this->arme = arme;
		}

		const string& getAccessoire() const {
			return accessoire->getNom();
		}

		int getX() const {
			return x;
		}
		int getY() const {
			return y;
		}


		void setPositions(int x, int y);
		void ajouterArme(Arme * nouvelleArme);
		void ajouterAccessoire(Accessoire * nouvelleAccessoire);
		void deplacer(float deplacementX, float deplacementY);
		void attaquer(Arme * arme);
		virtual void afficher(RenderWindow& fenetre);

	protected:
		string nom;
		int age;
		int pv;
		int x;
		int y;
		Texture * texture = NULL;
		Sprite * illustration = NULL;
		Arme * arme;
		Accessoire * accessoire;
		vector<Arme *> armesSecondaires;
		vector<Accessoire *> accessoireSecondaire;


	};
}

#endif /* PERSONNAGE_H_ */
