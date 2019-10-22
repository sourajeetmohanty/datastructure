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
    printf("header linked list created\n");
    temp->info=0;
    temp->next=NULL;
    char ch;
    printf("Do you wish to add a node(y/n):");
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
        start->info+=1;
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
