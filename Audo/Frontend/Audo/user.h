#ifndef USER_H
#define USER_H

#endif // USER_H

#include <unordered_map>
#include <string>
#include <QString>
//info for currently logged in user, such as name, status, school, classes;
namespace User{
    static std::unordered_map<std::string, std::string> joinedClasses;
    static std::string fname;
    static std::string lname;
    static std::string school;
    static std::string status;
    static QString username;
};
