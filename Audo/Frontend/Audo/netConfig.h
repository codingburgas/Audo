#ifndef NETCONFIG_H
#define NETCONFIG_H

#include <QtNetwork/QtNetwork>

namespace net
{
    static QString* authToken;

    static QString* baseUrl = new QString("127.0.0.1:45098");

    static QNetworkAccessManager* manager = new QNetworkAccessManager;
}

#endif // NETCONFIG_H
