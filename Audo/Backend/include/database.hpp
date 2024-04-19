#pragma once

#include <soci/soci.h>
#include <soci/postgresql/soci-postgresql.h>
#include <iostream>

using namespace soci;

class Database {
private:
	Database() {
		sql.open(postgresql, "dbname=postgres user=audo password=Db123123123 host=audo-db.postgres.database.azure.com port=5432 sslmode=require");
	}

	static Database* databaseInstance;
	soci::session sql;

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