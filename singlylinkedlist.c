#include<stdio.h>
#include<stdlib.h>
typedef struct SinglyListNode
{
    int val;
    struct SinglyListNode *next;
} node;
 node *head=NULL;
 int success_flag=1;
 void insertAtBeginning(int value)
 {
    if(head==NULL)
    {
        head=(node *)malloc(sizeof(node));
        head->val=value;
        head->next=NULL;
        return;
    }
    node *tempNode=(node *)malloc(sizeof(node));
    if(tempNode==NULL)
    {
        printf("error:memory allocation failed");
        success_flag=0;
        return;
    }
    tempNode->val=value;
    tempNode->next=head;
    head=tempNode;
 }

 void insertAtEnd(int value)
 {
    if(head==NULL)
    {
        head=(node *)malloc(sizeof(node));
        head->val=value;
        head->next=NULL;
        return;
    }
    node *iterator=head;
    while(iterator->next!=NULL)
    {
        iterator=iterator->next;
    }
    iterator->next=(node *)malloc(sizeof(node));
    if(iterator->next==NULL)
    {
        printf("error: memory allocation failed");
        success_flag=0;
        return;
    }
    iterator->next->val=value;
    iterator->next->next=NULL;
 }

 void inserrtAtPosition(int position,int value)
 {
    if(position<1)
    {
       printf("error:invalid position number");
       success_flag=0;
       return;
    }
    if(position==1)
    {
        insertAtBeginning(value);
        return;
    }
    node *iterator=head;
    int count=0;
    while(iterator!=NULL&&count<position-2)
    {
        iterator=iterator->next;
        count++;
    }
    if(iterator==NULL&&count!=position-2)
    {
        printf("error: position is out of range");
        success_flag=0;
        return;
    }
    node *temp=(node *)malloc(sizeof(node));
    temp->val=value;
    temp->next=NULL;
    temp->next=iterator->next;
    iterator->next=temp;
 }

 void display()
 {
    node *iterator=head;
    if(iterator==NULL)
    {
        printf("nothing to print");
        return;
    }
    while(iterator!=NULL)
    {
        printf("%d",iterator->val);
        iterator=iterator->next;
    }
 }

 void updateAtPosition(int position,int value)
 {
    if(position<1)
    {
       printf("error:invalid position number");
       success_flag=0;
       return;
    }
    node *iterator=head;
    int count=1;
    while(iterator!=NULL&&count<position)
    {
        iterator=iterator->next;
        count++;
    }
    if(iterator==NULL&&count!=position)
    {
        printf("error: position is out of range");
        success_flag=0;
        return;
    }
    iterator->val=value;
 }

 void deleteAtBeginning()
 {
    if(head==NULL)
    {
        printf("nothing to delete");
        return ;
    }
    node *deleted=head;
    head=head->next;
    free(deleted);
 }

 void deleteAtEnd()
 {
    if(head==NULL)
    {
        printf("nothing to delete");
        return;
    }
    node *iterator=head;
   node *   prev=NULL;
    while(iterator->next!=NULL)
    {
        prev=iterator;
        iterator=iterator->next;
    }
    prev->next=NULL;
    free(iterator);
 }

 void deleteAtPosition(int position)
 {
    if(head==NULL)
    {
        printf("nothing to delete");
        return;
    }
    if(position<=0)
    {
        printf("invalid position");
        success_flag=0;
        return;
    }
    if(position==1)
    {
        deleteAtBeginning();
        return;
    }
    int count=1;
    node *iterator=head;
    while(iterator!=NULL&&count<position)
    {
        iterator=iterator->next;
        count++;
    }
    if((iterator==NULL&&count!=position)||(iterator->next==NULL))
    {
        printf("error: position is out of range");
        success_flag=0;
        return ;
    }
    node *deleted=iterator->next;
    iterator->next=iterator->next->next;
    free(deleted);
 }
int main()
{
    int n;
    printf("enter number of operations to be performed :  ");
    scanf("%d",&n);   
    while(n<0)
    {
        printf("number of operations should be positive or zero\n");
        printf("enter number of operations to be performed :  ");
        scanf("%d",&n);
    }
    while(n!=0)
    {
        int operation_number=0;
        scanf("%d",&operation_number);
        int value=0,position=0;
        success_flag=1;
        switch(operation_number)
        {
            case 1:
            scanf("%d",&value);
            insertAtEnd(value);
            break;
            case 2:
            scanf("%d",&value);
            
            insertAtBeginning(value);
            break;
            case 3:
            scanf("%d %d",&position,&value);
            inserrtAtPosition(position,value);
            break;
            case 4:
            display();
            break;
            case 5:
            scanf("%d %d",&position,&value);
            updateAtPosition(position,value);
            break;
            case 6:
            deleteAtBeginning();
            break;
            case 7:
            deleteAtEnd();
            break;
            case 8:
            scanf("%d",&position);
            deleteAtPosition(position);
            break;
            default:
            printf("Not a valid operation Number");
            success_flag=0;
            break; 
        }
        if(success_flag==0)
        {
            break;
        }
        n--;
    }



}