        .data
sum:    .int    0
        .text
        .global main
main:
//        call    readi32
        movl    $1, %eax
        shl     $31, %eax
        movl    %eax, sum
        call    readi32
        addl    sum, %eax
        call    writei32
        call    nl
        call    finish
