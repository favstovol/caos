#include <stdio.h>
#include <string.h>

int parse_rwx_permissions(const char *str) {
    if (str == NULL)
        return -1;
    char ex[10] = "rwxrwxrwx";
    int ex_len = strlen(ex);
    if (strlen(str) != ex_len)
        return -1;
    int answer = 0;
    for (int i = 0; i < ex_len; ++i)
        if (str[i] != ex[i] && str[i] != '-')
            return -1;
    int bit = 1 << ex_len;
    for (int i = 0; i < ex_len; ++i) {
        bit >>= 1;
        if (ex[i] == str[i])
            answer = answer | bit;
    }
    return answer;
}
