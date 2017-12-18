void normalize_path(char *buf) {
    char *cur = buf;
    while (*buf) {
        ++buf;
        if (*buf != '/' || *cur != '/')
            *(++cur) = *buf;
    }
}
