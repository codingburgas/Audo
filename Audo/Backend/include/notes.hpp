#pragma once
#include "return_type.hpp"
#include "database.hpp"
#include "secret.hpp"
#include "hash.hpp"
#include <chrono>
#undef min
#undef max
#include "jwt-cpp/traits/nlohmann-json/traits.h"

struct Note {
    int id;
    std::string subject;
    std::string topic;
    int room_id;
    std::string content;
};

namespace soci
{
    template<>
    struct type_conversion<Note>
    {
        typedef values base_type;

        static void from_base(values const& v, indicator /* ind */, Note& n)
        {
            n.id = v.get<int>("id");
            n.subject = v.get<std::string>("subject");
            n.topic = v.get<std::string>("topic");
            n.room_id = v.get<int>("room_id");
            n.content = v.get<std::string>("content");
        }

        static void to_base(const Note& n, values& v, indicator& ind)
        {
            v.set("id", n.id);
            v.set("subject", n.subject);
            v.set("topic", n.topic);
            v.set("room_id", n.room_id);
            v.set("content", n.content);
            ind = i_ok;
        }
    };
}

returnType AddNote(CppHttp::Net::Request& req);