__attribute__((fastcall))
void writechar(int c, struct FileWriteState *out);

__attribute__((fastcall))
void flush(struct FileWriteState *out);

asm(".globl writechar\n"
    "writechar:\n"
    
