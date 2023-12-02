#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C Function Prototypes
int fact(int);
int is_palindromeC(char*);

// Assembly Function Prototypes 
int addstr(char*, char*);
int is_palindromeASM(char*);
int factstr(char*);
void palindrome_check();


int main()
{

    int choice;

    while (choice)
    {
        // Print Menu and Get user's choice
        printf("\n\nBack and Forth:\n");
        printf("\t1. Add Two Strings\n");
        printf("\t2. Test Palindrome (C -> ASM)\n");
        printf("\t3. Print Factorial\n");
        printf("\t4. Test Palindrome (ASM -> C)\n");
        printf("\t5. Exit\n");
        printf("\n\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            ;
            char str1[10];
            char str2[10];
            int resultCase1;

            printf("\nEnter first number: ");
            scanf("%9s", str1);
            printf("\nEnter second number: ");
            scanf("%9s", str2);

            resultCase1 = addstr(str1, str2);
            printf("\nThe sum is: %d", resultCase1);
            break;


            case 2:
            ;
            // string with values set to 0 (for null termination)
            char possiblePalindrome[1024] = {0};
            int resultCase2 = 0;

            printf("\nEnter string to find if it is a palindrome: ");
            scanf("%1023s", possiblePalindrome);

            resultCase2 = is_palindromeASM(possiblePalindrome);
            if (resultCase2 == 1)
            {
                printf("\nIs a Palindrome!");
            }
            else
            {
                printf("\nNot a palindrome.");
            }
            break;


            case 3:
            ;
            char num[10];
            int resultCase3; 

            printf("Enter Number: ");
            scanf("%9s", num);

            resultCase3 = factstr(num);
            printf("\nThe factorial is: %d", resultCase3);
            break;


            case 4:
            ;
            palindrome_check();
            break;


            case 5:
            choice = 0; 
            break;
        }
    }

    return 0;
}

// Recursive factorial function
int fact(int num)
{
    if (num == 0)
    {
        return 1;
    }

    return num * fact(num-1);
}

// Test if palindrome or not 
int is_palindromeC(char* userStr)
{

    int left = 0;
    int right = strlen(userStr) - 1;

    while (left < right)
    {
        if (userStr[left] != userStr[right])
        {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}