        .data
res:    .int 0
        .text
        .global main
        .global process
process:
        pushl   %ebp
        movl    %esp, %ebp

        movl    8(%ebp), %eax
        movl    $-3, %edx
        imull   %edx
        jo      overflow
        movl    %eax, %ecx
        movl    12(%ebp), %eax
        movl    $2, %edx
        imull   %edx
        jo      overflow
        addl    %ecx, %eax
        jo      overflow
        movl    16(%ebp), %ecx
        movl    %eax, (%ecx)
        movl    $1, %eax
        jmp     exit
overflow:
        movl    $0, %eax
exit:   
        movl    %ebp, %esp
        popl    %ebp
        ret

main:
        pushl   $res
        pushl   $5
        pushl   $10
        call    process
        addl    $12, %esp
        movl    res, %eax
        call    writei32
        call    finish
