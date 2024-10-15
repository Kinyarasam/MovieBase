#include <stdio.h>
#include <time.h>
#include <string.h>
#include "logger.h"

void log_info(const char *message) {
    time_t now;
    time(&now);
    // Format the time to remove the newline
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove the newline character

    printf("%s[INFO] [%s] %s%s\n", GREEN, time_str, message, RESET);
}

void log_warning(const char *message) {
    time_t now;
    time(&now);
    // Format the time to remove the newline
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove the newline character

    printf("%s[WARNING] [%s] %s%s\n", YELLOW, time_str, message, RESET);
}

void log_error(const char *message) {
    time_t now;
    time(&now);
    // Format the time to remove the newline
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove the newline character

    fprintf(stderr, "%s[ERROR] [%s] %s%s\n", RED, time_str, message, RESET);
}
