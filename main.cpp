#include<iostream> //basic c++ library
#include<fstream> // file IO library
#include<string> // string library
#include<vector> //vector library
//can add more #includes if need more libraries

using namespace std;

//classes:
class Organism
{
public:
  string name;
  int currentAge;
  int deathAge; // what age will the organism die (if it is still alive) getting to an old age?
  Organism();
}
//global variables:
vector<m_organism> org;

//constructor
Organism::Organism()
{
  cout << "Organism being created and adding to vector....\n"; //change to file io later
  org.push_back(*this);
}

//method declarations:
/*example:
void nando(int overachievinglevel, int richlevel);
*/

int main()
{
  
  return 0;
}

//method bodies:
/*example:
void nando(int overachievinglevel, int richlevel)
{
  //do stuff to nando
}
*/
