#ifndef __MOVIE_MODEL_H__
#define __MOVIE_MODEL_H__

typedef struct {
    int id;
    char title[255];
    char release_date[11];
    char genre[100];
    int rating;
    char description[1024];
} Movie;

#endif /** __MOVIE_MODEL_H__ */
