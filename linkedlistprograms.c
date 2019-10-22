#include<stdio.h>
#include<stdlib.h>
struct link
{
    int info;
    struct link *next;
};
struct link *start;

void main()
{
    createList();
    display();
    //isCircular();
    //movelasttofirst();
    swapelements();
    display();
}
void createList()
{
     start=(struct link*)malloc(sizeof(struct link));
    if(start==NULL)
    {
        printf("unable to allocate memory");
        exit(1);
    }
    struct link *temp=start;
    printf("Enetr the value:");
    scanf("%d",&temp->info);
    temp->next=NULL;
    char ch;
    printf("Do you wish to continue(y/n):");
    fflush(stdin);
    scanf("%c",&ch);
    while(ch=='y')
    {
        temp->next=(struct link*)malloc(sizeof(struct link));
        if(temp->next==NULL)
        {
            printf("unable to allocate memory");
            exit(1);
        }
        temp=temp->next;
        printf("Enter the value:");
        scanf("%d",&temp->info);
        temp->next=NULL;
        printf("Do you wish to continue(y/n):");
        fflush(stdin);
        scanf("%c",&ch);
    }
}
void display()
{
    printf("\nDisplay:\n");
    struct link *temp=start;
    while(temp!=NULL)
    {
        printf("%d\n",temp->info);
        temp=temp->next;
    }
}
void isCircular()
{
    struct link *temp=start;
    while(temp->next!=start&&temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
        printf("it is a single linked list.\n");
    else
        printf("it is a single circular linked list.\n");
}
void movelasttofirst()
{
    struct link *temp1=start;
    struct link *temp2;
    while(temp1->next!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next=NULL;
    temp1->next=start;
    start=temp1;
}
void swapelements()
{
     struct link *temp1=start;
    struct link *temp2;
    struct link *temp3;

    temp2=temp1->next;
    temp1->next=temp2->next;
    temp2->next=temp1;
    start=temp2;

    while(temp1->next!=NULL)
    {
        temp3=temp1;
        temp1=temp1->next;

        temp2=temp1->next;
        if(temp2==NULL)
            break;
       temp1->next=temp2->next;
       temp2->next=temp1;
       temp3->next=temp2;

  }
}
