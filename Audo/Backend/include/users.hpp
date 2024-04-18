#pragma once
#include "return_type.hpp"
#include "database.hpp"
#include "secret.hpp"
#include "hash.hpp"
#undef min
#undef max
#include "jwt-cpp/traits/nlohmann-json/traits.h"

struct User {
	int id;
	std::string fname;
	std::string lname;
	std::string email;
	std::string password;
	std::string status;
	std::string school;
};

namespace soci
{
    template<>
    struct type_conversion<User>
    {
        typedef values base_type;

        static void from_base(values const& v, indicator /* ind */, User& u)
        {
            u.id = v.get<int>("id", 0);
            u.fname = v.get<std::string>("fname");
            u.lname = v.get<std::string>("lname");
            u.email = v.get<std::string>("email");
            u.password = v.get<std::string>("password");
            u.school = v.get<std::string>("school");
            u.status = v.get<std::string>("status");
        }

        static void to_base(const User& u, values& v, indicator& ind)
        {
            v.set("id", u.id);
            v.set("fname", u.fname);
            v.set("lname", u.lname);
            v.set("email", u.email);
            v.set("password", u.password);
            v.set("school", u.school);
            v.set("status", u.status);
            ind = i_ok;
        }
    };
}

returnType Register(CppHttp::Net::Request& req);

returnType Login(CppHttp::Net::Request& req);

returnType GetUser(CppHttp::Net::Request& req);

returnType DeleteUser(CppHttp::Net::Request& req);