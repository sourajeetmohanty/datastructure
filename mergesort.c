#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int start,int mid,int end)
{
    int i,j,k;
    int n1=mid-start+1;
    int n2=end-mid;

    int l[n1],r[n2];

    for(i=0;i<n1;i++)
      l[i]=arr[start+i];

    for(j=0;j<n2;j++)
      r[j]=arr[mid+1+j];

    i=0;
    j=0;
    k=start;
    while(i<n1&&j<n2)
    {
        if(l[i]<=r[j])
        {
            arr[k]=l[i];
            i++;
        }
        else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=r[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int start, int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
void display(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void main()
{
    int arr[]={9,3,7,5,6,4,8,2};
    int arr_size=sizeof(arr)/sizeof(arr[0]);
    printf("Given array is:\n");
    display(arr,arr_size);
    mergesort(arr,0,arr_size-1);
    printf("Sorted array is:\n");
    display(arr,arr_size);
}
