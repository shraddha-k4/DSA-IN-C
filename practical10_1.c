
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertBeginning()
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;

    printf("Node inserted at beginning.\n");
}

void insertEnd()
{
    struct node *newnode, *temp;

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted at end.\n");
}

void deleteBeginning()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void deleteEnd()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev == NULL)
        head = NULL;
    else
        temp->prev->next = NULL;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void search()
{
    struct node *temp = head;
    int key, pos = 1;

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found at position %d.\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Element not found!\n");
}

void displayForward()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Forward: NULL <-> ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void displayBackward()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: NULL <-> ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Search\n");
        printf("6. Display Forward\n");
        printf("7. Display Backward\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: deleteBeginning(); break;
            case 4: deleteEnd(); break;
            case 5: search(); break;
            case 6: displayForward(); break;
            case 7: displayBackward(); break;
            case 8: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 8);

    while (head != NULL)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
