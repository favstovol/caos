#include <asm/unistd_32.h>

unsigned char buffer[4096];

struct FileWriteState {
    int fd;
    unsigned char *buf;
    int bufsize;
    int cursize;
    // здесь потребуется добавить поля для реализации буферизованной записи
};

struct FileReadState state_keeper = {1, buffer, 4096, 0};

struct FileReadState *stout = &state_keeper;

__attribute__((fastcall))
void writechar(int c, struct FileWriteState *out) {
    (*out).buf[(*out).cursize] = c;
    ++(*out).cursize;
    if ((*out).cursize == (*out).bufsize)
        flush(out);
}

__attribute__((fastcall))
void flush(struct FileWriteState *out) {
    if (cursize == 0)
        return;
    int out_size;
    asm("movl   $4, %%eax\n"
        "movl   %1, %%ebx\n"
        "movl   %2, %%ecx\n"
        "movl   %3, %%edx\n"
        "int    $0x80\n"
        "movl   %%eax, %0"
        : "=g" (out_size)
        : "g" ((*out).fd), "g" ((*out).buf), "g" ((*out).cursize)
        : "%eax", "%ebx", "%ecx", "%edx");
    (*out).cursize = 0;
}

asm(".globl writechar\n"
    "writechar:\n"
    
