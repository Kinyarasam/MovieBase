#ifndef __DB_H__
#define __DB_H__

#include <libpq-fe.h>

typedef enum {
    MOVIE,
    USER,
    REVIEW
} ModelType;

typedef struct {
    ModelType type;
    void *data;
} Model;

typedef struct Database {
    PGconn *connection;

    void (*create)(struct Database *, Model *);
    void (*get)(struct Database *, int);
    void (*get_all)(struct Database *);
} Database;

void initialize_database(Database *db, const char *conninfo);
void create_record(Database *db, Model *model);

#endif /** __DB_H__ */
