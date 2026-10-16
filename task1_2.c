
#include <stdio.h>

int main()
{
    int n, remainder[32], i = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    if (n == 0)
    {
        printf("Binary equivalent = 0\n");
        return 0;
    }

    while (n > 0)
    {
        remainder[i] = n % 2;
        n = n / 2;
        i++;
    }

    printf("Binary equivalent = ");

    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", remainder[i]);
    }

    printf("\n");

    return 0;
}
