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

int partition(int *nums,int low,int high)
 {
    int i=low;
    int j=high;
    int pivot=nums[low];
    while(i<j)
    {
        while(nums[i]<=pivot&&i<=high-1)
        i++;
        while(nums[j]>pivot&&j>=low+1)
        j--;
        if(i<j)
        {
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }

    }
    int temp=nums[low];
    nums[low]=nums[j];
    nums[j]=temp;
    return j;
 }
 void quickSort(int *nums,int low,int high)
 {
    if(low<high)
    {
        int index=partition(nums,low,high);
        quickSort(nums,low,index-1);
        quickSort(nums,index+1,high);
    }
 }

void printArray(int *arr,int len)
{
    for(int index=0;index<len;index++)
    {
        printf("%d ",arr[index]);
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
        printf("\n array elements after sorting\n");
        quickSort(arr,0,len-1);
        printArray(arr,len);
        if(len!=0)
        free(arr);
    }
    else
    {
        printf("error:memory allocation failure");
    }
}