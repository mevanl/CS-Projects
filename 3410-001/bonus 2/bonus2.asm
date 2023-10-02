BITS 32

section .data
userPrompt: db "Enter a string you would like to be reversed: "
userPromptLen equ $-userPrompt

section .bss
userString resb 1024        ; reserve a kilobyte
reversedString resb 1024    

global _start
section .text
_start:
    ; print the prompt
    mov eax, 4
    mov ebx, 1
    mov ecx, userPrompt
    mov edx, userPromptLen
    int 80h

    ; read the user's response
    mov eax, 3
    mov ebx, 0
    mov ecx, userString
    mov edx, 1024
    int 80h

    ; move string into register for string manipulation and clear counter register (ecx)
    mov esi, userString
    xor ecx, ecx


    ; create for loop, the will traverse the string until we reach the end
    ; the end of strings contain newlines and terminating zeroes, go until found.
go_to_end:
    ; compare to see if we have reached the terminating zero
    cmp byte [esi], 0
    ; if we have reached...
    jz reverse_string
    ; else if have not reached...
    inc ecx                 ; increment counter (used when reversing)
    inc esi                 ; increment position in the string
    jmp go_to_end           ; restart the process until condition met

    
    ; now that string we are at the end, and have the count of the string in ecx
    ; can reverse the string 
reverse_string:
    dec ecx                 ; ecx now at 'index' to the final characater in the string
    mov edx, ecx            ; used for printing the length 

    ; incase ecx is zero, meaning string is empty...
    jecxz print_results


    ; start reversing the string
    mov edi, reversedString ; edi will be used to manipulate string at reversedString memory

    ; skip the terminating zero and newline character, will be added to reversedString later
    dec esi
    dec esi


    ; now loop through userString (in esi) 
    ; work backwards putting it into reversedString (in edi)
reverse_copy:
    ; move character at esi into temp register, put into edi
    mov al, [esi]
    mov [edi], al
    ; go foward in reversed string, backwards in normal 
    inc edi
    dec esi
    ; until ecx is zero
    loop reverse_copy

print_results:
    ; before print, add terminating zero and newline to reversedString
    mov BYTE [edi], 10
    inc edx                 ; remember this had the final character index for size
    mov BYTE [edi+1], 0

    ; print solution
    mov eax, 4
    mov ebx, 1
    mov ecx, reversedString
    int 80h

    mov eax, 1
    mov ebx, 0
    int 80h