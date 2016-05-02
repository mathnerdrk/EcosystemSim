#include<string>
#include<vector>

using namespace std;

#ifndef SPECIES_H_
#define SPECIES_H_

class Species
{
public:
	string name;
	double reprAge; //what age will the organism be mature enough to produce offspring
	double deathAge; // what age will the organism die (if it is still alive) getting to an old age?
	double startMass; //what is the mass the organism is born?
	double massToNotDie; //what is the amount of mass increased every year?
	vector<Species> predators; //what organisms will eat this species?
	vector<Species> prey; //what organisms will this species eat?
};

#endif /* SPECIES_H_ */
