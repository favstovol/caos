        .text
input_n:
        .asciz  "%u"
input_numb:
        .asciz  "%d"
output: 
        .asciz  "%d "
nl:     
        .asciz  "\n"
        .global process
process:
        pushl   %esi
        pushl   %edi
        pushl   %ebx
        pushl   %ebp
        movl    %esp, %ebp
        subl    $4, %esp
        movl    %esp, %edi
        pushl   %edi
        pushl   $input_n
        call    scanf
        movl    (%edi), %ebx
        movl    %ebx, %esi
        addl    $8, %esp
        test    %ebx, %ebx
loop1_start:
        jz      loop1_end
        pushl   %edi
        pushl   $input_numb
        call    scanf
        addl    $8, %esp
        pushl   (%edi)
        decl    %ebx
        jmp     loop1_start
loop1_end:
        movl    %esi, %ebx
        test    %ebx, %ebx
loop2_start:
        jz      loop2_end
        pushl   $output
        call    printf
        addl    $8, %esp
        decl    %ebx
        jmp loop2_start
loop2_end:
        pushl   $nl
        call    printf
        addl    $4, %esp
        movl    %ebp, %esp
        popl    %ebp
        popl    %ebx
        popl    %edi
        popl    %esi
        ret

        .global main
main:
        call    process
        call    finish
