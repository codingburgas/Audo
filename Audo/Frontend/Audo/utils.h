#ifndef NETCONFIG_H
#define NETCONFIG_H

#include <cpr/cpr.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#define toText() toPlainText().toStdString()
#define toStr() toString().toStdString()

namespace audoCfg{

    inline std::string authToken;

    inline QString firstName;
    inline QString lastName;
    inline QString email;
    inline QString status;
    inline QString school;

    inline int currentClassId;
    inline int currentNoteId;

    inline std::string baseUrl = "localhost:45098";
}

namespace audoUtil{

    using Body = std::vector<std::pair<std::string, std::variant<QString, int>>>;

    struct Response
    {
        long status_code{};
        QJsonObject data{};
        QJsonArray* array = nullptr;
    };

    enum StatusCode : long {
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

    enum class ResponseType : bool {
        OBJECT = 0,
        ARRAY
    };


    [[maybe_unused]]
    static Response post(const std::string&& urlAdd, Body body, const bool&& needAuth = false, const ResponseType&& type = ResponseType::OBJECT){

        QJsonObject jsonObj;
        for(auto& param : body)
        {
            try
            {
                std::ignore = std::get<int>(std::get<1>(param));
                jsonObj.insert(QString::fromStdString(std::get<0>(param)), std::get<int>(std::get<1>(param)));
            }
            catch (...)
            {
                jsonObj.insert(QString::fromStdString(std::get<0>(param)), std::get<QString>(std::get<1>(param)));
            }

        }

        QJsonDocument jsonDoc;
        jsonDoc.setObject(jsonObj);

        cpr::Response r;
        if(needAuth)
            r = cpr::Post(cpr::Url{audoCfg::baseUrl + urlAdd},
                                        cpr::Header{{"Authorization", "Bearer " + audoCfg::authToken}},
                                        cpr::Body{jsonDoc.toJson()});
        else
            r = cpr::Post(cpr::Url{audoCfg::baseUrl + urlAdd},
                                        cpr::Body{jsonDoc.toJson()});


        Response response({r.status_code});

        if(type == ResponseType::OBJECT)
        {
            response.data = QJsonDocument::fromJson(QString::fromStdString(r.text).toUtf8()).object();
        }
        else
        {
            response.array = new QJsonArray(QJsonDocument::fromJson(QString::fromStdString(r.text).toUtf8()).array());
        }

        return response;

    }

    [[maybe_unused]]
    static void put(const std::string&& urlAdd, Body body, const bool&& needAuth = false){

        QJsonObject jsonObj;
        for(auto& param : body)
        {
            try
            {
                std::ignore = std::get<int>(std::get<1>(param));
                jsonObj.insert(QString::fromStdString(std::get<0>(param)), std::get<int>(std::get<1>(param)));
            }
            catch (...)
            {
                jsonObj.insert(QString::fromStdString(std::get<0>(param)), std::get<QString>(std::get<1>(param)));
            }

        }

        QJsonDocument jsonDoc;
        jsonDoc.setObject(jsonObj);

        cpr::Response r;
        if(needAuth)
            r = cpr::Put(cpr::Url{audoCfg::baseUrl + urlAdd},
                          cpr::Header{{"Authorization", "Bearer " + audoCfg::authToken}},
                          cpr::Body{jsonDoc.toJson()});
        else
            r = cpr::Put(cpr::Url{audoCfg::baseUrl + urlAdd},
                          cpr::Body{jsonDoc.toJson()});
    }

    [[maybe_unused]]
    static void del(const std::string&& urlAdd, Body body, const bool&& needAuth = false){

        QJsonObject jsonObj;
        for(auto& param : body)
        {
            try
            {
                std::ignore = std::get<int>(std::get<1>(param));
                jsonObj.insert(QString::fromStdString(std::get<0>(param)), std::get<int>(std::get<1>(param)));
            }
            catch (...)
            {
                jsonObj.insert(QString::fromStdString(std::get<0>(param)), std::get<QString>(std::get<1>(param)));
            }

        }

        QJsonDocument jsonDoc;
        jsonDoc.setObject(jsonObj);

        cpr::Response r;
        if(needAuth)
            r = cpr::Delete(cpr::Url{audoCfg::baseUrl + urlAdd},
                          cpr::Header{{"Authorization", "Bearer " + audoCfg::authToken}},
                          cpr::Body{jsonDoc.toJson()});
        else
            r = cpr::Delete(cpr::Url{audoCfg::baseUrl + urlAdd},
                          cpr::Body{jsonDoc.toJson()});
    }

    [[maybe_unused]] [[nodiscard]]
    static Response get(const std::string&& urlAdd, const ResponseType&& type = ResponseType::OBJECT){

        cpr::Response r = cpr::Get(cpr::Url{audoCfg::baseUrl + urlAdd},
                                    cpr::Header{{"Authorization", "Bearer " + audoCfg::authToken}});

        Response response({r.status_code});

        if(type == ResponseType::OBJECT)
        {
            response.data = QJsonDocument::fromJson(QString::fromStdString(r.text).toUtf8()).object();
        }
        else
        {
            response.array = new QJsonArray(QJsonDocument::fromJson(QString::fromStdString(r.text).toUtf8()).array());
        }

        return response;

    }
}

#endif // NETCONFIG_H
