#include "Patient.h"

Patient::Patient() : name{ "" }, diagnosis{ "" }, specialisation{ "" }, currentDoctor{ "" }, admissionDate{ "" } {}

Patient::Patient(string name, string diagnosis, string specialisation, string currentDoctor, string admissionDate) : name{ name }, diagnosis{ diagnosis }, specialisation{ specialisation }, currentDoctor{ currentDoctor }, admissionDate{ admissionDate } {}

string Patient::getName()
{
	return this->name;
}

string Patient::getDiagnosis()
{
	return this->diagnosis;
}

string Patient::getSpecialisation()
{
	return this->specialisation;
}

string Patient::getCurrentDoctor()
{
	return this->currentDoctor;
}

string Patient::getAdmissionDate()
{
	return this->admissionDate;
}

istream& operator>>(istream& is, Patient& p)
{
	string line;
	getline(is, line);

	vector<string> tokens;
	stringstream ss(line);
	string token;
	while (getline(ss, token, ','))
		tokens.push_back(token);

	if (tokens.size() != 5)
		return is;

	p.name = tokens[0];
	p.diagnosis = tokens[1];
	p.specialisation = tokens[2];
	p.currentDoctor = tokens[3];
	p.admissionDate = tokens[4];
	
	return is;
}

ostream& operator<<(ostream& os, Patient& p)
{
	os << p.name << "," << p.diagnosis << "," << p.specialisation << "," << p.currentDoctor << "," << p.admissionDate << "\n";
	return os;
}