#ifndef CLASS_H
#define CLASS_H

#endif // CLASS_H
#include "user.h"

namespace Audo{
class Class{
public:
    std::string* roomId = nullptr;
    std::string* roomName = nullptr;
    std::unordered_map<std::string, User>* joinedUsers = nullptr;
};
}
