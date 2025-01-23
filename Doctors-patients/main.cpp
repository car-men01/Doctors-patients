#include "Doctorspatients.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    Repository repo{ "patients.txt", "doctors.txt" };
    Service service{ repo };

    vector<Doctor> doctors = service.getDoctors();

    for (Doctor d : doctors)
    {
        Doctorspatients* w = new Doctorspatients{ d, service };
        w->setWindowTitle(QString::fromStdString(d.getName()));
        repo.addObserver(w);
        w->show();
    }

    return a.exec();
}
