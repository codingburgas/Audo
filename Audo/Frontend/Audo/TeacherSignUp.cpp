#include "TeacherSignUp.h"
#include "ui_TeacherSignUp.h"

#include "netConfig.h"

TeacherSignUp::TeacherSignUp(QAction* switcher, QWidget *parent)
    : QWidget(parent), ui(new Ui::TeacherSignUp), switchAction(switcher)
{
    ui->setupUi(this);
}

TeacherSignUp::~TeacherSignUp()
{
    delete ui;
}

void TeacherSignUp::on_SignInButton_clicked()
{
    switchAction->setText("SignIn");
    switchAction->trigger();
}


void TeacherSignUp::on_Continue_clicked()
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
    body.insert("status", "teacher");
    body.insert("school", ui->ClassCode->toPlainText());

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

