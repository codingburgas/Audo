#include "SignIn.h"
#include "ui_SignIn.h"
#include "utils.h"
#include <QtLogging>
#include "handler.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>

#include <cpr/cpr.h>

SignIn::SignIn(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::SignIn), switchAction(switcher)
{
    ui->setupUi(this);
}

SignIn::~SignIn(){
    delete ui;
}

void SignIn::on_Continue_clicked(){

    audoUtil::Body body =
    {
        { "email", ui->Email->toPlainText() },
        { "password", ui->Password->text() }
    };

    audoUtil::Response response = audoUtil::post("/api/login", body);

    if (response.status_code == audoUtil::OK) {

        audoCfg::authToken = response.data["token"].toStr();

        audoUtil::Response user = audoUtil::get("/api/get/user");

        audoCfg::firstName = user.data["fname"].toString();
        audoCfg::lastName = user.data["lname"].toString();
        audoCfg::email = user.data["email"].toString();

        if(user.data["status"].toString() == "teacher")
            audoCfg::status = "Teacher";
        if(user.data["status"].toString() == "student")
            audoCfg::status = "Student";

        audoCfg::school = user.data["school"].toString();

        if(audoCfg::status == "Teacher")
            switchAction->setText("TeacherNotes");

        else
            switchAction->setText("StudentNotes");
        switchAction->trigger();
    }
    else {

        ui->Warning->setText(response.data["data"].toString());
    }
}


void SignIn::on_SignUpButton_clicked(){
    switchAction->setText("SignUp");
    switchAction->trigger();
}


