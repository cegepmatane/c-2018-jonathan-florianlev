#pragma once

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_
#include <iostream>
using namespace std;

namespace JeuBaston {
	class Personnage
	{
	public:
		Personnage();
		Personnage(string nom);
		Personnage(string nom, int age);

		virtual ~Personnage();

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


	};



}
