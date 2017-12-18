int mystrcmp(const char *str1, const char *str2) {
    while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0') {
        ++str1;
        ++str2;
    }
    if ((unsigned char) *str1 > (unsigned char) *str2)
        return 1;
    else if (*str1 == *str2)
        return 0;
    else
        return -1;
}
