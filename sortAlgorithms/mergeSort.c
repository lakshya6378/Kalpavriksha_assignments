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

void merge(int *arr,int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int *arr1=(int *)malloc(sizeof(int)*n1);
    int *arr2=(int *)malloc(sizeof(int)*n2);
    for(int i=0;i<n1;i++)
    arr1[i]=arr[low+i];
    for(int i=0;i<n2;i++)
    arr2[i]=arr[mid+1+i];
   int arr1Start=0,arr2Start=0;
   int arrlow=low;
   while(arr1Start<n1&&arr2Start<n2)
   {
    if(arr1[arr1Start]<arr2[arr2Start])
    arr[arrlow++]=arr1[arr1Start++];
    else
    arr[arrlow++]=arr2[arr2Start++];
   }
   while(arr1Start<n1)
   arr[arrlow++]=arr1[arr1Start++];
   while(arr2Start<n2)
   arr[arrlow++]=arr2[arr2Start++];
    free(arr1);
    free(arr2);
}
void mergeSort(int *arr,int low,int high)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
        mergeSort(arr,0,len-1);
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