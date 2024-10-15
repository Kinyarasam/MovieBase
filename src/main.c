#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include "main.h"
#include "env.h"

int main(void) {
    load_env_variables();

    char dbConnInfo[256];
    sprintf(dbConnInfo, "host=%s dbname=%s user=%s password=%s", 
            getenv("DB_HOST"), getenv("DB_NAME"), 
            getenv("DB_USER"), getenv("DB_PASSWORD"));

    PGconn *conn = PQconnectdb(dbConnInfo);
    
    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        exit(1);
    }

    PQfinish(conn);
    return 0;
}
