// take a user input number, store each figit to a linked list,
// add the adjacent nodes and input the sum to another linked list
// and print that particular linked list


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *numshead = NULL, *sumhead = NULL;

void addAtBeginning(node **head,int data){
    node *newNode=(node *)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=*head;
    *head=newNode;
}

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
    }
}



void main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    while(num!=0){
        addAtBeginning(&numshead,(num%10));
        num/=10;
    }
    display(&numshead);
    node* curr = numshead;
    while(curr->next!=NULL){
        addAtEnd(&sumhead,(curr->data + curr->next->data));
        curr=curr->next;
    }
    display(&sumhead);
}