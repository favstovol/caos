        .text
        .global list_del
list_del:
        pushl   %ebp
        movl    %esp, %ebp
        pushl   %ebx
        pushl   %edi

        movl    8(%ebp), %eax
        movl    12(%ebp), %ebx

start:
        test    %eax, %eax
        jz      exit
        movsbl  (%eax), %ecx
        cmpl    %ebx, %ecx
        jne     next_step
        movl    4(%eax), %eax
        jmp     start

next_step:
        movl    %eax, %edx  // %edx - prev node, %edi - current node
loop:
        movl    4(%edx), %edi
        test    %edi, %edi
        jz      exit
        movsbl  (%edi), %ecx
        cmpl    %ebx, %ecx
        jne     not_equal
        movl    4(%edi), %edi
        movl    %edi, 4(%edx)
        jmp     loop
not_equal:
        movl    %edi, %edx
        jmp     loop
exit:
        popl    %edi
        popl    %ebx
        movl    %ebp, %esp
        popl    %ebp
        ret
