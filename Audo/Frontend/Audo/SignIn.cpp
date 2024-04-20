#include "SignIn.h"
#include "ui_signin.h"

SignIn::SignIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
}

SignIn::~SignIn()
{
    delete ui;
}
