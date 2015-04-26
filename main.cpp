#include<iostream> //basic c++ library
#include<fstream> // file IO library
#include<string> // string library
#include<vector> //vector library
//can add more #includes if need more libraries

using namespace std;

//global variables:


//classes:
class Species
{
public:
  void Speciesset(string nameT) //constructor
  {
    name = nameT;
  }
private: 
  string name;
};

class Organism
{
public:
  Organism(Species vName);
  
private: 
  int currentAge;
  int deathAge; // what age will the organism die (if it is still alive) getting to an old age?
  Species speciesN;
};

vector<Organism> org;

Organism::Organism(Species vName)
{
   cout << "Organism being created and adding to vector....\n"; //change to file io later
   org.push_back(*this);
   speciesN = vName;
}
//method declarations:
/*example:
void nando(int overachievinglevel, int richlevel);
*/

int main()
{
  Species newSpecies = Species();
  newSpecies.Speciesset("YOLO");
  Organism organism = Organism(newSpecies);

  return 0;
}

//method bodies:
/*example:
void nando(int overachievinglevel, int richlevel)
{
  //do stuff to nando
}
*/
