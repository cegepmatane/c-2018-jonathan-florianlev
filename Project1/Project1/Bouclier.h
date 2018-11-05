#pragma once

#include "Accessoire.h"
#ifndef BOUCLIER_H_
#define BOUCLIER_H_
namespace JeuBaston {

	class Bouclier : public Accessoire
	{
	public:
		Bouclier();

		~Bouclier();

	protected:
		int protection;
	};


}

#endif