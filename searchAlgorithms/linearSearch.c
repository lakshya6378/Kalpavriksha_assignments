#include<stdio.h>
#include<stdlib.h>
int linearSearch(int *arr,int len,int key)
{
    for(int index=0;index<len;index++)
    {
        if(arr[index]==key)
        {
            return index;
        }
    }
    return -1;
}
int main()
{
    int *arr=(int *)malloc(sizeof(int)*(1e6));
    if(arr!=NULL)
    {
       printf("enter the elements of array:\n");
    int num=0;
    int len=0;
    int key=0;
    while(scanf("%d",&num)==1)
    {
        arr[len]=num;
        len++;
        if(getchar()=='\n')
        break;
    
    }
    
    arr=(int *)realloc(arr,sizeof(int)*len);
    printf("enter the key\n");
    scanf("%d",&key);
    int keyIndex=-1;
    keyIndex=linearSearch(arr,len,key);
    if(keyIndex==-1)
    {
        printf("key not found");
    }
    else
    {
        printf("key found at index(0-based) %d",keyIndex);
    }
    if(len!=0)
    free(arr);
    }
    else
    {
        printf("error:memory allocation failure");
    }
    
}