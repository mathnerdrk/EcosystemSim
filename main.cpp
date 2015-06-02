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
  string name;
  int reprAge; //what age will the organism be mature enough to produce offspring
  int deathAge; // what age will the organism die (if it is still alive) getting to an old age?
};

class Organism
{
public:
  Organism(Species vName); // constructor

  int currentAge;
  Species speciesN;
};

vector<Organism> org; //Would it be better to have an array with a set limit? That way it is easier to have organisms die &
					  //"delete" them (unless there is a vector method that does this automatically that I'm forgetting?)

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
  cout << "How many species do you want to have?: ";
  int species;
  cin >> species;

  for(int i = 0; i < species; i++)
  {
	  Species names;

	  cout << "What is the name of this species?: ";
	  string name;
	  cin >> name;
	  names.name = name;

	  cout << "How many organisms are present of given species?: ";
	  int numOrgasm;
	  cin >> numOrgasm;


	  for(int i = 0; i < numOrgasm; i++)
	  {
		  Organism orgasm(names);
		  cout << "What is the age of " << names.name << " #" << i << "?: ";
		  int age;
		  cin >> age;
		  orgasm.currentAge = age;
	  }

	  cout << "At what age will the organisms of the species specified be mature enough to reproduce?: ";
	  int repAge;
	  cin >> repAge;
	  names.reprAge = repAge;

	  cout << "At what age will the organisms of the species specified die, if it is able to reach that age?: ";
	  int deathAge;
	  cin >> deathAge;
	  names.deathAge = deathAge;
  }

  string choice = "a";
  while(choice[0] != 'z') // loop to stay in program, z to quit (unless you want it to be 'q')
  {
	  cout << "Please choose one of the following options:";
	  cout << "(a) - Advance one week" << endl; // note: might not need some of these (might be too specific or too long)
	  cout << "(b) - Advance one month" << endl;
	  cout << "(c) - Advance three months" << endl;
	  cout << "(d) - Advance six months" << endl;
	  cout << "(e) - Advance one year" << endl;
	  cout << "(f) - Advance five years" << endl;
	  cout << "(g) - List out all organisms alive at present" << endl;
	  //cout << "(h) - there will be more things we need to do later
	  cout << "(z) - Quit" << endl;

	  cin >> choice;

	  switch(choice[0])
	  {
	  case 'a':
		  {
			  //in development
		  }
	  case 'b':
		  {
			  //in development
		  }
	  case 'c':
		  {
			  //in development
		  }
	  case 'd':
		  {
			  //in development
		  }
	  case 'e':
		  {
			  //in development
		  }
	  case 'f':
		  {
			  //in development
		  }
	  case 'g':
		  {
			  for(int i = 0; i < org.size; i++)
			  {
				  cout << "Name: " << org[i].speciesN.name << ", Age: " << org[i].currentAge << endl;
			  }
		  }
	  case 'z': break;
	  default:
		  {

		  }
	  }
  }

  

  return 0;
}

//method bodies:
/*example:
void nando(int overachievinglevel, int richlevel)
{
  //do stuff to nando
}
*/
