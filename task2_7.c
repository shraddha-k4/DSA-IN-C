
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* createNode(int c, int e) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    return newNode;
}

void insert(struct Node** head, int c, int e) {
    if (c == 0)
        return;

    struct Node* newNode = createNode(c, e);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            insert(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            insert(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else {
            insert(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insert(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insert(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void display(struct Node* poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);

        if (poly->next != NULL)
            printf(" + ");

        poly = poly->next;
    }

    printf("\n");
}

int main() {
    struct Node *p1 = NULL, *p2 = NULL, *result = NULL;
    int n, c, e, i;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent in descending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &c, &e);
        insert(&p1, c, e);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent in descending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &c, &e);
        insert(&p2, c, e);
    }

    printf("\nFirst polynomial: ");
    display(p1);

    printf("Second polynomial: ");
    display(p2);

    result = addPoly(p1, p2);

    printf("Resultant polynomial: ");
    display(result);

    return 0;
}
