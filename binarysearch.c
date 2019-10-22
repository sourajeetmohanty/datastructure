#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int i,a[n];
    printf("Enter the elements of  the array:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int x;
    printf("\nEnter the value u want to search in the array:");
    scanf("%d",&x);
    int l=0,b=n-1;
    int mid;
     while(l<=b)
     {
         mid=(l+b)/2;
         if(a[mid]==x)
         {
             printf("Element found at:%d",mid+1);
             exit(1);
         }
         if(a[mid]>x)
            b=mid-1;
         if(a[mid]<x)
            l=mid+1;
     }
     printf("element not found!!!!!");
     qw
}
