
#include <stdio.h>
#include <time.h>

// Iterative approach
void fibonacciIterative(int n)
{
    int a = 0, b = 1, c, i;

    printf("Fibonacci Series (Iterative): ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }

    printf("\n");
}

// Recursive function
int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;

    return fibonacciRecursive(n - 1) +
           fibonacciRecursive(n - 2);
}

// Display series using recursion
void fibonacciRecursiveSeries(int n)
{
    int i;

    printf("Fibonacci Series (Recursive): ");

    for (i = 0; i < n; i++)
        printf("%d ", fibonacciRecursive(i));

    printf("\n");
}

int main()
{
    int n;
    clock_t start, end;
    double iterativeTime, recursiveTime;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 1 || n > 45)
    {
        printf("Please enter a number between 1 and 45.\n");
        return 1;
    }

    start = clock();
    fibonacciIterative(n);
    end = clock();
    iterativeTime = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    fibonacciRecursiveSeries(n);
    end = clock();
    recursiveTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nExecution Time Comparison:\n");
    printf("Iterative: %.6f seconds\n", iterativeTime);
    printf("Recursive: %.6f seconds\n", recursiveTime);

    return 0;
}
