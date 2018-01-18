#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getline2(FILE *f) {
    unsigned int cp = 16;
    unsigned int size = 0;
    char *string = malloc(cp);
    if (string == NULL)
        return NULL;
    int c;
    while ((c = getc_unlocked(f)) != EOF) {
        if (c == '\0')
            break;
        ++size;
        if (size > cp) {
            cp *= 2;
            char *n_string = realloc(string, cp);
            if (n_string == NULL) {
                free(string);
                return NULL;
            }
            string = n_string;
        }
        *(string + size - 1) = c;
        if (c == '\n')
            break;
    }
    if (size == 0) {
        free(string);
        return NULL;
    }
    char *n_string = realloc(string, size + 1);
    if (n_string == NULL) {
        free(string);
        return NULL;
    }
    n_string[size] = '\0';
    return n_string;
}
