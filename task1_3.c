
#include <stdio.h>

int main()
{
    int A[10][10], B[10][10], Sum[10][10], Mul[10][10];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 ||
        r1 > 10 || c1 > 10 || r2 > 10 || c2 > 10)
    {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    // Matrix Addition
    if (r1 == r2 && c1 == c2)
    {
        for (i = 0; i < r1; i++)
            for (j = 0; j < c1; j++)
                Sum[i][j] = A[i][j] + B[i][j];

        printf("\nMatrix Addition:\n");
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
                printf("%d ", Sum[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("\nMatrix addition is not possible.\n");
        printf("Both matrices must have the same dimensions.\n");
    }

    // Matrix Multiplication
    if (c1 == r2)
    {
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                Mul[i][j] = 0;

                for (k = 0; k < c1; k++)
                    Mul[i][j] += A[i][k] * B[k][j];
            }
        }

        printf("\nMatrix Multiplication:\n");
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
                printf("%d ", Mul[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("\nMatrix multiplication is not possible.\n");
        printf("Columns of A must equal rows of B.\n");
    }

    return 0;
}
