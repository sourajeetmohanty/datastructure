#include<stdio.h>
#include<stdlib.h>
struct STACK
{
   int info;
   struct STACK *next;
};
struct STACK *top=NULL;
void main()
{
    int n,i;
    printf("Enter the number:");
    scanf("%d",&n);
    for(i=n;i>=1;i--)
        push(i);
    int factorial=1;
    struct STACK *temp=top;
    while(top!=NULL)
    {
        factorial*=top->info;
        pop();
    }
    printf("%d",factorial);
}
void push(int x)
{
  struct STACK *curr;
  curr=(struct STACK*)malloc(sizeof(struct STACK));

  if(curr==NULL)
  {
      printf("\nOut of memory");
      exit(1);
  }

  curr->info=x;
  curr->next=top;
  top=curr;
}
void pop()
{
    struct STACK *curr=top;
    if(curr==NULL)
    {
        printf("stack is empty.");
        exit(1);
    }
    top=curr->next;
    free(curr);
}
