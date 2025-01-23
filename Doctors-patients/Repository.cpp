#include "Repository.h"

Repository::Repository(string filePatients, string fileDoctors) 
{
	this->filePatients = filePatients;
	this->fileDoctors = fileDoctors;
	this->readFileDoctors();
	this->readFilePatients();
}

Repository::~Repository() {}

void Repository::addPatient(Patient p)
{
	this->patients.push_back(p);
	this->notify();
	this->writeFilePatients();
}

void Repository::addDoctor(Doctor d)
{
	this->doctors.push_back(d);
}

void Repository::updatePatient(Patient p)
{
	for (Patient& patient : this->patients)
	{
		if (patient.getName() == p.getName())
		{
			patient = p;
			break;
		}
	}
	this->notify();
	this->writeFilePatients();
}

vector<Patient> Repository::getPatientsRepo()
{
	return this->patients;
}

vector<Doctor> Repository::getDoctorsRepo()
{
	return this->doctors;
}

void Repository::readFilePatients()
{
	ifstream file(this->filePatients);
	Patient p;
	while (file >> p)
		this->addPatient(p);
	file.close();
}

void Repository::readFileDoctors()
{
	ifstream file(this->fileDoctors);
	Doctor d;
	while (file >> d)
		this->addDoctor(d);
	file.close();
}

void Repository::writeFilePatients()
{
	ofstream file(this->filePatients);
	for (Patient p : this->patients)
		file << p;
	file.close();
}