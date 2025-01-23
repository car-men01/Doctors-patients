#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Doctor
{
private:
	string name, specialisation;
public:
	Doctor();
	Doctor(string name, string specialisation);
	string getName();
	string getSpecialisation();

	friend istream& operator>>(istream& is, Doctor& d);
};

