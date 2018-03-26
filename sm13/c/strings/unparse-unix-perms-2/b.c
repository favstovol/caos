#include <stdio.h>

const char *perms_to_str(char *buf, size_t size, int perms) {
    if (size == 0)
        return buf;
    char s[16];
    char ex[16] = "rwxrwxrwx";
    int st = 0x200;
    for (int i = 0; i < 9; ++i) {
        st >>= 1;
        if (st & perms)
            s[i] = ex[i];
        else
            s[i] = '-';
    }
    if ((perms & 0x809) == 0x801 || (perms & 0x809) == 0x808)
        s[2] = 's';
    if ((perms & 0x401) == 0x401)
        s[5] = 's';
    if ((perms & 0x203) == 0x203)
        s[8] = 't';
    if (size > 10)
        size = 10;
    for (int i = 0; i < size - 1; ++i)
        buf[i] = s[i];
    buf[size - 1] = '\0';
    return buf;
}

int main() {
    char buf[16];
    perms_to_str(buf, 11, 06706);
    printf("%s\n", buf);
    perms_to_str(buf, sizeof(buf), 0640);
    printf("%s\n", buf);
}

