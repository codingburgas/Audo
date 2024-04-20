#include "MainPage.h"
#include "SignIn.h"
#include "SignUp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainPage mainPage;
    SignIn signIn;
    SignUp signUp;

    QObject::connect(mainPage.GetSignInButton(), &QPushButton::clicked, [&]() {
        mainPage.hide();
        signIn.show();
    });

    QObject::connect(mainPage.GetSignUpButton(), &QPushButton::clicked, [&]() {
        mainPage.hide();
        signUp.show();
    });

    QObject::connect(signIn.GetSignUpButton(), &QPushButton::clicked, [&]() {
       signIn.hide();
       signUp.show();
    });

    QObject::connect(signUp.GetSignInButton(), &QPushButton::clicked, [&]() {
        signUp.hide();
        signIn.show();
    });
    mainPage.show();
    return app.exec();
}
