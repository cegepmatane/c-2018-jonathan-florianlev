
#ifndef MAGICIEN_H_
#define MAGICIEN_H_

#include "Personnage.h"

namespace JeuBaston {

	class Magicien : public Personnage {
	public:
		Magicien();
		Magicien(string nom, int magie);
		Magicien(string nom, int magie, int age);
		virtual ~Magicien();
		string exporter();

		int getMagie() const {
			return magie;
		}

		void setMagie(int magie) {
			this->magie = magie;
		}

	protected:
		int magie;

	};

}
#endif /* MAGICIEN_H_ */
