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
{   p->top=-1;
    char input[100];
    printf("Enter the string:");
    scanf("%s",&input);
    STACK->items=input;
    STACK->top=input.strlen()-1;
    printf("string in reverse order:");
    for(int i=0;input[i]!='\0';i++)
        push(input[i]);
    display();
}
void push(char x)
{   if(p->top==99)
    {
        printf("\nStack is full.");
        exit(1);
    }
    p->top++;
    p->items[p->top]=x;
}
void display()
{
    int i;
    char x;
    if(p->top==-1)
    {
        printf("\nStack is empty.");
        exit(1);
    }
    for(i=p->top;i>=0;i--)
    {   x=p->items[i];
        printf("%c",x);
    }
}
