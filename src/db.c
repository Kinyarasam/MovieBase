#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include "logger.h"
#include "db.h"
#include "model/movie.h"
#include "model/review.h"

void initialize_database(Database *db, const char *conninfo) {
    db->connection = PQconnectdb(conninfo);
    
    // Check connection.
    if (PQstatus(db->connection) != CONNECTION_OK) {
        log_error("Connection to database failed.");
        exit(1);
    }

    db->create = &create_record;
}

void create_record(Database *db, Model *model) {
    PGresult *res; // Declare PGresult pointer once at the beginning
    const char *insert_sql = NULL; // Initialize insert_sql

    switch (model->type) {
        case MOVIE: {
            Movie *movie = (Movie *)model->data; // Cast to Movie
            insert_sql = "INSERT INTO movies (title, release_date, genre, rating, description) VALUES ($1, $2, $3, $4, $5)";
            
            res = PQexecParams(db->connection, insert_sql,
                            5, NULL,
                            (const char *[]) { movie->title, movie->release_date, movie->genre,
                                                (char *)&movie->rating, movie->description },
                            NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                log_error("Failed to add movie.");
            } else {
                log_info("Movie added successfully.");
            }
            break; // Important to break after handling the case
        }
        case REVIEW: {
            Review *review = (Review *)model->data; // Cast to Review
            insert_sql = "INSERT INTO reviews (movie_id, user_name, review, rating) VALUES ($1, $2, $3, $4)";
            
            res = PQexecParams(db->connection, insert_sql,
                            4, NULL,
                            (const char *[]) { (char *)&review->movie_id, review->user_name, review->review, (char *)&review->rating },
                            NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                log_error("Failed to add review.");
            } else {
                log_info("Review added successfully.");
            }
            break; // Important to break after handling the case
        }
        default:
            log_error("Unsupported model type.");
            return; // Exit if model type is unsupported
    }

    // Clear the result set after handling
    if (res) {
        PQclear(res);
    }
}
