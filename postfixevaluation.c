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
    int i=0;
    char exp[200];
    p->top=-1;
    int a,b,res;
    printf("Enter the expression::");
    scanf("%s",&exp);
    for(i=0;exp[i]!='\0';i++)
    {
        if(isalnum(exp[i]))
           {
               push(exp[i]);
           }
        else{
            a=pop()-48;
            b=pop()-48;
            if(exp[i]=='+')
                res=b+a;
            else if(exp[i]=='-')
                res=b-a;
            else if(exp[i]=='*')
                res=b*a;
            else if(exp[i]=='/')
                res=b/a;
            char x=res;
            push(x+48);

        }
    }
              int x=p->items[p->top]-48;
            printf("\n%d",x);
}
void push( char x)
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
