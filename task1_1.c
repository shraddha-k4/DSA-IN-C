#include <stdio.h>

// GCD using Conventional Method
int gcdConventional(int a, int b)
{
    int i, gcd = 1;
    int min = (a < b) ? a : b;

    for (i = 1; i <= min; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }

    return gcd;
}

// GCD using Euclid's Algorithm
int gcdEuclid(int a, int b)
{
    int temp;

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    int a, b;
    int gcd1, gcd2, lcm1, lcm2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0)
    {
        printf("Please enter positive integers.\n");
        return 1;
    }

    // Conventional Method
    gcd1 = gcdConventional(a, b);
    lcm1 = (a / gcd1) * b;

    // Euclid's Algorithm
    gcd2 = gcdEuclid(a, b);
    lcm2 = (a / gcd2) * b;

    printf("\n--- Conventional Method ---\n");
    printf("GCD = %d\n", gcd1);
    printf("LCM = %d\n", lcm1);

    printf("\n--- Euclid's Algorithm ---\n");
    printf("GCD = %d\n", gcd2);
    printf("LCM = %d\n", lcm2);

    return 0;
}