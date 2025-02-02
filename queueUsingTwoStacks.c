#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 1000
typedef struct Stack{
    int st[MAX_STACK_SIZE];
    int top;
} stack;
void push(stack *sta,int val)
{
    if(sta->top==MAX_STACK_SIZE-1)
    {
        printf("stack is full, push is not possible");
        return ;
    }
    sta->top++;
    sta->st[sta->top]=val;
}

void pop(stack *sta)
{
    if(sta->top==-1)
    {
        printf("stack is already empty");
        return ;
    }
    sta->top--;
    return;

}

int peekS(stack *sta)
{
    if(sta->top==-1)
    {
        printf("stack is empty");
        return -1;
    }
    return sta->st[sta->top];
}

int isSEmpty(stack *sta)
{
      return sta->top==-1;
}

int sizeS(stack *sta)
{
    return sta->top+1;
}
typedef struct queue{
    stack sta1,sta2;
} Queue;
Queue qu;
void InsertAtBottomStack(stack *sta,int val)
{
    if(isSEmpty(sta))
    {
         push(sta,val);
         return;
    }
    int value=peekS(sta);
    pop(sta);
    InsertAtBottomStack(sta,val);
    push(sta,value);
}
void enqueue(int val)
{
    if(sizeS(&qu.sta2)==MAX_STACK_SIZE)
    {
        printf("cant insert queue is full");
        return;
    }
    push(&qu.sta2,val);
    printf("%d inserted successfully",val);
}

void dequeue()
{
    if(isSEmpty(&qu.sta1)&&isSEmpty(&qu.sta2))
    {
        printf("queue is already empty");
        return;
    }
    if(isSEmpty(&qu.sta1))
    {
         while(!isSEmpty(&qu.sta2))
        {
              int val=peekS(&qu.sta2);
             pop(&qu.sta2);
             push(&qu.sta1,val);
        }
    
    }
    int val=peekS(&qu.sta1);
    pop(&qu.sta1);
    printf("%d is deleted successfully",val);
    
}
int isEmpty()
{
    return isSEmpty(&qu.sta1)&&isSEmpty(&qu.sta2);
}
int peek()
{
    if( isSEmpty(&qu.sta1)&&isSEmpty(&qu.sta2))
    {
        printf("queue is empty");
        return -1;
    }
    if(isSEmpty(&qu.sta1))
    {
         while(!isSEmpty(&qu.sta2))
        {
              int val=peekS(&qu.sta2);
             pop(&qu.sta2);
             push(&qu.sta1,val);
        }
    
    }
    int val=peekS(&qu.sta1);
    return val;
}
int size()
{
    if(isSEmpty(&qu.sta1)&&isSEmpty(&qu.sta2))
    return 0;
    return sizeS(&qu.sta1)+sizeS(&qu.sta2);
}
int main()
{
    qu.sta1.top=-1;
    qu.sta2.top=-1;
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