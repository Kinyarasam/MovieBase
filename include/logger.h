#ifndef __LOGGER_H__
#define __LOGGER_H__

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void log_info(const char *message);
void log_warning(const char *message);
void log_error(const char *message);

#endif /** __LOGGER_H__ */
