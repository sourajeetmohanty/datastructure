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
    createlist();
    display();
    //insertatbegin();
   // display();
   // insertatend();
   // display();
    //deleteatbeginning();
   // display();
   // deleteatend();
   // display();
    isCircular();
}
void createlist()
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
    temp->next=start;
}
void display()
{
    printf("\nDisplay:\n");
    struct link *temp=start;


    do
    {
        printf("%d--%d--->%d\n",temp,temp->info,temp->next);
        temp=temp->next;
    }while(temp!=start);

}
void insertatbegin()
{    struct link *temp=start;

struct link *node=(struct link*)malloc(sizeof(struct link));
    if(node==NULL)
    {
        printf("unable to allocate memory");
        exit(1);
    }
    printf("Enter the value at beginning:");
    scanf("%d",&node->info);
    node->next=start;
    while(temp->next!=start)
    {
        temp=temp->next;
    }
    start=node;
    temp->next=start;
}
void insertatend()
{
    struct link *temp=start;
    struct link *node=(struct link*)malloc(sizeof(struct link));
    if(node==NULL)
    {
        printf("unable to allocate memory");
        exit(1);
    }
    printf("\nEnter the value at the end:");
    scanf("%d",&node->info);
    while(temp->next!=start)
    {
        temp=temp->next;
    }
    temp->next=node;
    node->next=start;
}
void deleteatbeginning()
{
     struct link *temp1=start;
     struct link *temp2=start;
     printf("\ndeleting at beginning...");
     while(temp1->next!=start)
    {
        temp1=temp1->next;
    }
    temp1->next=start->next;
    start=start->next;
    free(temp2);
}
void deleteatend()
{
    struct link *temp1=start;
    struct link *temp2;
    printf("\ndeleting at end...\n");
    while(temp1->next!=start)
    {   temp2=temp1;
        temp1=temp1->next;
    }

    temp2->next=start;
    free(temp1);

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
