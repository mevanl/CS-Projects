BITS 32

section .data
    ; title
    titleMsg DB "The Mutiplying Program", 0xA
    titleMsgLen EQU $-titleMsg

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
    ; print title
    mov eax, 4
    mov ebx, 1
    mov ecx, titleMsg
    mov edx, titleMsgLen
    int 80h

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
    sub BYTE [firstDigit], '0'                                   ; String --> int

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
    sub BYTE [secondDigit], '0'

    mov ax, 0                                                     ; clear ax register
    mov al, [firstDigit]                                          
    imul BYTE [secondDigit]                                       ; integer multiplicaton on accumulator al

    add al, '0'                                                   ; int --> string
    mov [answer], al                                              ; store in answer
    mov BYTE [answer+1], 10                                       ; add newline

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
