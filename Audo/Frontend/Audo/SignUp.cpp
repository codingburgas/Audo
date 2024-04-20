#include "SignUp.h"
#include "ui_SignUp.h"

SignUp::SignUp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

QPushButton* SignUp::GetSignInButton()
{
    return ui->SignInButton;
}



