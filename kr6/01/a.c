#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
//#include <gnu/lib-names.h>
int main(int argc, char *argv[]) {
    double x;
    sscanf(argv[1], "%lf", &x);
    for (int i = 2; i < argc; i += 2) {
        void *handle;
        double (*func)(double);
        char *error;

        handle = dlopen(argv[i], RTLD_LAZY);
        if (!handle)
            continue;
        dlerror();
        func = (double (*)(double)) dlsym(handle, argv[i + 1]);
        error = dlerror();
        if (error != NULL)
            continue;
        x = (*func)(x);
        dlclose(handle);
    }
    printf("%.10g\n", x);
}

