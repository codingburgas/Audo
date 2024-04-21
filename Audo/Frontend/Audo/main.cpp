#include "MainPage.h"
#include "SignIn.h"
#include "SignUp.h"
#include "StudentSignUp.h"
#include "TeacherSignUp.h"
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
    Audo heroPage(&switchWindows);
    QWidget* currentWindow = &mainPage;
    Handler handler;
    mainPage.show();
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
            currentWindow = &studentSignUp;

        }
        if (windowToSwitch == "Audo"){
            QObject::connect(&signIn, &SignIn::userInfoReady, [&](QVector<std::string> userInfo) {
                for (const std::string& info : userInfo) {
                    qDebug() << info;
                }
                heroPage.setUserName(userInfo);

            });

            signIn.on_Pedalite_azsumgei();
            currentWindow = &heroPage;
        }
        currentWindow->show();

    });
    return app.exec();
}
