#include<stdio.h>
#define MAX_STACK_SIZE 1000
# define MAX_SIZE 100
typedef struct queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;
void enqueue(Queue *qu,int val)
{
    if(qu->rear==MAX_SIZE-1)
    {
        printf("cant insert queue is full");
        return;
    }
    qu->arr[++(qu->rear)]=val;
    if(qu->front==-1)
    qu->front=0;
}

void dequeue(Queue *qu)
{
    if(qu->front==-1)
    {
        printf("queue is already empty");
        return;
    }
    int val=qu->arr[qu->front];
    if(qu->front==qu->rear)
    {
        qu->front=-1;
        qu->rear=-1;
    }
    else
    ++(qu->front);
}
int isQEmpty(Queue *qu)
{
    return qu->front==-1;
}
int peekQ(Queue *qu)
{
    if(isQEmpty(qu))
    {
        printf("queue is empty");
        return -1;
    }
    return qu->arr[qu->front];
}
int sizeQ(Queue *qu)
{
    if(isQEmpty(qu))
    return 0;
    return qu->rear-qu->front+1;
}
typedef struct Stack{
    Queue qu;
} stack;
stack sta;
int success_flag=1;
void push(int val)
{
    if(sizeQ(&sta.qu)==MAX_SIZE)
    {
        printf("stack is full, push is not possible");
        return ;
    }
    enqueue(&sta.qu,val);
    int size=sizeQ(&sta.qu)-1;
    while(size--)
    {
        int value=peekQ(&sta.qu);
        dequeue(&sta.qu);
        enqueue(&sta.qu,value);
    }
    printf("push operation successed");
}

void pop()
{
    if(isQEmpty(&sta.qu))
    {
        printf("stack is already empty");
        return ;
    }
    int val=peekQ(&sta.qu);
    dequeue(&sta.qu);
    printf("%d deleted successfully",val);
}

int peek()
{
    if(isQEmpty(&sta.qu))
    {
        printf("stack is empty");
        return -1;
    }
    return peekQ(&sta.qu);
}

int isEmpty()
{
      return isQEmpty(&sta.qu);
}

int size()
{
    return sizeQ(&sta.qu);
}
int main()
{
sta.qu.front=-1;
sta.qu.rear=-1;
  int choice=6;

    do
    {
        int value;
        printf("\nselect a operation to perform\n");
        printf("1.enter 1 for push operation\n 2. enter 2 for pop operation\n 3. enter 3 for finding peek of stack\n 4. enter 4 for check if stack is empty or not\n5. enter 5 for size of stack\n6. enter 6 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:
                  printf("enter a number \n");
                  scanf("%d",&value);
                  push(value);
                  break;
          case 2:
                  pop();
                  break;
          case 3:
                  value=peek();
                  printf("%d",value);
                  break;
          case 4:
                  value=isEmpty();
                  if(value==1)
                  {
                    printf("stack is empty");
                  }
                  else 
                  {
                    printf("stack is not empty");
                  }
                  break;
          case 5:
                 int value=size();
                 printf("%d",value);
                 break;
          case 6:
                 printf("exiting from program.....");
                 break;
          default:
               printf("please enter a valid choice");
          
        }

    }
    while(choice!=6);
}