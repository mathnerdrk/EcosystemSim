#include <iostream> //basic c++ input/output library
#include <fstream> // file IO library
#include <string> // string library
#include <vector> //vector library
#include <algorithm> //algorithm library

#include <stdio.h> //string to int
#include <string.h> //string to int

#include <assert.h> //asserting

#include "Species.h" //Species class declaration
#include "Organism.h" //Organism class declaration

using namespace std;

//global variables:
int year = 0;
ofstream filePrinter;

vector<Organism> org;

//method declarations:

void oneYear();

int main()
{
	cout << "Who is the author of this Ecosystem?: ";
	string name;
	cin >> name;

	//File IO Setup
	cout << "What file would you like to use (.txt): ";
	string fileName;
	cin >> fileName;

	filePrinter.open((fileName+".txt").c_str());

	filePrinter << "Author: " << name << endl;

	//Ecosystem Setup
	cout << "How many species do you want to have?: ";
	string s;
	cin >> s;

	int numSpecies = atoi(s.c_str());

	if(numSpecies == 0)
	{
		cout << "You entered 0, or a string, so the program is terminating...\n";
		return 0;
	}

	Species names;

	for(int i = 0; i < numSpecies; i++)
	{
		cout << "What is the name species #" << i+1 << "?: ";
		string name;
		cin >> name;
		names.name = name;
		filePrinter << "A new species was born!!! Name: " << name << "\nProperties of this species: \n";

		cout << "How many organisms are present of given species?: ";
		int numOrganism;
		cin >> numOrganism;

		cout << "What is the starting mass of all the organisms of the given species?: ";
		double mass;
		cin >> mass;
		names.startMass = mass;
		filePrinter << "\tStarting Mass: " << mass << endl;


		cout << "How much increase of mass is needed for the organism to stay alive?: ";
		double alive;
		cin >> alive;
		names.massToNotDie = alive;
		filePrinter << "\tNeeded mass to stay alive: " << alive << endl;

		cout << "All " << names.name << "s will start at age 0" << endl;

		cout << "At what age will the organisms of the species specified be mature enough to reproduce?: ";
		double repAge;
		cin >> repAge;
		names.reprAge = repAge;
		filePrinter << "\tReproduction age: " << repAge << endl;

		cout << "At what age will the organisms of the species specified die, if it is able to reach that age?: ";
		double deathAge;
		cin >> deathAge;
		names.deathAge = deathAge;
		filePrinter << "\tDeath age: " << deathAge << "\n\n";

		filePrinter << numOrganism << " Organisms were Born in Year " << year << " of Species " << names.name << endl;

		for(int j = 0; j < numOrganism; j++)
		{
			Organism organism(names, i);
			organism.currentAge = 0;
			organism.currentMass = organism.speciesN.startMass;
			org.push_back(organism);
		}

		filePrinter << endl;
	}

	string choice = "a";
	while(choice[0] != 'z') // loop to stay in program, z to quit (unless you want it to be 'q')
	{
		cout << "Please choose one of the following options:" << endl;
		cout << "(a) - Advance one year" << endl;
		cout << "(b) - Advance five years" << endl;
		cout << "(f) - List out number of each species" << endl;
		cout << "(g) - List out all organisms alive at present" << endl;
		//cout << "(h) - there will be more things I need to do later
		cout << "(z) - Quit" << endl;

		cin >> choice;

		switch(choice[0])
		{
		case 'a':
			{
				oneYear();

				cout << "Advancing One Year... \nYear: " << year << " CE\n\n";
				break;
			}

		case 'b':
			{
				for(int i = 0; i < 5; i++) oneYear();

				cout << "Advancing Five Years... \nYear: " << year << " CE\n\n";
				break;
			}

		case 'f':
			{
				//printing the number of each species by name
				if(org.size() < 1)
					cout << "No more organisms\n";
				else
				{
					int prevChange = 0;
					int i = 0;
					int counter = 0;

					vector<Organism>::iterator iter;

					for(iter = org.begin(); iter != org.end(); iter++, i++, counter++)
					{
						if(org[prevChange].getMember() != iter->getMember())
						{
							cout << org[prevChange].speciesN.name << ": " << counter << endl;

							prevChange = i;
							counter = 0;
						}
					}

					cout << org[prevChange].speciesN.name << ": " << counter << endl;
				}

				break;

			}

		case 'g':
			{
				//printing each organism
				if(org.size() < 1)
					cout << "No more organisms\n";
				else
				{
					for(unsigned int i = 0; i < org.size(); i++)
					{
						cout << "Name: " << org[i].speciesN.name << ", Age: " << org[i].currentAge << endl;
					}
				}

				break;
			}

		case 'z': break;
		case 'd': //debugging purposes
		{
			if(org.size() < 1)
				cout << "No more organisms\n";
			else
			{
				ofstream debug;
				debug.open("debugging.txt");

				debug << "-------------------Degbugging Test-------------------\n";
				for(unsigned int i = 0; i < org.size(); i++)
				{
					debug << "Name of Species: " << org[i].speciesN.name << endl;
					debug << "\tSpecies Reproduction Age: " << org[i].speciesN.reprAge << endl;
					debug << "\tSpecies Death Age: " << org[i].speciesN.deathAge << endl;
					debug << "\tSpecies Start Mass: " << org[i].speciesN.startMass << endl;
					debug << "\tSpecies Mass per Year to Not Die: " << org[i].speciesN.massToNotDie << endl;
					debug << "\tOrganism Current Age: " << org[i].currentAge << endl;
					debug << "\tOrganism Current Mass: " << org[i].currentMass << endl;

					debug << endl;
				}
				debug << "-----------------------------------------------------\n";
				cout << "Debugged into \"debugging.txt\"\n";
			}
			break;
		}

		default:
			{
				cout << "Not a valid option...\n";
				break;
			}
		}
	}

	cout << "Program is terminating...";
	filePrinter << "Program terminated at Year " << year << endl;
	if(org.size() == 0) filePrinter << "No Organisms are left.\n";
	else
	{
		filePrinter << "Organisms left: ";
		for(unsigned int i = 0; i < org.size(); i++)
		{
			filePrinter << "\tName: " << org[i].speciesN.name << ", Age: " << org[i].currentAge << ", Mass: " << org[i].currentMass << endl;
		}
	}

	//Clean Up
	filePrinter.close();
	org.clear();
	return 0;
}

//method bodies:

void oneYear()
{
	//advances one year
	//each organism grows a year
	bool deleted = false;

	for(unsigned int i = 0; i < org.size(); i++)
	{
		org[i].currentAge++;

		if(org[i].speciesN.deathAge < org[i].currentAge)
		{
			filePrinter << "An Organism of type " << org[i].speciesN.name << " has died at age " << org[i].currentAge << " of old age in year " << year << endl;
			deleted = true;

			if(org.size() < 2)
			{
				org.clear();
			}
			else
			{
				org.erase(org.begin() + i);
				i--;
			}
		}
	}

	if(deleted) filePrinter << endl;


	year++;
}
