#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    int j;

    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int p1=partition(arr,low,high);
        quicksort(arr,low,p1-1);
        quicksort(arr,p1+1,high);
    }
}
void printarray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
       printf("%d ",arr[i]);
}
void main()
{
    int arr[]={10,16,8,12,15,6,3,9,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    printf("Sorted array:");
    printarray(arr,n);
}
