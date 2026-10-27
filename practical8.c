
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue is Full!\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;

    printf("Element inserted successfully.\n");
}

void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue is Empty!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void peek()
{
    if (front == -1)
        printf("Circular Queue is Empty!\n");
    else
        printf("Front element: %d\n", queue[front]);
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is Empty!\n");
        return;
    }

    printf("Queue elements: ");
    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

void isEmpty()
{
    if (front == -1)
        printf("Queue is Empty.\n");
    else
        printf("Queue is not Empty.\n");
}

void isFull()
{
    if ((rear + 1) % MAX == front)
        printf("Queue is Full.\n");
    else
        printf("Queue is not Full.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- CIRCULAR QUEUE ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check Empty\n");
        printf("6. Check Full\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: isEmpty(); break;
            case 6: isFull(); break;
            case 7: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
