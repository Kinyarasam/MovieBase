#ifndef __REVIEW_MODEL_H__
#define __REVIEW_MODEL_H__

typedef struct {
    int id;
    int movie_id;
    char user_name[255];
    char review[1024];
    int rating;
} Review;

#endif /** __REVIEW_MODEL_H__ */
