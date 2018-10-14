#pragma once

#ifndef EPEE_H_
#define EPEE_H_

#include "Arme.h"
namespace JeuBaston {

	class Epee : public Arme
	{
	public:
		Epee();
		Epee(int force);

		virtual ~Epee();
	};
}
#endif
