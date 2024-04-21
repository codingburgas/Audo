#include "requests.h"
#include "ui_requests.h"
#include "netConfig.h"
#include <QtLogging>



requests::requests(QAction* switcher, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::requests) , switchAction(switcher)
{
    ui->setupUi(this);

}

requests::~requests()
{
    delete ui;
    QString str = "http://localhost:45098/api/login";
    const QUrl loginUrl = QUrl(str);

    QNetworkRequest loginRequest;
    loginRequest.setUrl(loginUrl);
    loginRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray headerData = QByteArray::fromStdString("Bearer " + net::authToken->toStdString());

    loginRequest.setRawHeader("Authorization", headerData);

    QJsonObject body;



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

