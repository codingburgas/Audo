#pragma once
#include "return_type.hpp"
#include "database.hpp"
#include "secret.hpp"
#include "hash.hpp"
#include <fstream>
#include <cpr/cpr.h>
#undef min
#undef max
#include "jwt-cpp/traits/nlohmann-json/traits.h"

struct Request {
    int room_id;
    int user_id;
    int id;
};

namespace soci {
    template<>
    struct type_conversion<Request>
    {
        typedef values base_type;

        static void from_base(values const& v, indicator /* ind */, Request& r)
        {
            r.id = v.get<int>("id");
            r.room_id = v.get<int>("room_id");
            r.user_id = v.get<int>("user_id");
        }

        static void to_base(const Request& r, values& v, indicator& ind)
        {
            v.set("id", r.id);
            v.set("room_id", r.room_id);
            v.set("user_id", r.user_id);
            ind = i_ok;
        }
    };
}

returnType AddRequest(CppHttp::Net::Request& req);
returnType GetRequests(CppHttp::Net::Request& req);
returnType DeleteRequest(CppHttp::Net::Request& req);
returnType AcceptRequest(CppHttp::Net::Request& req);
returnType DeclineRequest(CppHttp::Net::Request& req);