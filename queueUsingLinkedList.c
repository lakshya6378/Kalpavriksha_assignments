#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node *next;
} node;
node *createNode(int val)
{
    node *newNode=(node *)malloc(sizeof(node)); 
    if(newNode==NULL)
    {
        printf("overflow no memory available");
        return NULL;
    }
    newNode->val=val;
    newNode->next=NULL;
}
typedef struct queue{
    node *head;
    node *rear;
} Queue;
Queue qu;
void enqueue(int val)
{
    node *newNode=createNode(val);
    if(newNode==NULL)
    {
        return;
    }
    if(qu.head==NULL)
    {
        qu.head=newNode;
        qu.rear=newNode;
    }
    else
    {
        (qu.rear)->next=newNode;
        qu.rear=(qu.rear)->next;
    }
    printf("%d inserted successfully",val);
}

void dequeue()
{
    if(qu.head==NULL)
    {
        printf("queue is already empty");
        return;
    }
    int val=(qu.head)->val;
    node *deleted=qu.head;
    if(qu.head==qu.rear)
    {
        qu.head=NULL;
        qu.rear=NULL;
    }
    else
    qu.head=(qu.head)->next;
    free(deleted);
    printf("%d is deleted successfully",val);
}
int isEmpty()
{
    return qu.head==NULL;
}
int peek()
{
    if(isEmpty())
    {
        printf("queue is empty");
        return -1;
    }
    return (qu.head)->val;
}
int size()
{
    if(isEmpty())
    return 0;
    node *iterator=qu.head;
    int count=0;
    while(iterator!=NULL)
    {
        count++;
        iterator=iterator->next;
    }
    return count;
}
int main()
{
    qu.head=NULL;
    qu.rear=NULL;
    int choice=0;
    int value;
    do 
    {
        printf("\nenter a operation to perform\n");
        printf("1. enter 1 for enqueue operation\n");
        printf("2.enter 2 for dequeue operation\n");
        printf("3.enter 3 for peek operation\n");
        printf("4.enter 4 for checking queue is empty or not\n");
        printf("5.enter 5 for check queue size\n");
        printf("6.enter 6 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                  printf("enter a value");
                  scanf("%d",&value);
                  enqueue(value);
                  break;
            case 2:
                dequeue();
                break;
            case 3:
                 value=peek();
                 printf("%d",value);
                 break;
            case 4:
                value=isEmpty();
                if(value==1)
                printf("queue is empty");
                else
                printf("queue is not empty");
            break;
            case 5:
                value=size();
                printf("size of queue is %d",value);
                break;
            case 6:
                printf("terminating the program...");
                break;
            default:
               printf("enter a valid choice");
               break;

        }
    }while(choice!=6);
    
}