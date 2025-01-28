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

void swap(int *num1,int *num2)
{
    int temp=*num1;
                    *num1=*num2;
                    *num2=temp;
}

void bubbleSort(int *arr,int len)
{
     int flag=0;
        for(int round=0;round<len-1;round++)
        {
            flag=0;
            for(int index=0;index<len-round-1;index++)
            {
                if(arr[index]>arr[index+1])
                {
                    swap(&arr[index],&arr[index+1]);
                    flag=1;
                }
            }
            if(flag==0)
            break;
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
        bubbleSort(arr,len);
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