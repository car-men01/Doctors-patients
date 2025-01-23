#include "Doctor.h"


Doctor::Doctor() : name{ "" }, specialisation{ "" } {}

Doctor::Doctor(string name, string specialisation) : name{ name }, specialisation{ specialisation } {}

string Doctor::getName()
{
	return this->name;
}

string Doctor::getSpecialisation()
{
	return this->specialisation;
}


istream& operator>>(istream& is, Doctor& d)
{
	string line;
	getline(is, line);

	vector<string> tokens;
	stringstream ss(line);
	string token;
	while (getline(ss, token, ','))
		tokens.push_back(token);

	if (tokens.size() != 2)
		return is;

	d.name = tokens[0];
	d.specialisation = tokens[1];

	return is;
}
