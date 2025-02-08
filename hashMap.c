#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int key;
    int value;
    struct node *next;
} node;
const int hashSize=10;
node **hashMap=NULL;
void initializeHash()
{
    hashMap=(node **)malloc(sizeof(node *)*(hashSize));
    for(int index=0;index<hashSize;index++)
    hashMap[index]=NULL;
}

int hash(int key)
{
    return key%hashSize;
}

void insertInHash(int key,int value)
{
    int index=hash(key);
    node *head=hashMap[index];
    node *newNode=(node *)malloc(sizeof(node));
    newNode->key=key;
    newNode->value=value;
    newNode->next=NULL;
    if(head==NULL)
    {
       hashMap[index]=newNode;
    }
    else
    {
       newNode->next=head;
       hashMap[index]=newNode;
    }
}

void searchKey(int key)
{
    int index=hash(key);
    node *head=hashMap[index];
    while(head!=NULL)
    {
        if(head->key==key)
        {
            printf("Value: %d\n",head->value);
            return;
        }
    }
    printf("key not found\n");
}

void deleteKey(int key)
{
    int index=hash(key);
    node *head=hashMap[index];
    node *prev=NULL;
    while(head!=NULL)
    {
        if(head->key==key)
        {
            if(prev==NULL)
            {
                head=head->next;
                hashMap[index]=head;
                
    
            }
            else
            {
                prev->next=head->next;
               
            }
            printf("%d deleted successfully",key);
            return;
        }
        prev=head;
        head=head->next;
    }
    printf("key not found");
}

void displayHash()
{
   
    for(int index=0;index<hashSize;index++)
    {
        node *ptr=hashMap[index];
        if(ptr!=NULL)
        printf("\nIndex %d: ",index);
        while(ptr)
        {
            printf("(%d, %d)",ptr->key,ptr->value);
            if(ptr->next)
            printf(" -> ");
        ptr=ptr->next;
        }
    }
}
int main()
{
    initializeHash();
     int choice=0;
     do
     {
         printf("\n");
         printf("1. insert   2.search  3.delete  4.display  5.exit\n");
         printf("enter a choice :  ");
         scanf("%d",&choice);
         switch(choice)
         {
            case 1:
            {
                int key;
                int value;
                printf("enter the key : ");
                scanf("%d",&key);
                printf("enter the value : ");
                scanf("%d",&value);
                insertInHash(key,value);
                break;
            }
            case 2:
                 
                 {
                    int key;
                 printf("enter the key :");
                 scanf("%d",&key);
                 searchKey(key);
                 break;
                 }
            case 3:
                {
                     int key;
                 printf("enter the key :");
                 scanf("%d",&key);
                 deleteKey(key);
                 break;
                }
            case 4:
               displayHash();
               break;
            case 5:
               printf("exiting.....");
               break;
            default:
            printf("enter a valid choice");
            break;
         }

     }
     while(choice!=5);
}
