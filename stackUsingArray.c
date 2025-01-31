#include<stdio.h>
#define MAX_STACK_SIZE 1000
typedef struct Stack{
    int st[MAX_STACK_SIZE];
    int top;
} stack;
stack sta;
int success_flag=1;
void push(int val)
{
    if(sta.top==MAX_STACK_SIZE-1)
    {
        printf("stack is full, push is not possible");
        return ;
    }
    sta.top++;
    sta.st[sta.top]=val;
    printf("push operation successed");
}

void pop()
{
    if(sta.top==-1)
    {
        printf("stack is already empty");
        return ;
    }
    int deleted=sta.st[sta.top];
    sta.top--;
    printf("%d deleted successfully",deleted);
    return;

}

int peek()
{
    if(sta.top==-1)
    {
        printf("stack is empty");
        return -1;
    }
    return sta.st[sta.top];
}

int isEmpty()
{
      return sta.top==-1;
}

int size()
{
    return sta.top+1;
}
int main()
{

sta.top=-1;
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