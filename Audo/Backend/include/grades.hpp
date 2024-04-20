#pragma once
#include "return_type.hpp"
#include "database.hpp"
#include "secret.hpp"
#include "hash.hpp"
#include <chrono>
#undef min
#undef max
#include "jwt-cpp/traits/nlohmann-json/traits.h"

struct Grade {
	int id;
	int student_id;
	std::string subject;
	std::tm date;
	std::string description;
	int score;
    int room_id;
};

namespace soci
{
    template<>
    struct type_conversion<Grade>
    {
        typedef values base_type;

        static void from_base(values const& v, indicator /* ind */, Grade& g)
        {
            g.id = v.get<int>("id", 0);
            g.student_id = v.get<int>("student_id", 0);
            g.subject = v.get<std::string>("subject");
            g.date = v.get<std::tm>("date_of_creation");
            g.description = v.get<std::string>("description");
			g.score = v.get<int>("score", 0);
            g.room_id = v.get<int>("room_id", 0);
        }

        static void to_base(const Grade& g, values& v, indicator& ind)
        {
            v.set("id", g.id);
            v.set("student_id", g.student_id);
            v.set("subject", g.subject);
            v.set("date_of_creation", g.date);
            v.set("description", g.description);
            v.set("score", g.score);
            v.set("room_id", g.room_id);
            ind = i_ok;
        }
    };
}

returnType GetGrades(CppHttp::Net::Request& req);
returnType GetGrade(CppHttp::Net::Request& req);
returnType AddGrade(CppHttp::Net::Request& req);
returnType UpdateGrade(CppHttp::Net::Request& req);
returnType DeleteGrade(CppHttp::Net::Request& req);
returnType GetStudentGrades(CppHttp::Net::Request& req);