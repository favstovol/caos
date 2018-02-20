#include <asm/unistd_32.h>

unsigned char buffer[4096];

struct FileReadState {
    int fd;
    unsigned char *buf;
    int bufsize;
    int lc;
    int realsize;
    int counter;
};

struct FileReadState state_keeper = {0, buffer, 4096, -1, 0, 0};

struct FileReadState *stin = &state_keeper;

int nextchar() {
    if ((*stin).realsize == -1)
        return -1;
    if ((*stin).counter >= (*stin).realsize) {
        asm("movl   $3, %%eax\n"
            "movl   %1, %%ebx\n"
            "movl   %2, %%ecx\n"
            "movl   %3, %%edx\n"
            "int    $0x80\n"
            "movl   %%eax, %0"
            : "=g" ((*stin).realsize)
            : "g" ((*stin).fd), "g" ((*stin).buf), "g" ((*stin).bufsize)
            : "%eax", "%ebx", "%ecx", "%edx");
        (*stin).counter = 0;
        if ((*stin).realsize <= 0) {
            (*stin).realsize = -1;
            return -1;
        }
    }
    (*stin).lc = (*stin).buf[(*stin).counter];
    ++(*stin).counter;
    return (*stin).lc;
}

int lastchar() {
    return (*stin).lc;
}

