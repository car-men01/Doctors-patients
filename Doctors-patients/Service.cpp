#include "Service.h"
#include <algorithm>

Service::Service(Repository& repo) : repo{ repo } {}

Service::~Service() {}

void Service::addPatient(string name, string diagnosis, string specialisation, string currentDoctor, string admissionDate)
{
	Patient p{ name , diagnosis, specialisation, currentDoctor, admissionDate };
	this->repo.addPatient(p);
}

Patient Service::getPatientByName(string name)
{
	vector <Patient> allPatients = this->getPatients();
	for (Patient p : allPatients) {
		if (p.getName() == name)
			return p;
	}
}

void Service::updatePatient(string patientName, string newDiagnosis, string newSpecialisation)
{
	Patient patient = this->getPatientByName(patientName);
	Patient newPatient{ patientName, newDiagnosis, newSpecialisation, patient.getCurrentDoctor(), patient.getAdmissionDate() };
	this->repo.updatePatient(newPatient);
}

vector<Doctor> Service::getDoctors()
{
	return this->repo.getDoctorsRepo();
}

vector<Patient> Service::getPatients()
{
	return this->repo.getPatientsRepo();
}

vector<Patient> Service::getPatientsBySpecialisationUndiagnosed(Doctor d)
{
	vector<Patient> result;
	vector<Patient> allPatients = this->getPatients();

	for (Patient p : allPatients) {
		if (p.getSpecialisation() == d.getSpecialisation() || p.getDiagnosis() == "undiagnosed")
			result.push_back(p);
	}

	sort(result.begin(), result.end(), [](Patient p1, Patient p2) 
		{
			return p1.getAdmissionDate() < p2.getAdmissionDate(); 
		});

	return result;

}

vector<Patient> Service::getPatientsWithCurrentDoctor(Doctor d)
{
	vector<Patient> result;
	vector<Patient> allPatients = this->getPatients();

	for (Patient p : allPatients) {
		if (p.getCurrentDoctor() == d.getName())
			result.push_back(p);
	}

	return result;
}

vector<Patient> Service::getPatientsCurrentDoctorUndiagnosed(Doctor d)
{
	vector<Patient> result;
	vector<Patient> allPatients = this->getPatients();

	for (Patient p : allPatients) {
		if (p.getCurrentDoctor() == d.getName() || p.getDiagnosis() == "undiagnosed")
			result.push_back(p);
	}

	return result;
}

int Service::checkAdmissionDate(string admissionDate)
{
	string currentDate = "2024-06-21";
	if (admissionDate < currentDate)
		return 0;
	return 1;
}