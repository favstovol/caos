        .data
even:   .int    0
odd:    .int    0

        .text
        .global main
main:
        call    readi32
        jc      end
        test    $1, %eax
        jz      zero
        addl    %eax, odd
        jmp     main
zero:
        addl    %eax, even
        jmp     main
end:
        movl    even, %eax
        call    writei32
        call    nl
        movl    odd, %eax
        call    writei32
        call    nl
        call    finish
