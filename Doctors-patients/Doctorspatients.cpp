#include "Doctorspatients.h"
#include <qmessagebox.h>

Doctorspatients::Doctorspatients(Doctor doctor, Service& service, QWidget* parent)
	: QMainWindow(parent), service{ service }, doctor{ doctor }
{
	ui.setupUi(this);
	//this->populatePatientsList();
	this->update();
	this->connectSignalsAndSlots();
}

Doctorspatients::~Doctorspatients()
{
}

void Doctorspatients::update()
{
	this->populatePatientsList();
}

void Doctorspatients::connectSignalsAndSlots()
{
	QObject::connect(this->ui.currentPatientsCheckBox, &QCheckBox::stateChanged, this, &Doctorspatients::populatePatientsList);
	QObject::connect(this->ui.addPushButton, &QPushButton::clicked, this, &Doctorspatients::addPatient);
	QObject::connect(this->ui.updatePushButton, &QPushButton::clicked, this, &Doctorspatients::updatePatient);
}

void Doctorspatients::populatePatientsList()
{
	this->ui.patientsListWidget->clear();
	vector<Patient> patients = this->service.getPatientsBySpecialisationUndiagnosed(this->doctor);

	if (this->ui.currentPatientsCheckBox->isChecked()) {
		patients = this->service.getPatientsWithCurrentDoctor(this->doctor);
	}
	else {
		patients = this->service.getPatientsBySpecialisationUndiagnosed(this->doctor);
	}

	for (Patient p : patients) {
		if (p.getDiagnosis() == "undiagnosed") {
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(p.getName() + " - " + p.getDiagnosis() + " - " + p.getAdmissionDate()));
			this->ui.patientsListWidget->addItem(item);
		}
		else {
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(p.getName() + " - " + p.getDiagnosis() + " - " + p.getSpecialisation() + " - " + p.getCurrentDoctor() + " - " + p.getAdmissionDate()));
			this->ui.patientsListWidget->addItem(item);
			if (p.getCurrentDoctor() == this->doctor.getName()) {
				QBrush brush{ Qt::green };
				item->setBackground(brush);
			}
		}
	}
}

void Doctorspatients::addPatient()
{
	string name = this->ui.nameLineEdit->text().toStdString();
	string diagnosis = this->ui.diagnosisLineEdit->text().toStdString();
	string specialisation = this->ui.specialisationLineEdit->text().toStdString();
	string currentDoctor = this->ui.currentDoctorLineEdit->text().toStdString();
	string admissionDate = this->ui.admissionDateLineEdit->text().toStdString();

	if (name == "" || this->service.checkAdmissionDate(admissionDate) == 0) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Name cannot be empty and admission date cannot be in the past!");
		return;
	}

	this->service.addPatient(name, diagnosis, specialisation, currentDoctor, admissionDate);
	this->populatePatientsList();
}

void Doctorspatients::updatePatient()
{
	string patientName = this->ui.updateNameLineEdit->text().toStdString();
	string diagnosis = this->ui.updateDiagnosisLineEdit->text().toStdString();
	string specialisation = this->ui.updateSpecialisationLineEdit->text().toStdString();

	vector<Patient> patients = this->service.getPatientsCurrentDoctorUndiagnosed(this->doctor);
	int found = 0;
	for (Patient p : patients) {
		if (p.getName() == patientName) {
			found = 1;
		}
	}

	if (found == 0) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Cannot update this patient!");
		return;
	}

	if (diagnosis == "undiagnosed") {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Cannot update the patient to undiagnosed!");
		return;
	}

	this->service.updatePatient(patientName, diagnosis, specialisation);
	this->populatePatientsList();
}

