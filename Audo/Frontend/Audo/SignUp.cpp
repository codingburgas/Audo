#include "SignUp.h"
#include "ui_SignUp.h"

SignUp::SignUp(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::SignUp), switchAction(switcher)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}



void SignUp::on_pushButton_clicked()
{
    switchAction->setText("StudentSignUp");
    switchAction->trigger();
}


void SignUp::on_SignInButton_clicked()
{
    switchAction->setText("SignIn");
    switchAction->trigger();
}


void SignUp::on_Teacher_clicked()
{
    switchAction->setText("TeacherSignUp");
    switchAction->trigger();
}

