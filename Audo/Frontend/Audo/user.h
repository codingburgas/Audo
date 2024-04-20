#ifndef USER_H
#define USER_H

#endif // USER_H

#include <unordered_map>
#include <string>

//info for currently logged in user, such as name, status, school, classes;
class User {
public:
    std::unordered_map<std::string, std::string> joinedClasses;
    std::string fname;
    std::string lname;
    std::string school;
    std::string status;
};
