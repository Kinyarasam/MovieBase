#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_env_variables() {
    FILE *file = fopen(".env", "r");
    if (!file) {
        perror("Unable to open .env file");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "\n");

        if (key && value) {
            setenv(key, value, 1);
        }
    }
    fclose(file);
}
