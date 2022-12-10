#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;

void Push(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (top == NULL)
    {
        newNode->link = NULL;
        top = newNode;
        return;
    }
    else
    {
        newNode->link = top;
        top = newNode;
    }
}

int Pop()
{
    if (top == NULL)
    {
        printf("The stack is empty");
        return 0;
    }
    else
    {
        struct node *delNode = top;
        int data = delNode->data;
        top = top->link;
        free(delNode);
        return data;
    }
}

void display()
{
    struct node *curr = top;
    if (curr == NULL)
    {
        printf("List is empty. Nothing to Display");
        return;
    }
    printf("\nThe stack is : \n");
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
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Quit");

        printf("\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to push into the stack : ");
            scanf("%d", &element);
            Push(element);
            break;
        case 2:
            popped = Pop();
            printf("\nPopped Element is : %d ", popped);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Error, Input is wrong. Please try again.");
        }
    } while (ch != 4);
}
