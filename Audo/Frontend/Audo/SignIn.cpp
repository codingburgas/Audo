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



void SignIn::on_Pedalite_azsumgei() {
    // QString str = "http://localhost:45098/api/get/user";
    // const QUrl url = QUrl(str);
    // QNetworkRequest user;

    // user.setUrl(url);
    // QString authToken = *net::authToken;
    // QString header = "Bearer " + authToken;
    // user.setRawHeader("Authorization", header.toUtf8());

    // QNetworkReply* reply = net::manager->get(user);
    // QObject::connect(reply, &QNetworkReply::finished, this, &SignIn::on_Pedalite_azsumgeiFinished);
}

void SignIn::on_Pedalite_azsumgeiFinished() {
    // QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    // if (reply->error() == QNetworkReply::NoError) {
    //     QString strReply = (QString)reply->readAll();
    //     QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    //     QJsonObject jsonObj = jsonResponse.object();
    //     this->userInfo.append(jsonObj["fname"].toString().toStdString());
    //     this->userInfo.append(jsonObj["lname"].toString().toStdString());
    //     emit SignIn::userInfoReady(this->userInfo);
    // }
    // reply->deleteLater();
}

void SignIn::on_Continue_clicked(){

    audoUtil::Body body =
    {
        { "email", ui->Email->toText() },
        { "password", ui->Password->toText() }
    };

    audoUtil::Response response = audoUtil::post("/api/login", body);

    if (response.status_code == audoUtil::OK) {

        audoCfg::authToken = response.data["token"].toStr();

        audoUtil::Response user = audoUtil::get("/api/get/user");

        audoCfg::firstName = user.data["fname"].toStr();
        audoCfg::lastName = user.data["lname"].toStr();
        audoCfg::email = user.data["email"].toStr();
        audoCfg::status = user.data["status"].toStr();
        audoCfg::school = user.data["school"].toStr();

        switchAction->setText("Audo");
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


