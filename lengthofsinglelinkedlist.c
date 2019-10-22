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
    //length();
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
void length()
{   int i=0;
    struct link *temp=start;
    while(temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    printf("\nThe length of the linked list is:%d\n",i);
}
void swapelements()
{
    int curr;
    struct link *temp1=start;
    struct link *temp2=temp1->next;

    while(temp1->next!=NULL)
    {
        curr=temp2->info;
        temp2->info=temp1->info;
        temp1->info=curr;

        temp1=temp2->next;
        if(temp1==NULL)
            break;
        temp2=temp1->next;
    }
}
