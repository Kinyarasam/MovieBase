#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include "main.h"
#include "env.h"
#include "logger.h"

int main(void) {
    load_env_variables();
    log_info("Loaded environment variables.");

    char dbConnInfo[256];
    sprintf(dbConnInfo, "host=%s dbname=%s user=%s password=%s", 
            getenv("DB_HOST"), getenv("DB_NAME"), 
            getenv("DB_USER"), getenv("DB_PASSWORD"));

    log_info("Connecting to the database...");
    PGconn *conn = PQconnectdb(dbConnInfo);
    
    if (PQstatus(conn) != CONNECTION_OK) {
         char err_msg[256];
        sprintf(err_msg, "Connection to database failed: %s", PQerrorMessage(conn));
        log_error(err_msg);
        PQfinish(conn);
        exit(1);
    }

    log_info("Successfully connected to the database.");
    PQfinish(conn);
    log_info("Application finished.");
    return 0;
}
