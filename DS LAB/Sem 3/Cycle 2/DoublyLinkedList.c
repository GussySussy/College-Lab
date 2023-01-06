#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

typedef struct node node;

node *head = NULL, *tail = NULL;

void insertAtBeginning(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    node *current = head;
    if (current != NULL)
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail=newNode;
    }
    else
    {
        newNode->prev = NULL;    
        head=newNode;
        tail=newNode;
    }
}

void deleteByPos(int pos){
    if(head==NULL){
        printf("\nList is empty\n");
        return;
    }
    else{
        node *curr = head;
        for(int i =0;i<pos;i++){
            curr=curr->next;
        }
        if(pos==1){
            curr->next->prev=NULL;
            curr->next=NULL;
            free(curr);
        }
        else if(curr->next==NULL){
            curr->prev->next=NULL;
            curr->prev=NULL;
            free(curr);
        }
        else{
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            curr->next=NULL;
            curr->prev=NULL;
            free(curr);
        }
    }
}