#include <stdio.h>
#include <string.h>

int parse_rwx_permissions(const char *str) {
    if (str == NULL)
        return -1;
    char ex[10] = "rwxrwxrwx";
    if (strlen(str) != strlen(ex))
        return -1;
    int answer = 0;
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 3; ++i) {
            if (str[j + i * 3] != ex[j] && str[j + i * 3] != '-')
                return -1;
        }
    }
    int bit = 1 << strlen(ex);
    for (int i = 0; i < strlen(ex); ++i) {
        bit >>= 1;
        if (ex[i] == str[i])
            answer = answer | bit;
    }
    return answer;
}
