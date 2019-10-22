#include<stdio.h>
#include<stdlib.h>
struct STACK
{
  int items[10];
  int top;
};
struct STACK s;
struct STACK *p=&s;
void push();
void pop();
void display();

void main()
{

    p->top=-1;
    while(1)
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
    if(p->top==9)
    {
        printf("\nThe stack is full.");
        exit(1);
    }

    p->top++;
    int x;
    printf("\nEnter the value :");
    scanf("%d",&x);

    p->items[p->top]=x;
    printf("\nElement pushed to the stack.");
}
void pop()
{
    if(p->top==-1)
    {
        printf("\nThe stack is empty.");
        exit(1);
    }
    int x=p->items[p->top];
    p->top--;
    printf("\n %d deleted from the stack.",x);
}
void display()
{
    int i,x;
    if(p->top==-1)
    {
        printf("\nStack is empty.");
        exit(1);
    }
    printf("\nElements in the stack are:");
    for(i=p->top;i>=0;i--)
    {   x=p->items[i];
        printf("\n %d \n",x);
    }
}
