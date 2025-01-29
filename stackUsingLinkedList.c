#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node *next;
} node;

typedef struct Stack{
    node *head;
} stack;

stack sta;
void insertAtBeginning(int value)
{
    node *newNode=(node *)malloc(sizeof(node));
    if(newNode==NULL)
    {
        printf("error:no memory available");
        return;
    }
    newNode->val=value;
    newNode->next=NULL;
    if(sta.head==NULL)
    {
       sta.head=newNode;
       return;
    }
    newNode->next=sta.head;
    sta.head=newNode;
    printf("push operation successful");

}
void push(int val)
{
     insertAtBeginning(val);
     return;
}

void pop()
{
    if(sta.head==NULL)
    {
        printf("stack is already empty");
        return ;
    }
    node * deleted=sta.head;
    sta.head=sta.head->next;
    printf("%d deleted successfully",deleted->val);
    free(deleted);
    return;

}

int peek()
{
    if(sta.head==NULL)
    {
        printf("stack is empty");
        return -1;
    }
    return sta.head->val;
}

int isEmpty()
{
      return sta.head==NULL;
}

int size()
{
    int si=0;
    node *ptr=sta.head;
    while(ptr!=NULL)
    {
        si++;
        ptr=ptr->next;
    }
    return si;
}
int main()
{

sta.head=NULL;
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
