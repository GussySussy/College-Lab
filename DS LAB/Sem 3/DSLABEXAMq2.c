// to create two linked list,
// find their intersection and union,
// and sort the union linked list using selection
// without the help of array

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *ll1 = NULL, *ll2 = NULL, *interhead = NULL, *unionhead = NULL;

void addAtEnd(node **head, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    struct node *end = *head;

    if (end != NULL)
    {
        while (end->next != NULL)
        {
            end = end->next;
        }
        end->next = newNode;
    }
    else
    {
        *head = newNode;
    }
}

void display(node **head)
{
    node *curr = *head;
    if (curr == NULL)
    {
        printf("\nList empty");
    }
    else
    {
        printf("\n");
        while (curr != NULL)
        {
            printf("%d->", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

void main()
{
    int n1, n2, x;

    printf("\nEnter the number of elements of the first linked list : ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("\nEnter the element : ");
        scanf("%d", &x);
        addAtEnd(&ll1, x);
        addAtEnd(&unionhead, x);
    }
    display(&ll1);

    printf("\nEnter the number of elements of the second linked list : ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("\nEnter the element : ");
        scanf("%d", &x);
        addAtEnd(&ll2, x);
    }
    display(&ll2);

    node *curr1 = ll1, *curr2 = ll2;
    while (curr1 != NULL)
    {
        while (curr2 != NULL)
        {
            if (curr1->data == curr2->data)
            {
                addAtEnd(&interhead, curr1->data);
            }
            curr2 = curr2->next;
        }
        curr2 = ll2;
        curr1 = curr1->next;
    }
    display(&interhead);

    curr1 = interhead;
    while (curr2 != NULL)
    {
        while (curr1 != NULL)
        {
            if (curr1->data != curr2->data)
            {
                addAtEnd(&unionhead, curr2->data);
            }
            curr1 = curr1->next;
        }
        curr1 = interhead;
        curr2 = curr2->next;
    }
    display(&unionhead);

    curr1 = unionhead;
    while (curr1)
    {
        node *min = curr1;
        node *iter = curr1->next;

        while (iter)
        {
            if (iter->data < min->data)
            {
                min = iter;
            }
            iter = iter->next;
        }

        int x = curr1->data;
        curr1->data = min->data;
        min->data = x;
        curr1 = curr1->next;
    }
    printf("\nAfter sorting : \n");
    display(&unionhead);
}