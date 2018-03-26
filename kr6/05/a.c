#include <dirent.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char *argv[]) {
    int64_t flag;
    sscanf(argv[2], "%" PRId64, &flag);
    uint64_t max_size;
    if (flag < 0)
        max_size = 0;
    else
        sscanf(argv[2], "%" PRIu64, &max_size);
    size_t len = PATH_MAX + 1;
    char fullpath[len];
    char best[len];
    best[0] = 0;
    uint64_t best_size = 0;
    strncpy(fullpath, argv[1], len);
    fullpath[len - 1] = 0;

    struct stat statbuf;
    struct dirent *dirp;
    DIR *dp = opendir(argv[1]);
    char *ptr;
    unsigned long long counter = 0;

    ptr = fullpath + strlen(fullpath);
    *ptr++ = '/';
    *ptr = 0;
    if ((dp = opendir(fullpath)) == NULL)
        return 0;
    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;
        strcpy(ptr, dirp->d_name);
        if (lstat(fullpath, &statbuf) < 0)
            continue;
        if (S_ISREG(statbuf.st_mode) == 0)
            continue;
        if (statbuf.st_size > best_size) {
            best_size = statbuf.st_size;
            strcpy(best, dirp->d_name);
        } else if (statbuf.st_size == best_size && (strcmp(dirp->d_name, best) < 0 || best[0] == 0))
            strcpy(best, dirp->d_name);
        if (counter <= max_size)
            counter += statbuf.st_size;
    }
    if (counter > max_size)
        printf("%s\n", best);
}
