#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void Enqueue(int data)
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
    printf("\n--- Enqueuing is Successful ---");
}

void Dequeue()
{
    struct node *delNode = head;
    head = head->link;
    free(delNode);
}

void Display()
{
    struct node *curr = head;
    if (curr == NULL)
    {
        printf("\nThe queue is empty. Nothing to display. ");
        return;
    }
    printf("\nThe queue is : \n");
    while (curr != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->link;
    }
}

void main()
{
    int ch, element, popped;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Quit");

        printf("\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element you want to enqueue : \n");
            scanf("%d", &element);
            Enqueue(element);
            break;
        case 2:
            Dequeue();
            printf("Dequeing is Successful");
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nError, Input is wrong. Please try again.");
        }
    } while (ch != 4);
}
