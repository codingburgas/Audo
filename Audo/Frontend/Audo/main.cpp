#include "MainPage.h"
#include "SignIn.h"
#include "SignUp.h"
#include "StudentSignUp.h"
#include "TeacherSignUp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QAction switchWindows;

    MainPage mainPage(&switchWindows);

    SignIn signIn(&switchWindows);

    SignUp signUp(&switchWindows);
    StudentSignUp studentSignUp(&switchWindows);
    TeacherSignUp teacherSignUp(&switchWindows);

    QWidget* currentWindow = &mainPage;

    QObject::connect(&switchWindows, &QAction::triggered, [&]() {

        std::string windowToSwitch = switchWindows.text().toStdString();
        currentWindow->hide();

        if (windowToSwitch == "SignIn")
            currentWindow = &signIn;
        if (windowToSwitch == "Landing")
            currentWindow = &mainPage;
        if (windowToSwitch == "SignUp")
            currentWindow = &signUp;
        if (windowToSwitch == "StudentSignUp")
            currentWindow = &studentSignUp;
        if (windowToSwitch == "TeacherSignUp")
            currentWindow = &studentSignUp;

        currentWindow->show();

    });

    mainPage.show();
    return app.exec();
}
