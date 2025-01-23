#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Doctorspatients.h"
#include "Service.h"

class Doctorspatients : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    Doctorspatients(Doctor doctor, Service& service, QWidget* parent = nullptr);
    ~Doctorspatients();

private:
    Ui::DoctorspatientsClass ui;
    Service& service;
    Doctor doctor;

    void update() override;
    void connectSignalsAndSlots();
    void populatePatientsList();
    void addPatient();
    void updatePatient();
};
