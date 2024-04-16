#pragma once

#include <soci/soci.h>
#include <soci/postgresql/soci-postgresql.h>

using namespace soci;


class Database {
private:
	Database();

	static Database* databaseInstance;
	soci::session sql = soci::session(postgresql, "dbname=postgres user=audo password=Db123123123 host=audo-db.postgres.database.azure.com port=5432 sslmode=require");

public:
	Database(const Database&) = delete;

	static Database* GetInstance() {
		if (databaseInstance == nullptr) {
			databaseInstance = new Database();
		}
		return databaseInstance;
	}

	soci::session* GetSession() {
		return &sql;
	}
};