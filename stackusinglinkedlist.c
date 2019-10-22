#include<stdio.h>
#include<stdlib.h>
struct STACK
{
   int info;
   struct STACK *next;
};
struct STACK *top=NULL;
void push();
void pop();
void display();

void main()
{  while(1)
     {
         printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        int ch;
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\n Invalid Choice.");

        }
    }
}
void push()
{
  struct STACK *curr;
  curr=(struct STACK*)malloc(sizeof(struct STACK));

  if(curr==NULL)
  {
      printf("\nOut of memory");
      exit(1);
  }
  int x;
  printf("enter the value:");
  scanf("%d",&x);
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
void display()
{
    printf("\nDisplay:\n");
    struct STACK *temp=top;
    if(temp==NULL)
    {
        printf("\nStack is empty");
        exit(1);
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->info);
        temp=temp->next;
    }
}
