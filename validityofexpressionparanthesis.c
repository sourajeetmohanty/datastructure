#include<stdio.h>
#include<stdlib.h>
struct STACK
{
   char info;
   struct STACK *next;
};
struct STACK *top=NULL;
void main()
{
    int i;
    char exp[100];
    printf("enter the expression:");
    scanf("%s",&exp);
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);

        if(exp[i]==')')
        {
            if(top==NULL)
            {
                printf("\nINVALID EXPRESSION first");
                exit(1);
            }
            else
                pop();
        }
    }
    if(top==NULL)
        printf("\nVALID EXPRESSION");
    else{
        printf("\nINVALID EXPRESSION last");
        exit(1);
    }
}
void push( char x)
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
