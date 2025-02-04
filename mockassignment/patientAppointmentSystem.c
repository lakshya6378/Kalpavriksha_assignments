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
    return 0;
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

int isValid(char *num)
{
    int len=strlen(num);
    for(int i=0;i<len;i++)
    {
        if(num[i]<'0'||num[i]>'9')
        return 0;
    }
    return 1;
}

int stoI(char *num)
{
int len=strlen(num);
int n=0;
    for(int  index=0;index<len;index++)
    {
        n=n*10+num[index]-'0';
    }
    return n;
}
int main()
{
    char num[100];
    node *head=NULL;
    node *tail=NULL;
    patient pa;
    int *PatientIds=(int *)malloc(sizeof(int)*2);
    int count=0;
    int size=2;
    int valid=0;

    printf("enter the number of patients.\n");
    scanf("%[^\n]s",num);
    valid=isValid(num);
   
    while(!valid)
    {
        printf("please enter some valid number of patients\n");
        getchar();
         scanf("%[^\n]s",num);
         valid=isValid(num);
    }
    int n=stoI(num);
    
    for(int paNum=0;paNum<n;paNum++)
    {
        scanf("%d",&pa.patient_id);
        getchar();
        scanf("%s",pa.severity);
        int pat=0;
        int flag=0;
        for(pat=0;pat<count;pat++)
        {
            if(PatientIds[pat]==pa.patient_id)
            {
                printf("patient id cant be same for two patients. please reenter patient id\n");
                paNum--;
                flag=1;
                break;
                

            }
        }
        if(flag==1)
        continue;

         if(!priority(pa.severity))
        {
            printf("severity can have values Critical or Serious or Stable.please reenter patient details\n");
            paNum--;
            continue;
        }

        if(pat==count)
        {
            if(count<size)
            {
                size=size*2;
                PatientIds=(int *)realloc(PatientIds,sizeof(int)*size);
            }
             PatientIds[count]=pa.patient_id;
             count++;
        }
       
        head=insertAtEnd(head,pa,&tail);
    }  
    sortList(head);
    printPaitent(head);
    return 0;  

}
