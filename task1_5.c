
#include <stdio.h>

// Iterative method
unsigned long long factorialIterative(int n)
{
    unsigned long long fact = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive method
unsigned long long factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

int main()
{
    int n;

    printf("Enter a number (0 to 20): ");
    scanf("%d", &n);

    if (n < 0 || n > 20)
    {
        printf("Please enter a number between 0 and 20.\n");
        return 1;
    }

    printf("Factorial using Iterative Method = %llu\n",
           factorialIterative(n));

    printf("Factorial using Recursive Method = %llu\n",
           factorialRecursive(n));

    return 0;
}
