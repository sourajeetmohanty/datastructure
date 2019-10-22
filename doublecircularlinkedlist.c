#include<stdio.h>
#include<stdlib.h>
struct DLINK
{
    struct DLINK *prev;
    int info;
    struct DLINK *next;
};
struct DLINK *start;

void main()
{
    createList();
    display();
    //insertatbegin();
    //display();
    //insertatend();
    //display();
    //deleteatbegin();
    //display();
    deleteatend();
    display();

}
void createList()
{
    start=(struct DLINK*)malloc(sizeof(struct DLINK));
    if(start==NULL)
    {
        printf("unable to allocate memory");
        exit(1);
    }
    struct DLINK *temp=start;
    printf("Enetr the value:");
    scanf("%d",&temp->info);
    temp->prev=NULL;
    temp->next=NULL;
    char ch;
    printf("do you wish to continue(y/n):");
    fflush(stdin);
    scanf("%c",&ch);
    struct DLINK *curr;
    while(ch=='y')
    {
        curr=(struct DLINK*)malloc(sizeof(struct DLINK));
        if(curr==NULL)
        {
            printf("Out of memory");
            exit(1);
        }
        temp->next=curr;
        curr->prev=temp;
        temp=temp->next;
        printf("Enter value of node:");
        scanf("%d",&temp->info);
        temp->next=NULL;
        printf("Do you wish to continue(y/n):");
        fflush(stdin);
        scanf("%c",&ch);
    }
    temp->next=start;
    start->prev=temp;
}
void display()
{   printf("display in forward order:\n");
    struct DLINK *temp=start;
    struct DLINK *temp1=NULL;
    do
    {   temp1=temp;
        printf("%d--%d--->%d\n",temp,temp->info,temp->next);
        temp=temp->next;
    }while(temp!=start);
    struct DLINK *temp2=temp1;
    printf("display in reverse order:\n");
    do
    {
        printf("%d--%d--->%d\n",temp1,temp1->info,temp1->prev);
        temp1=temp1->prev;
    }while(temp1!=temp2);
}
void insertatbegin()
{
    struct DLINK *beg=(struct DLINK*)malloc(sizeof(struct DLINK));
    printf("insert the value at begining:");
    scanf("%d",&beg->info);
    beg->next=start;
    start->prev=beg;
    struct DLINK *temp=start;
    while(temp->next!=start)
    {
        temp=temp->next;
    }
    temp->next=beg;
    beg->prev=temp;
    start=beg;
}
void insertatend()
{
    struct DLINK *node=(struct DLINK*)malloc(sizeof(struct DLINK));
    struct DLINK *temp=start;
    while(temp->next!=start)
    {
        temp=temp->next;
    }
    printf("insert the value at the end:");
    scanf("%d",&node->info);

    node->next=start;
    start->prev=node;
    temp->next=node;
    node->prev=temp;
}
void deleteatbegin()
{
    printf("deleting element at beginning...\n");
    struct DLINK* temp=start;
    struct DLINK* temp1=start;
    while(temp->next!=start)
    {
        temp=temp->next;
    }
    start=start->next;
    start->prev=temp;
    temp->next=start;
    free(temp1);
}
void deleteatend()
{
    printf("deleting element at end...\n");
    struct DLINK* temp1=start;
    while(temp1->next!=start)
    {
        temp1=temp1->next;
    }
    struct DLINK* temp2=temp1->prev;
    temp2->next=start;
    start->prev=temp2;
    free(temp1);
}
