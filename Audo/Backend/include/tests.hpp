#pragma once
#include "return_type.hpp"
#include "database.hpp"
#include "secret.hpp"
#include "qa.hpp"
#include "hash.hpp"
#include <fstream>
#include <cpr/cpr.h>
#undef min
#undef max
#include "jwt-cpp/traits/nlohmann-json/traits.h"

struct Test {
    int id;
    int user_id;
    double score;
	std::string subject;
};

struct UserScore {
	int user_id;
	double score;
};

namespace soci {
	template<>
	struct type_conversion<Test>
	{
		typedef values base_type;

		static void from_base(values const& v, indicator /* ind */, Test& r)
		{
			r.id = v.get<int>("id");
			r.user_id = v.get<int>("user_id");
			r.score = v.get<double>("score");
			r.subject = v.get<std::string>("subject");
		}

		static void to_base(const Test& r, values& v, indicator& ind)
		{
			v.set("id", r.id);
			v.set("user_id", r.user_id);
			v.set("score", r.score);
			v.set("subject", r.subject);
			ind = i_ok;
		}
	};

	template<>
	struct type_conversion<UserScore>
	{
		typedef values base_type;

		static void from_base(values const& v, indicator /* ind */, UserScore& r)
		{
			r.user_id = v.get<int>("user_id");
			r.score = v.get<double>("total_score");
		}

		static void to_base(const UserScore& r, values& v, indicator& ind)
		{
			v.set("user_id", r.user_id);
			v.set("total_score", r.score);
			ind = i_ok;
		}
	};
}

returnType SubmitTest(CppHttp::Net::Request& req);
returnType GetTests(CppHttp::Net::Request& req);
returnType GetRankings(CppHttp::Net::Request& req);