BITS 32

section .data                                                          ; Data Segment
    ; User Digits
    firstDigitMsg DB "Enter a single digit number: ",                  ; Ask user for first digit
    firstDigitMsgLen EQU $-firstDigitMsg                               ; first digit length
    secondDigitMsg DB "Enter another single digit number: ",           ; ask user for second digit
    secondDigitMsgLen EQU $-secondDigitMsg                             ; second digit length

    ; Final addition value
    displayQuotient DB "The answer is: "
    displayQuotientLen EQU $-displayQuotient
    displayRemainder DB "The answer is: "
    displayRemainderLen EQU $-displayRemainder

section .bss
    firstDigit RESB 2
    secondDigit RESB 1
    quotient RESB 1
    remainder RESB 1

section .text
    global _start

_start:
    ; Print + input for first digit
    mov eax, 4                                                   ; sys_write
    mov ebx, 1                                                   ; STDOUT
    mov ecx, firstDigitMsg                                       ; first digit inquiry
    mov edx, firstDigitMsgLen                                    ; len of first digit question
    int 80h                                                      ; Sys interupt (call kernel) 

    ; Read and store the first digit 
    mov eax, 3                                                   ; sys_read
    mov ebx, 0                                                   ; STDIN
    mov ecx, firstDigit                                          ; memory location to store string input
    mov edx, 2                                                   ; reserved max size of input
    int 80h    

    ; Print + input for second digit
    mov eax, 4
    mov ebx, 1
    mov ecx, secondDigitMsg
    mov edx, secondDigitMsgLen
    int 80h

    ; Read and store the second digit
    mov eax, 3
    mov ebx, 0
    mov ecx, secondDigit
    mov edx, 1
    int 80h    

    ; convert string to decimal
    mov ax, 0
    mov ax, [firstDigit]
    sub ax, '0'
    mov bl, [secondDigit]
    sub bl, '0'

    ; divide
    idiv bl

    ; convert them to string
    add al, '0'
    add ah, '0'

    ; store the quotient and remainder
    mov [quotient], al
    mov [remainder], ah

    ; print quotient 
    mov eax, 4
    mov ebx, 1
    mov ecx, displayQuotient
    mov edx, displayQuotientLen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, quotient
    mov edx, 1
    int 80h

    ; print remainder
    mov eax, 4
    mov ebx, 1
    mov ecx, displayRemainder
    mov edx, displayRemainderLen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, remainder
    mov edx, 1
    int 80h   

    mov eax, 1
    mov ebx, 0
    int 80h