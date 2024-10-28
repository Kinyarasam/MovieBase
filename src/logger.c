#include <stdio.h>
#include <time.h>
#include <string.h>
#include "logger.h"

void log_info(const char *message) {
    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';

    printf("%s[INFO] %s[%s] %s%s\n", GREEN, BLUE, time_str, RESET, message);
}

void log_warning(const char *message) {
    time_t now;
    time(&now);

    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';

    printf("%s[WARNING] %s[%s] %s%s\n", YELLOW, BLUE, time_str, RESET, message);
}

void log_error(const char *message) {
    time_t now;
    time(&now);

    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';

    fprintf(stderr, "%s[ERROR] %s[%s] %s%s\n", RED, BLUE, time_str, RESET, message);
}
