#include<stdio.h>
#include<stdlib.h>
int *generateInput(int *len)
{
    int *arr=(int *)malloc(sizeof(int)*(1e5));
    int index=0;
    if(arr!=NULL)
    {
        printf("enter the array elements\n");
        int num=0;
        while(scanf("%d",&num)==1)
        {
            arr[index]=num;
            index++;
            if(getchar()=='\n')
            break;
        }
        *len=index;
        return arr;
    }
    return NULL;
}

void printArray(int *arr,int len)
{
    for(int index=0;index<len;index++)
    {
        printf("%d ",arr[index]);
    }
}

void insertionSort(int *arr,int len)
{
     for(int index=0;index<len;index++)
        {
            int element=arr[index];
            int j=index-1;
            while(j>=0&&arr[j]>element)
            {
                
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=element;
        }
}
int main()
{
    int *arr=NULL;
    int len=0;
    arr=generateInput(&len);
    if(arr!=NULL)
    {
        printf("\n array elements before sorting\n");
        printArray(arr,len);
        insertionSort(arr,len);
        printf("\n array elements after sorting\n");
        printArray(arr,len);
        if(len!=0)
        free(arr);
    }
    else
    {
        printf("error:memory allocation failure");
    }
}