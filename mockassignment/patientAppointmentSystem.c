#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Patient{
    int patient_id;
    char severity[10];
} patient;
typedef struct Node{
    patient pa;
    struct Node *next;
} node;
node *createNode(patient p)
{
    node *newNode=(node *)malloc(sizeof(node));
    if(newNode==NULL)
    {
        printf("memory allocation failed");
        return NULL;
    }
    newNode->pa.patient_id=p.patient_id;
    strcpy(newNode->pa.severity,p.severity);
    return newNode;
}

node *insertAtEnd(node *head,patient pa,node **tail)
{
    if(head==NULL)
    {
        head=createNode(pa);
        *tail=head;
        return head;
    }
    else
    {
        (*tail)->next=createNode(pa);
        (*tail)=(*tail)->next;
    }
    return head;
}

void printPaitent(node *head)
{
    node *iterator=head;
    while(iterator!=NULL)
    {
        printf("%d %s\n",iterator->pa.patient_id,iterator->pa.severity);
        iterator=iterator->next;
    }
}

int priority(char str[10])
{
    if(strcmp(str,"Critical")==0)
    return 3;
    if(strcmp(str,"Serious")==0)
    return 2;
    if(strcmp(str,"Stable")==0)
    return 1; 
}

void sortList(node *head)
{
   int swapped=1;
   while(swapped==1)
   {

    node *iterator=head;
    swapped=0;
    while(iterator->next!=NULL)
    {
    if(priority(iterator->pa.severity)<priority(iterator->next->pa.severity))
     {
        patient temp=iterator->pa;
      iterator->pa=iterator->next->pa;
      iterator->next->pa=temp;
      swapped=1;
     }
     iterator=iterator->next;
    }
   }
}
int main()
{
    int n;
    node *head=NULL;
    node *tail=NULL;
    patient pa;
    scanf("%d",&n);
    while(n<=0)
    {
        printf("number of patient cant be negative or zero, please reenter the number of patient\n");
        scanf("%d",&n);
    }
    for(int paNum=0;paNum<n;paNum++)
    {
        scanf("%d",&pa.patient_id);
        getchar();
        scanf("%s",pa.severity);
        head=insertAtEnd(head,pa,&tail);
    }  
    sortList(head);
    printPaitent(head);
    return 0;  

}
