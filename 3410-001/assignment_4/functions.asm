bits 32
global addstr, is_palindromeASM, factstr, palindrome_check
extern atoi, fact, is_palindromeC

section .data
userPrompt: db "Enter string: "
userPromptLen equ $-userPrompt

; is palindrome message
isPalindromeMsg db "It is a palindrome!", 0xA
isPalindromeMsgLen equ $-isPalindromeMsg

; is not palindrome message
notPalindromMsg db "It is NOT a palindrome!", 0xA
notPalindromMsgLen equ $-notPalindromMsg

section .bss
userString resb 100

section .text
addstr:
    push ebp 
    mov ebp, esp

    ; add space to stack for local vars, 
    ; space for the first char* on stack 
    sub esp, 4

    ; local var for first char*
    mov eax, dword [ebp+8]
    mov dword [ebp-4], eax

    ; convert to integer, stored into eax 
    call atoi 
    ; store our integer locally on the stack
    sub esp, 4
    mov dword [ebp-8], eax

    ; store second char* 
    sub esp, 4
    mov eax, dword [ebp+12]
    mov dword [ebp-12], eax
    ; convert to integer, stored into eax 
    call atoi
    ; store our integer locally on the stack
    sub esp, 4
    mov dword [ebp-16], eax

    ; move integers into registers
    mov eax, dword [ebp-16]
    mov edx, dword [ebp-8]

    ; add into return register eax, leave and return
    add eax, edx
    
    ; remove local space from stack and pop ebp 
    add esp, 16
    pop ebp
    
    ret

is_palindromeASM:
    push ebp
    mov ebp, esp
    pusha

    mov esi, dword [ebp+8]
    xor ecx, ecx

counter:
    cmp dword [esi], 0
    jz palindrome_test

    inc ecx
    inc esi
    jmp counter

palindrome_test:
    dec esi
    mov edi, dword [ebp+8]

    ; put length / 2 into ecx
    mov eax, ecx
    xor edx, edx
    xor ecx, ecx
    mov ecx, 2
    idiv ecx
    xor ecx, ecx
    mov ecx, eax

for:
    ; if its one letter (points to same address in memory) or even and has yet to fail
    cmp esi, edi
    je true

    ; compare the letters 
    mov dl, [edi]
    cmp [esi], dl

    ; if not equal, not a palindrome
    jne false

    ; else they are equal, move to adjacent character and loop until ecx is 0
    inc edi
    dec esi

    loop for

true:
    ; is a palindrome, restore registers, return 1
    popa 
    pop ebp
    mov eax, 1

    ret

false:
    ; if was no palindrone, restore registers, return 0
    popa
    pop ebp
    mov eax, 0

    ret


factstr:
    push ebp 
    mov ebp, esp

    sub esp, 4

    pusha

    push dword [ebp+8]
    ; convert to integer, stored into eax 
    call atoi 
    ; store our integer locally on the stack
    push eax

    xor eax, eax
    call fact

    add esp, 8
    
    ; store onto stack, (before pusha so can preserve the answer)
    mov dword [ebp-4], eax
    popa
    pop eax
    pop ebp 
    ret

palindrome_check:
    push ebp 
    mov ebp, esp

    ; preserve caller registers 
    pusha

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
    mov edx, 100
    int 80h

    ; null terminate the string ?
    dec eax
    mov byte [ecx+eax], 0

    push ecx 
    call is_palindromeC 
    pop ecx

    cmp eax, 0
    jz notPalindrome   

isPalindrome:
    ; print that it is a palidnrome
    mov eax, 4        
    mov ebx, 1        
    mov ecx, isPalindromeMsg  
    mov edx, isPalindromeMsgLen      
    int 80h      
    jmp exit

notPalindrome:
    ; print that it is not a palindrome 
    mov eax, 4        
    mov ebx, 1        
    mov ecx, notPalindromMsg
    mov edx, notPalindromMsgLen
    int 80h  

exit:
    ; restore registers and return 
    popa
    pop ebp
    ret