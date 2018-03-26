#include <dirent.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    size_t len = PATH_MAX + 1;
    char fullpath[len];
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
        return 1;
    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue;
        strcpy(ptr, dirp->d_name);
        if (stat(fullpath, &statbuf) < 0)
            continue;
        if (S_ISREG(statbuf.st_mode) == 0)
            continue;
        if (statbuf.st_uid != getuid())
            continue;
        if ('A' <= dirp->d_name[0] && dirp->d_name[0] <= 'Z')
            counter += statbuf.st_size;
    }
    printf("%llu\n", counter);
}

