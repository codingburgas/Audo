#ifndef NETCONFIG_H
#define NETCONFIG_H

#include <QtNetwork/QtNetwork>

#include <string>

namespace net
{
    QString authToken;

    QString baseUrl{"127.0.0.1:45098"};

    QNetworkAccessManager* manager = new QNetworkAccessManager;
}

#endif // NETCONFIG_H
