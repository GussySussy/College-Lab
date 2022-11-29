#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct node *link;
} node;

*head = NULL;

void insertAtBeginning(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->link = head;
    head = newNode;

    printf("--- Insertion is successfull ---");
}

void insertAtEnd(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    node *end = head;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (end->link != NULL)
        {
            end = end->link;
        }
        end->link = newNode;
    }
    printf("--- Insertion is successful ---");
}

void insertAfterValue(int pos, int data)
{
    node *newNode = (node *)malloc(sizeof(node));
}
