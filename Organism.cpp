#include "Organism.h"

Organism::Organism(Species vName, int iMember) : member(iMember)
{
	//cout << "Organism being created and adding to vector....\n"; //change to file io later
	speciesN = vName;
}

