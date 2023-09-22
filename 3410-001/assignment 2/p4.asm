BITS 32

section .data
    ; program name
    titleMsg DB "Two Character Swap", 0xA
    titleMsgLen EQU $-titleMsg

    ; User Prompt
    userTwoCharMsg DB "Enter a 2 character string: "
    userTwoCharMsgLen EQU $-userTwoCharMsg

    ; solution msg
    solutionMsg DB "Swapped: "
    solutionMsgLen EQU $-solutionMsg

section .bss
    twoCharString resb 3
    highOrderChar resb 1
    lowOrderChar resb 1

section .text
    global _start

_start:
    ; print title
    mov eax, 4
    mov ebx, 1
    mov ecx, titleMsg
    mov edx, titleMsgLen
    int 80h

    ; print prompt for 2 character string
    mov eax, 4
    mov ebx, 1
    mov ecx, userTwoCharMsg
    mov edx, userTwoCharMsgLen
    int 80h

    ; store user input
    mov eax, 3
    mov ebx, 0
    mov ecx, twoCharString
    mov edx, 2
    int 80h

    ; flip the string  
    xor eax, eax
    mov ax, [twoCharString] ; move into 16bit register (ah has high order bits, al low order)
    mov [highOrderChar], ah
    mov [lowOrderChar], al

    ; swap bits from low order to high order, now the characters are swapped in the 32bit ax register
    xor eax, eax
    mov ah, [lowOrderChar]
    mov al, [highOrderChar]

    mov [twoCharString], ax
    mov BYTE [twoCharString+2], 10 ; add new line 

    ; print reversed string 
    mov eax, 4
    mov ebx, 1
    mov ecx, solutionMsg
    mov edx, solutionMsgLen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, twoCharString
    mov edx, 3
    int 80h

    ; exit
    mov eax, 1
    mov ebx, 0
    int 80h