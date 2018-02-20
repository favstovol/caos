        .text
        .global main
main:
        call    readi32
        cmpl    $0, %eax
        jl      end
start:
        push    %eax
        call    writei32
        call    nl
        pop     %eax
        decl    %eax
        cmpl    $0, %eax
        jnl     start
end:
        call    finish
