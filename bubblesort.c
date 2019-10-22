#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int i,a[n];
    printf("Enter the elements of  the array:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int p=0,temp;
    while(p<n-1)
    { i=0;
        while(i<n-p-1)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
            i++;
        }
        p++;
    }
    printf("Sorted array is:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
