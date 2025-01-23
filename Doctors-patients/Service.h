#pragma once
#include "Repository.h"

class Service
{
private:
	Repository& repo;
public:
	Service(Repository& repo);
	~Service();

	void addPatient(string name, string diagnosis, string specialisation, string currentDoctor, string admissionDate);
	void updatePatient(string patientName, string newDiagnosis, string newSpecialisation);

	Patient getPatientByName(string name);
	vector<Doctor> getDoctors();
	vector<Patient> getPatients();

	vector<Patient> getPatientsBySpecialisationUndiagnosed(Doctor d);
	vector<Patient> getPatientsWithCurrentDoctor(Doctor d);
	vector<Patient> getPatientsCurrentDoctorUndiagnosed(Doctor d);
	int checkAdmissionDate(string admissionDate);

};

