#include "StudentSignUp.h"
#include "ui_StudentSignUp.h"
#include "netConfig.h"

StudentSignUp::StudentSignUp(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::StudentSignUp), switchAction(switcher)
{
    ui->setupUi(this);
}

StudentSignUp::~StudentSignUp()
{
    delete ui;
}

void StudentSignUp::on_SignInButton_clicked()
{
    switchAction->setText("SignIn");
    switchAction->trigger();
}


void StudentSignUp::on_Continue_clicked()
{
    QString str = "http://localhost:45098/api/register";
    const QUrl loginUrl = QUrl(str);

    QNetworkRequest loginRequest;
    loginRequest.setUrl(loginUrl);
    loginRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject body;
    body.insert("first_name", ui->FName->toPlainText());
    body.insert("last_name", ui->LName->toPlainText());
    body.insert("email", ui->Email->toPlainText());
    body.insert("password", ui->Password->toPlainText());
    body.insert("status", "student");
    body.insert("school", "VSCPI");

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

