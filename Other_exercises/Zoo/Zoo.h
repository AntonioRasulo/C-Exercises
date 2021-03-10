
#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"

class Zoo{
	private:
		vector<Animal*> v;
	public:

		Zoo();

		Zoo(Animal* a);

		~Zoo();

		void Insert(Animal* a);

		void Clear();
};

#endif
