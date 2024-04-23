#include "MainPage.h"
#include "SignIn.h"
#include "SignUp.h"
#include "StudentSignUp.h"
#include "TeacherSignUp.h"
#include "teachergrades.h"
#include "audo.h"
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
    Audo heroPage(&switchWindows);
    QWidget* currentWindow = &teacherGrades;
    Handler handler;
    currentWindow->show();
    teacherGrades.FetchUI();
    QObject::connect(&switchWindows, &QAction::triggered, [&]() {

        std::string windowToSwitch = switchWindows.text().toStdString();
        currentWindow->hide();

        if (windowToSwitch == "SignIn"){
            currentWindow = &signIn;
        }
        if (windowToSwitch == "Landing"){
            currentWindow = &mainPage;
        }
        if (windowToSwitch == "SignUp"){
            currentWindow = &signUp;

        }
        if (windowToSwitch == "StudentSignUp"){
            currentWindow = &studentSignUp;

        }
        if (windowToSwitch == "TeacherSignUp"){
            currentWindow = &teacherSignUp;

        }
        if (windowToSwitch == "Audo"){
            currentWindow = &heroPage;
        }
        if (windowToSwitch == "TeacherGrades"){
            currentWindow = &teacherGrades;
        }

        currentWindow->show();

    });
    return app.exec();
}
