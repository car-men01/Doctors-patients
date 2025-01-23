#pragma once
#include "Patient.h"
#include "Doctor.h"
#include "Observer.h"

class Repository : public Subject
{
private:
	vector<Patient> patients;
	vector<Doctor> doctors;
	string filePatients, fileDoctors;

public:
	Repository(string filePatients, string fileDoctors);
	~Repository();

	void addPatient(Patient p);
	void addDoctor(Doctor d);
	void updatePatient(Patient p);

	
	vector<Patient> getPatientsRepo();
	vector<Doctor> getDoctorsRepo();

	void readFilePatients();
	void readFileDoctors();
	void writeFilePatients();
};

