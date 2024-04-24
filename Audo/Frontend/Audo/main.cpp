#include "MainPage.h"
#include "SignIn.h"
#include "SignUp.h"
#include "StudentSignUp.h"
#include "TeacherSignUp.h"
#include "teachergrades.h"
#include "audo.h"
#include "studentnotes.h"
#include "studentgrades.h"
#include <QtLogging>
#include <QApplication>
#include "handler.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QAction switchWindows;

    MainPage mainPage(&switchWindows);

    SignIn signIn(&switchWindows);

    SignUp signUp(&switchWindows);
    StudentSignUp studentSignUp(&switchWindows);
    TeacherSignUp teacherSignUp(&switchWindows);
    TeacherGrades teacherGrades(&switchWindows);

    Audo teacherNotes(&switchWindows);

    StudentNotes studentNotes(&switchWindows);
    StudentGrades studentGrades(&switchWindows);

    QWidget* currentWindow = &mainPage;

    Handler handler;

    currentWindow->show();
    QObject::connect(&switchWindows, &QAction::triggered, [&]() {

        std::string windowToSwitch = switchWindows.text().toStdString();
        currentWindow->hide();

        if (windowToSwitch == "SignIn")
            currentWindow = &signIn;

        else if (windowToSwitch == "Landing")
            currentWindow = &mainPage;

        else if (windowToSwitch == "SignUp")
            currentWindow = &signUp;

        else if (windowToSwitch == "StudentSignUp")
            currentWindow = &studentSignUp;

        else if (windowToSwitch == "StudentNotes"){
            studentNotes.FetchUI();
            currentWindow = &studentNotes;
        }

        else if (windowToSwitch == "StudentGrades")
            currentWindow = &studentGrades;

        else if (windowToSwitch == "TeacherSignUp")
            currentWindow = &teacherSignUp;

        else if (windowToSwitch == "TeacherNotes")
            currentWindow = &teacherNotes;

        else if (windowToSwitch == "TeacherGrades")
            currentWindow = &teacherGrades;

        currentWindow->show();

    });
    return app.exec();
}
