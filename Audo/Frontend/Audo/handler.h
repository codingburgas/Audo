#ifndef HANDLER_H
#define HANDLER_H
#endif // HANDLER_H
#include "user.h"
#include <QObject>
#include <QVector>

class Handler : public QObject {
    Q_OBJECT

public slots:
    void handleUserInfoReady(QVector<std::string> userInfo) {
        User::fname = userInfo.at(0);
        User::lname = userInfo.at(1);
    }
};
