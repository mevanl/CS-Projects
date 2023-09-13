BITS 32

section .data
    ; user digits 
    firstDigitMsg DB "Enter a single digit number: "              ; Ask user for first digit
    firstDigitMsgLen EQU $-firstDigitMsg                          ; first digit length
    secondDigitMsg DB "Enter another single digit number: "       ; ask user for second digit
    secondDigitMsgLen EQU $-secondDigitMsg                        ; second digit length

    ; result 
    displayMultiple DB "The answer is: "
    displayMultipleLen EQU $-displayMultiple

section .bss
    firstDigit RESB 5
    secondDigit RESB 5
    answer RESB 5

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
    mov edx, 5                                                   ; reserved max size of input
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
    mov edx, 5
    int 80h  

    ; converting from strings to decimal 
    mov ah, [firstDigit]                                         ; move the value of the first digit into ah
    sub ah, '0'                                                  ; convert from ascii to decimal 
    mov al, [secondDigit]                                        ; same for second digit
    sub al, '0'

    ; put decimal back into varialbe's address
    mov [firstDigit], ah
    mov [secondDigit], al

    mov ax, 0
    mov al, [firstDigit]
    imul ax, [secondDigit]

    add al, '0'
    mov [answer], al 

    ; print solution
    mov eax, 4
    mov ebx, 1
    mov ecx, displayMultiple
    mov edx, displayMultipleLen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, answer
    mov edx, 5
    int 80h

    ; quit
    mov eax, 1                                                   ; sys exit
    mov ebx, 0
    int 80h                                                      ; call kernel
