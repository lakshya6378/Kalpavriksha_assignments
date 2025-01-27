#include<stdio.h>
#include<stdlib.h>
int binarySearch(int *arr,int len,int key)
{
    int mid=0;
    int low=0;
    int high=len-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key)
          return mid;
        if(arr[mid]>key)
          high=mid-1;
        else
        low=mid+1;

        
    }
    return -1;
}
int main()
{
    int *arr=(int *)malloc(sizeof(int)*(1e5));
    int num=0;
    int key=0;
    int len=0;
    int KeyIndex=-1;
    if(arr!=NULL)
    {
        printf("enter the array elements in increasing order\n");
        while(scanf("%d",&num)==1)
        {
            arr[len]=num;
            len++;
            if(getchar()=='\n')
            break;   
        }
        printf("enter the key element\n");
        scanf("%d",&key);
        KeyIndex=binarySearch(arr,len,key);
        if(KeyIndex==-1)
        {
            printf("key is not found");
        }
        else
        {
            printf("key found at index(0-based) %d",KeyIndex);
        }
        if(len!=0)
        free(arr);
    }
    else
    {
        printf("error:memory allocation failed");
    }
}