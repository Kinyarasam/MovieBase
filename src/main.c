#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "env.h"
#include "logger.h"
#include "db.h"
#include "http_server.h"

int main(void) {
    load_env_variables();
    log_info("Loaded environment variables.");
    char connInfo[256];
    sprintf(connInfo, "host=%s dbname=%s user=%s password=%s", 
            getenv("DB_HOST"), getenv("DB_NAME"), 
            getenv("DB_USER"), getenv("DB_PASSWORD"));

    Database db;
    initialize_database(&db, connInfo);

    log_info("Application finished.");

    start_server();

    PQfinish(db.connection);
    return 0;
}
