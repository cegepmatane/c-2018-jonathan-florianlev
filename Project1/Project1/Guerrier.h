#pragma once

#ifndef GUERRIER_H_
#define GUERRIER_H_

#include "Personnage.h"

namespace JeuBaston {

	class Guerrier : public Personnage
	{
	public:
		Guerrier();
		Guerrier(string nom, int force);
		Guerrier(string nom, int force, int age);
		virtual ~Guerrier();
		string exporter();


		int getForce() const {
			return force;
		}

		void setForce(int force) {
			this->force = force;
		}

	protected:
		int force;
	};
}
#endif
