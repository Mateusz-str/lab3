#include "Slav.h"
#include <fstream>
#include <stdlib.h>
#include <sstream> 
#include <iterator>   
#include <algorithm> 

using namespace std;

vector <string> Slav::names;
int Slav::_counter = 0;

void Slav::init()
{
	srand(time(NULL));
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Slav::Slav()
{
	static int amountOfNames = (init(), names.size()); //Lazy evaliuation instrukcja wykona tylko raz, obydwie instrukcje wykonaj sie i zmienn przyjmie wartosc ostatniej instrukcj po przecinku
	_name = names[rand() % amountOfNames];
	_id = _counter++;
}

string Slav::description()
{
	return string("  ") + _name + " [" + to_string(_id) + "]";
}

gender Slav::checkGender()
	{
		if (_name[_name.length()-1]=='a')
			return female;
		else
			return male;
	} 
