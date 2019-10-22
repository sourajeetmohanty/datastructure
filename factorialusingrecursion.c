#include<stdio.h>
#include<stdlib.h>
void main()
{int n;
printf("Enter the number:");
    scanf("%d",&n);

int x=factorial(n);
printf("%d",x);
}
int factorial(int x)
{
    if(x==1)
    return 1;

    return x*factorial(x-1);
}
