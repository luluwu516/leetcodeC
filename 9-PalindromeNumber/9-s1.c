#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(int x)
{
    if (x < 0)
    {
        return 0;
    }
    else if (x < 10)
    {
        return 1;
    }
    else
    {
        char str[20];
        sprintf(str, "%d", x);
        int len = strlen(str);
        for (int i = 0; i < len / 2; i++)
        {
            if (str[i] != str[len - i - 1])
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    // declaraction
    int num;

    // input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // processing and output
    printf("\nResult: ");
    if (isPalindrome(num))
    {
        printf("%d is a Palindrome Number.\n", num);
    }
    else
    {
        printf("%d is not a Palindrome Number.\n", num);
    }

    return 0;
}
