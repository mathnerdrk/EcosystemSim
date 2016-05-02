#include "Species.h"

using namespace std;

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Organism
{
public:
	Organism(Species vName, int iMember); // constructor; in Organism.cpp

	float currentAge;
	Species speciesN;
	float currentMass;

	int getMember()
	{
		return this->member;
	}

private:
	int member;
};

#endif /* ORGANISM_H_ */
