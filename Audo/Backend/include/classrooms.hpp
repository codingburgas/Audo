#pragma once
#include "return_type.hpp"
#include "database.hpp"
#include "secret.hpp"
#include "hash.hpp"
#undef min
#undef max
#include "jwt-cpp/traits/nlohmann-json/traits.h"

struct Classroom {
	int id;
	std::string code;
	std::string name;
	int ownerId;
};

namespace soci
{
    template<>
    struct type_conversion<Classroom>
    {
        typedef values base_type;

        static void from_base(values const& v, indicator /* ind */, Classroom& c)
        {
            c.id = v.get<int>("id", 0);
            c.name = v.get<std::string>("name");
            c.ownerId = v.get<int>("owner_id", 0);
            c.code = v.get<std::string>("unique_code");
        }

        static void to_base(const Classroom& c, values& v, indicator& ind)
        {
            v.set("id", c.id);
            v.set("name", c.name);
            v.set("owner_id", c.ownerId);
            v.set("unique_code", c.code);
            ind = i_ok;
        }
    };
}

returnType CreateClassroom(CppHttp::Net::Request& req);
returnType GetClassroom(CppHttp::Net::Request& req);
returnType DeleteClassroom(CppHttp::Net::Request& req);
returnType GetClassrooms(CppHttp::Net::Request& req);
returnType JoinClassroom(CppHttp::Net::Request& req);