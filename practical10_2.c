
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL;

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

    if (last == NULL)
    {
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
    }

    printf("Node inserted at beginning.\n");
}

void insertEnd()
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

    if (last == NULL)
    {
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }

    printf("Node inserted at end.\n");
}

void deleteBeginning()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = last->next;

    if (temp == last)
    {
        last = NULL;
    }
    else
    {
        last->next = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void deleteEnd()
{
    struct node *temp, *prev;

    if (last == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = last;

    if (last->next == last)
    {
        printf("Deleted element: %d\n", last->data);
        free(last);
        last = NULL;
        return;
    }

    prev = last->next;

    while (prev->next != last)
        prev = prev->next;

    printf("Deleted element: %d\n", last->data);

    prev->next = last->next;
    last = prev;

    free(temp);
}

void search()
{
    struct node *temp;
    int key, pos = 1;

    if (last == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = last->next;

    do
    {
        if (temp->data == key)
        {
            printf("Element found at position %d.\n", pos);
            return;
        }

        temp = temp->next;
        pos++;

    } while (temp != last->next);

    printf("Element not found!\n");
}

void display()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to head)\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- CIRCULAR LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Search\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: deleteBeginning(); break;
            case 4: deleteEnd(); break;
            case 5: search(); break;
            case 6: display(); break;
            case 7: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 7);

    /* Free all remaining nodes */
    if (last != NULL)
    {
        struct node *head = last->next;
        struct node *temp;

        last->next = NULL;

        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }

        last = NULL;
    }

    return 0;
}
