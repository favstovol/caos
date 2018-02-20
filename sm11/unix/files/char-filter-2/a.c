#include <asm/unistd_32.h>

void _start() {
    asm("start:\n"
        "subl   $1, %%esp\n"
        "movl   $3, %%eax\n"
        "xorl   %%ebx, %%ebx\n"
        "movl   %%esp, %%ecx\n"
        "movl   $1, %%edx\n"
        "int    $0x80\n"
        "cmpl   $0, %%eax\n"
        "jle    exit\n"
        "cmpb   $97, (%%esp)\n"
        "jb     write\n"
        "cmpb   $122, (%%esp)\n"
        "ja     write\n"
        "subb   $32, (%%esp)\n"
        "write:\n"
        "movl   $4, %%eax\n"
        "movl   $1, %%ebx\n"
        "movl   %%esp, %%ecx\n"
        "movl   $1, %%edx\n"
        "int    $0x80\n"
        "jmp    start\n"
        "exit:\n"
        "movl   $1, %%eax\n"
        "xorl   %%ebx, %%ebx\n"
        "int    $0x80\n" : : : "%esp", "%eax", "%ebx", "%ecx", "%edx");
}

