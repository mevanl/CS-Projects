BITS 32

section .data
    ; Prompt 
    promptMsg db "Please Enter a String: "
    promptMsgLen equ $-promptMsg

    ; is palindrome message
    isPalindromeMsg db "It is a palindrome!", 0xA
    isPalindromeMsgLen equ $-isPalindromeMsg

    ; is not palindrome message
    notPalindromMsg db "It is NOT a palindrome!", 0xA
    notPalindromMsgLen equ $-notPalindromMsg

section .bss 
    userString resd 1024
    teststr resd 1024

section .text
    global _start


_start:
    ; Printing the Prompt 
    mov eax, 4
    mov ebx, 1
    mov ecx, promptMsg
    mov edx, promptMsgLen
    int 80h

    ; Read user input
    mov eax, 3
    mov ebx, 0
    mov ecx, userString
    mov edx, 1024
    int 80h

while_loop:
    ; if user just pressed enter (newline), program terminates 
    cmp dword [userString], 0xA
    je exit

    dec eax ; at final character now 

    ; call is_palindrome function, must push the string and length to stack 
    push userString
    push eax
    call _is_palindrome

    ; if is_palindrome returned 1 or 0 
    cmp ax, 1
    je palindrome
    ; else 
    jmp notPalindrome

palindrome:
    ; print is palindrome message
    mov eax, 4
    mov ebx, 1
    mov ecx, isPalindromeMsg
    mov edx, isPalindromeMsgLen
    int 80h
    
    ; pop values from stack and reset the string
    pop ecx
    pop dword [userString]
    mov dword [userString], 0

    ; restart
    jmp _start

notPalindrome:
    ; Print not palindrome message
    mov eax, 4
    mov ebx, 1
    mov ecx, notPalindromMsg
    mov edx, notPalindromMsgLen
    int 80h

    ; pop values from stack and reset the string 
    pop ecx
    pop dword [userString]
    mov dword [userString], 0
    
    ; restart
    jmp _start  

exit:
    mov eax, 1
    mov ebx, 0
    int 80h


_is_palindrome:
    push ebp 
    mov ebp, esp


    ; start of string (i)
    mov ebx, dword [ebp+12]


    ; middle  (len/2)
    xor ecx, ecx
    xor edx, edx
    ; passed length & div by 2 for middle
    mov eax, dword [ebp+8]
    mov ecx, 2
    idiv ecx
    xor ecx, ecx
    mov ecx, eax


    ; end of string (j), string + length - 1
    xor edx, edx 
    mov edx, [ebp+8]
    mov eax, [ebp+12]
    add eax, edx 
    dec eax


    ; for loop 
for:
    ; incase single letter or even 
    cmp eax, ebx
    je true

    ; are letters the same?
    mov dl, [ebx]
    cmp [eax], dl

    ; if not the same..
    jne false

    ; else..
    inc ebx
    dec eax

    loop for
    ; if looped without failing, must be true 
    jmp true
    
false:
    ; return value of 0, clear stack and ret
    mov ax, 0
    leave
    ret
true:
    ; return  value of 1, clear stack and ret 
    mov ax, 1
    leave
    ret