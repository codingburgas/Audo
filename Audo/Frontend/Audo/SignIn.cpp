#include "SignIn.h"
#include "ui_signin.h"
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
    QString str = "http://localhost:45098/api/login";
    const QUrl loginUrl = QUrl(str);

    QNetworkRequest loginRequest;
    loginRequest.setUrl(loginUrl);
    loginRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject body;
    body.insert("email", ui->Email->toPlainText());
    body.insert("password", ui->Password->toPlainText());

    qDebug() << loginRequest.url().toString();

    QNetworkReply* reply = net::manager->post(loginRequest, QJsonDocument(body).toJson());

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QString strReply = (QString)reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
            QJsonObject jsonObj = jsonResponse.object();

            net::authToken = jsonObj["token"].toString();

        }
        else {
            QString strReply = (QString)reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
            QJsonObject jsonObj = jsonResponse.object();

            ui->Warning->setText(jsonObj["data"].toString());

        }
        reply->deleteLater();
    });
}

