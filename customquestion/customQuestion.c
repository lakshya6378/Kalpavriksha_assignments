// Problem Statement
// You are given a singly linked list of integers and an integer k. 
// Your task is to process the linked list based on the following rules:
// Starting from the head of the linked list, consider the next k elements (or fewer if fewer elements remain).
// Among these k elements:
// Find the minimum number.
// If the minimum number is less than or equal to k, reverse the selected k elements starting from the current position. Continue processing the list from the next node after the reversed section.
// If the minimum number is greater than k, sort the k elements in decreasing order and resume processing the list from the next node after this section.
// Continue this process until the entire linked list is processed.
// Examples and Test Cases
// Test Case 1
// Input:
// Linked List: 5 -> 1 -> 3 -> 8 -> 2 -> 7 -> 6 -> 4
// k = 3

// Processing Steps:

// Consider the first k = 3 elements: 5, 1, 3.

// The minimum number is 1, which is less than or equal to k (3).
// Reverse the first 3 elements: 3 -> 1 -> 5 -> 8 -> 2 -> 7 -> 6 -> 4.
// Start processing from the next node (8).
// Consider the next k = 3 elements: 8, 2, 7.

// The minimum number is 2, which is less than or equal to k (3).
// Reverse the 3 elements: 3 -> 1 -> 5 -> 7 -> 2 -> 8 -> 6 -> 4.
// Consider the next k = 3 elements: 6, 4.

// Fewer than k = 3 elements remain, and the minimum number is 4, which is greater than k (3).
// Sort the elements in decreasing order: 3 -> 1 -> 5 -> 7 -> 2 -> 8 -> 6 -> 4.
// Output:
// Modified Linked List: 3 -> 1 -> 5 -> 7 -> 2 -> 8 -> 6 -> 4

// Test Case 2
// Input:
// Linked List: 10 -> 2 -> 3 -> 1 -> 15 -> 8 -> 12
// k = 4

// Processing Steps:

// Consider the first k = 4 elements: 10, 2, 3, 1.

// The minimum number is 1, which is less than or equal to k (4).
// Reverse the 4 elements: 1 -> 3 -> 2 -> 10 -> 15 -> 8 -> 12.
// Start processing from the next node (15).
// Consider the next k = 4 elements: 15, 8, 12.

// Fewer than k = 4 elements remain, and the minimum number is 8, which is greater than k (4).
// Sort the elements in decreasing order: 1 -> 3 -> 2 -> 10 -> 15 -> 12 -> 8.
// Output:
// Modified Linked List: 1 -> 3 -> 2 -> 10 -> 15 -> 12 -> 8

// Test Case 3
// Input:
// Linked List: 7 -> 5 -> 9 -> 4 -> 2 -> 6 -> 8
// k = 2

// Processing Steps:

// Consider the first k = 2 elements: 7, 5.

// The minimum number is 5, which is greater than k (2).
// Sort the elements in decreasing order: 7 -> 5 -> 9 -> 4 -> 2 -> 6 -> 8.
// Consider the next k = 2 elements: 9, 4.

// The minimum number is 4, which is greater than k (2).
// Sort the elements in decreasing order: 7 -> 5 -> 9 -> 4 -> 2 -> 6 -> 8.
// Consider the next k = 2 elements: 2, 6.

// The minimum number is 2, which is less than or equal to k (2).
// Reverse the elements: 7 -> 5 -> 9 -> 4 -> 6 -> 2 -> 8.
// Remaining elements: 8.

// Fewer than k = 2 elements remain, no reversal or sorting.
// Output:
// Modified Linked List: 7 -> 5 -> 9 -> 4 -> 6 -> 2 -> 8







#include<stdio.h>
#include<stdlib.h>
typedef struct SinglyListNode
{
    int val;
    struct SinglyListNode *next;
} node;
 node *head=NULL;
 int success_flag=1;
 node *createNode(int val)
 {
    node *newNode=(node *)malloc(sizeof(node));
        newNode->val=val;
        newNode->next=NULL;
        return newNode;
 }
 void insertAtEnd(int value)
 {
    if(head==NULL)
    {
        head=createNode(value);
        return;
    }
    node *iterator=head;
    while(iterator->next!=NULL)
    {
        iterator=iterator->next;
    }
    iterator->next=createNode(value);
    if(iterator->next==NULL)
    {
        printf("error: memory allocation failed");
        success_flag=0;
        return;
    }
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
        printf("%d ",iterator->val);
        iterator=iterator->next;
    }
 }

node * reverse(node *iterator)
{
    node *curr=iterator,*prev=NULL;
    while(curr!=NULL)
    {
        node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void sort(node *iterator)
{
   int swapped=1;
    while(swapped==1)
    {
        node *ptr=iterator;
        swapped=0;
        while(ptr->next!=NULL)
        {
            if(ptr->val<ptr->next->val)
            {
                int temp=ptr->val;
                ptr->val=ptr->next->val;
                ptr->next->val=temp;
                swapped=1;
            }
            ptr=ptr->next;
        }
    }
}
void specialLinkedListOperation(int k)
 {
    node *iterator=head;
    node *prev=NULL;
    while(iterator!=NULL)
    {
        node *ptr=iterator;
        int currcount=0;
        int min=250;
        while(currcount<k-1&&ptr!=NULL)
        {
            if(ptr->val<min)
            min=ptr->val;
            ptr=ptr->next; 
            currcount++;
        }
        node *nextptr = (ptr != NULL) ? ptr->next : NULL;
        if(min<=k)
        {
            if(ptr!=NULL)
           ptr->next=NULL;  
           if(prev!=NULL)
           {
            prev->next=reverse(iterator);
           }
           else
           head=reverse(iterator);
           iterator->next=nextptr;
           prev=iterator;
        }
        else
        {
            if(ptr!=NULL)
            ptr->next=NULL;
            sort(iterator);
           node *temp = iterator;
          while (temp->next != NULL)
           {
          temp = temp->next;
           }
           temp->next = nextptr; // Correctly reconnect the rest of the list
           prev = temp;  
        }
        iterator=prev->next;
    }
 }
int main()
{
    int num=0,k;
    while(scanf("%d",&num)==1)
    {
        insertAtEnd(num);
        if(getchar()=='\n')
        break;
    }
    scanf("%d",&k);
   
   specialLinkedListOperation(k);
    display();
    

    return 0;
}