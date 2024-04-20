#include "SignIn.h"
#include "ui_SignIn.h"
#include "netConfig.h"

#include <iostream>
#include <QtLogging>

SignIn::SignIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
}

QPushButton* SignIn::GetSignUpButton()
{
    return ui->SignUpButton;
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_Continue_clicked()
{
    QUrl loginUrl;
    loginUrl.setUrl("127.0.0.1:45098/api/login");

    QNetworkRequest loginRequest;
    loginRequest.setUrl(loginUrl);

    QJsonObject body;

    body.insert("email", ui->Email->toPlainText());
    body.insert("password", ui->Password->toPlainText());

    qInfo("%s", loginUrl.toString().toStdString().c_str());

    QNetworkReply* reply = net::manager->post(loginRequest, QJsonDocument(body).toJson());
    while (!reply->isFinished())
    {
        // wait for the request to complete
    }
    QByteArray response_data = reply->readAll();
    reply->deleteLater();

    std::cout << response_data.toStdString() << std::endl;
}

