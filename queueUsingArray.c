#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
typedef struct queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;
Queue qu;
void enqueue(int val)
{
    if(qu.rear==MAX_SIZE-1)
    {
        printf("cant insert queue is full");
        return;
    }
    qu.arr[++qu.rear]=val;
    if(qu.front==-1)
    qu.front=0;
    printf("%d inserted successfully",val);
}

void dequeue()
{
    if(qu.front==-1)
    {
        printf("queue is already empty");
        return;
    }
    int val=qu.arr[qu.front];
    if(qu.front==qu.rear)
    {
        qu.front=-1;
        qu.rear=-1;
    }
    else
    ++qu.front;
    printf("%d is deleted successfully",val);
}
int isEmpty()
{
    return qu.front==-1;
}
int peek()
{
    if(isEmpty())
    {
        printf("queue is empty");
        return -1;
    }
    return qu.arr[qu.front];
}
int size()
{
    if(isEmpty())
    return 0;
    return qu.rear-qu.front+1;
}
int main()
{
    qu.front=-1;
    qu.rear=-1;
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