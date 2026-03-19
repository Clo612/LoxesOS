global inb
inb:
    mov dx, [rsp+8]   ; port
    in al, dx
    movzx rax, al
    ret
