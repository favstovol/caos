#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
//#include <gnu/lib-names.h>
int main(int argc, char *argv[]) {
    void *handle;
    double (*cosine)(double);
    char *error;

//    handle = dlopen(LIBM_SO, RTLD_LAZY);
    handle = dlopen("libm.so.6", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();
    cosine = (double (*)(double)) dlsym(handle, argv[1]);
    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }
    double x;
    while (scanf("%lf", &x) == 1) {
        printf("%.10g\n", (*cosine)(x));
    }
    dlclose(handle);
}
