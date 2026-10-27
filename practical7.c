
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

char peek()
{
    if (top == -1)
        return '\0';

    return stack[top];
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isspace((unsigned char)ch))
            continue;

        if (isdigit((unsigned char)ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && peek() != '(' &&
                  (precedence(peek()) > precedence(ch) ||
                  (precedence(peek()) == precedence(ch) && ch != '^')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[])
{
    int values[MAX];
    int valueTop = -1;
    int i, a, b;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if (isdigit((unsigned char)ch))
        {
            values[++valueTop] = ch - '0';
        }
        else
        {
            if (valueTop < 1)
            {
                printf("Invalid postfix expression!\n");
                return 0;
            }

            b = values[valueTop--];
            a = values[valueTop--];

            switch (ch)
            {
                case '+':
                    values[++valueTop] = a + b;
                    break;

                case '-':
                    values[++valueTop] = a - b;
                    break;

                case '*':
                    values[++valueTop] = a * b;
                    break;

                case '/':
                    if (b == 0)
                    {
                        printf("Division by zero is not allowed!\n");
                        return 0;
                    }
                    values[++valueTop] = a / b;
                    break;

                case '^':
                    values[++valueTop] = (int)pow(a, b);
                    break;

                default:
                    printf("Invalid operator!\n");
                    return 0;
            }
        }
    }

    if (valueTop != 0)
    {
        printf("Invalid postfix expression!\n");
        return 0;
    }

    return values[valueTop];
}

int main()
{
    char infix[MAX];
    char postfix[MAX];
    int result;

    printf("Enter an infix expression: ");
    if (fgets(infix, MAX, stdin) == NULL)
        return 1;

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    result = evaluatePostfix(postfix);

    printf("Evaluated result: %d\n", result);

    return 0;
}
