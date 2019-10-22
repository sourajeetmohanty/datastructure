#include<stdio.h>
#include<stdlib.h>
struct STACK
{
   char items[100];
   int top;
};
struct STACK s;
struct STACK *p=&s;
void main()
{
    p->top=-1;
    int n;
    printf("enter the range:");
    scanf("%d",&n);
    push(0);
    push(1);
    int i,x,y;
    for(i=2;i<=n;i++)
    {
        x=pop();
        y=pop();
        p->top+=2;
        push(x+y);
    }
    display();
}
void push(int x)
{
  p->top++;
  p->items[p->top]=x;
}
int pop()
{
  if(p->top==-1)
  {
      return -1;
  }
  else
  {
      int x=p->items[p->top];
      p->top--;
      return x;
  }
}
void display()
{
    int i,x;
    if(p->top==-1)
    {
        printf("\nStack is empty.");
        exit(1);
    }
    printf("\nElements in the stack are:\n");
    for(i=0;i<p->top;i++)
    {   x=p->items[i];
        printf("%d \n",x);
    }
}
