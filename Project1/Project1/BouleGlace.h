#pragma once

#ifndef BOULEGLACE_H_
#define BOULEGLACE_H_

#include "Arme.h"

namespace JeuBaston {

	class BouleGlace : public Arme
	{
	public:
		BouleGlace();
		BouleGlace(int mana);

		virtual ~BouleGlace();
	};
}

#endif
