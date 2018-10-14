#pragma once

#ifndef MARTEAU_H_
#define MARTEAU_H_
#include "Arme.h"

namespace JeuBaston {

	class Marteau : public Arme
	{
	public:
		Marteau();
		Marteau(int force);

		virtual ~Marteau();
	};

}
#endif