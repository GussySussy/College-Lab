#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void insertAtBeginning(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = head;
    head = newNode;

    printf("\n--- Insertion is successfull ---");
}

void insertAtEnd(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    struct node *end = head;

    if (end != NULL)
    {
        while (end->link != NULL)
        {
            end = end->link;
        }
        end->link = newNode;
    }
    else
    {
        head = newNode;
    }
    printf("\n--- Insertion is successful ---");
}

void insertAfterPosition(int pos, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    struct node *curr = head;
    while (curr != NULL && --pos)
    {
        curr = curr->link;
    }
    if (curr == NULL)
    {
        printf("\nposition exceeds the size of the list");
    }
    else
    {
        newNode->link = curr->link;
        curr->link = newNode;
    }
}

void deleteByValue(int value)
{
    struct node *curr = head, *prev = NULL;
    while (curr != NULL && curr->data != value)
    {
        prev = curr;
        curr = curr->link;
    }
    if (prev == NULL)
    {
        head = head->link;
    }
    else if (curr == NULL)
    {
        printf("\nElement not found in the List");
    }
    else
    {
        prev->link = curr->link;
    }
    free(curr);
    printf("\nDeletion Successfull");
}

void display()
{
    struct node *curr = head;
    if (curr == NULL)
    {
        printf("\nList empty");
    }
    else
    {
        while (curr != NULL)
        {
            printf("%d\t", curr->data);
            curr = curr->link;
        }
    }
}

void main()
{
    int ch, element, pos;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Delete element with a given value ");
        printf("\n5. Display linked list");
        printf("\n6. Quit");

        printf("\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAtBeginning(element);
            break;
        case 2:
            printf("\nEnter element to insert  ");
            scanf("%d", &element);
            insertAtEnd(element);
            break;
        case 3:
            printf("\nEnter the position after which struct node will be inserted ");
            scanf("%d", &pos);
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAfterPosition(pos, element);
            break;
        case 4:
            printf("\nEnter element to delete ");
            scanf("%d", &element);
            deleteByValue(element);
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        }
    } while (ch != 6);
}