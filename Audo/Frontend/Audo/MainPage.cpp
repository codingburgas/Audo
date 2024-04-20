#include "MainPage.h"
#include "ui_MainPage.h"


#include <QFontDatabase>

MainPage::MainPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
}

MainPage::~MainPage()
{
    delete ui;
}

QPushButton* MainPage::GetSignInButton()
{
    return ui->SignIn;
}

QPushButton* MainPage::GetSignUpButton()
{
    return ui->SignUp;
}
