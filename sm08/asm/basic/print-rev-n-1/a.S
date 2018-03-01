        .text
        .global main
main:
        call    readi32
start:
        cmpl    $0, %eax
        jl      end
        push    %eax
        call    writei32
        call    nl
        pop     %eax
        decl    %eax
        jmp     start
end:
        call    finish
