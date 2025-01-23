#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Patient
{
private:
	string name, diagnosis, specialisation, currentDoctor, admissionDate;
public:
	Patient();
	Patient(string name, string diagnosis, string specialisation, string currentDoctor, string admissionDate);
	string getName();
	string getDiagnosis();
	string getSpecialisation();
	string getCurrentDoctor();
	string getAdmissionDate();

	friend istream& operator>>(istream& is, Patient& p);
	friend ostream& operator<<(ostream& os, Patient& p);
};

