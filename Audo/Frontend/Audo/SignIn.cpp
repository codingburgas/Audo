#include "SignIn.h"
#include "ui_SignIn.h"
#include "netConfig.h"

#include <QtLogging>

SignIn::SignIn(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::SignIn), switchAction(switcher)
{
    ui->setupUi(this);
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

            delete net::authToken;
            net::authToken = new QString(jsonObj["token"].toString());

            switchAction->setText(QString("Landing"));
            switchAction->trigger();
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


void SignIn::on_SignUpButton_clicked()
{
    switchAction->setText("SignUp");
    switchAction->trigger();
}

