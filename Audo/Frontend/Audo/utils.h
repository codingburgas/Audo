#ifndef NETCONFIG_H
#define NETCONFIG_H

#include <cpr/cpr.h>
#include <QJsonObject>
#include <QJsonDocument>

#define toText() toPlainText().toStdString()
#define toStr() toString().toStdString()

namespace audoCfg{

    static std::string authToken;

    static std::string firstName;
    static std::string lastName;
    static std::string email;
    static std::string status;
    static std::string school;

    static std::string baseUrl = "20.234.64.232:45098";
}

namespace audoUtil{

    using Body = std::vector<std::array<std::string, 2>>;

    struct Response
    {
        long status_code{};
        QJsonObject data{};
    };

    enum StatusCode {
        OK = 200,
        CREATED = 201,
        BAD_REQUEST = 400,
        NOT_FOUND = 404,
        INTERNAL_ERROR = 500,
        NOT_IMPLEMENTED = 501,
        NOT_AUTHORIZED = 401,
        REDIRECT = 302,
        ALREADY_EXISTS = 409
    };


    [[maybe_unused]]
    static Response post(const std::string&& urlAdd, Body body, const bool&& needAuth = false){

        QJsonObject jsonObj;
        for(auto& param : body)
        {
            jsonObj.insert(QString::fromStdString(std::string(param[0])), QString::fromStdString(std::string(param[1])));
        }

        QJsonDocument jsonDoc;
        jsonDoc.setObject(jsonObj);

        cpr::Response r = cpr::Post(cpr::Url{audoCfg::baseUrl + urlAdd},
                                    cpr::Body{jsonDoc.toJson()});

        return Response({r.status_code, QJsonDocument::fromJson(QString::fromStdString(r.text).toUtf8()).object()});

    }

    [[maybe_unused]] [[nodiscard]]
    static Response get(const std::string&& urlAdd){

        cpr::Response r = cpr::Get(cpr::Url{audoCfg::baseUrl + urlAdd},
                                    cpr::Header{{"Authorization", "Bearer " + audoCfg::authToken}});

        return Response({r.status_code, QJsonDocument::fromJson(QString::fromStdString(r.text).toUtf8()).object()});

    }
}

#endif // NETCONFIG_H
