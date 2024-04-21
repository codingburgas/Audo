#include "handler.h"

void Handler::handleUserInfoReady(QVector<std::string> userInfo){
    User::fname = userInfo.at(0);
    User::lname = userInfo.at(1);
}
