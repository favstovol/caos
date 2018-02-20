        .data
sum:
        .int    0
lowest:
        .int    0
highest:
        .int    0
ireg:
        .int    0
        .text
        .global main
main:
        movl    $-1, %eax
        shr     $1, %eax
        movl    %eax, highest
        movl    $1, %eax
        shl     $31, %eax
        movl    %eax, lowest      
start:
        call    readi32
        jc      end
        addl    %eax, sum
        jno     start
        lahf
        shr     $15, %ax
        and     $1, %eax
        addl    $1, %eax
        movl    %eax, ireg
end:
        movl    ireg, %ebx
        movl    sum(,%ebx,4), %eax
        call    writei32
        call    nl
        call    finish
