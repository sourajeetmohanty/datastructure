#include<stdio.h>
#include<stdlib.h>
struct DLINK
{
    struct DLINK *prev;
    int info;
    struct DLINK *next;
};
struct DLINK *start;
void createList();
void display();
void insertatbegin();
void insertatend();
void insertatpos();

void main()
{
    createList();
    //insertatbegin();
   // insertatend();
    //display();
    //insertatpos();
    //display();
   // deleteatbegin();
    //display();
   // deleteatend();
    display();
    deleteatpos();
    display();
    //reversedisplay();
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
}
void display()
{   printf("display in forward order:\n");
    struct DLINK *temp=start;
    struct DLINK *temp1=NULL;
    while(temp!=NULL)
    {   temp1=temp;
        printf("%d\n",temp->info);
        temp=temp->next;
    }
    printf("display in reverse order:\n");
    while(temp1!=NULL)
    {
        printf("%d\n",temp1->info);
        temp1=temp1->prev;
    }
}
void reversedisplay()
{
    printf("reverse order display:\n");
    struct DLINK *temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->info);
        temp=temp->prev;
    }
}
void insertatbegin()
{
    struct DLINK *beg=(struct DLINK*)malloc(sizeof(struct DLINK));
    printf("insert the value at begining:");
    scanf("%d",&beg->info);
    beg->next=start;
    start->prev=beg;
    beg->prev=NULL;
    start=beg;
}
void insertatend()
{
    struct DLINK *node=(struct DLINK*)malloc(sizeof(struct DLINK));
    struct DLINK *temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("insert the value at the end:");
    scanf("%d",&node->info);

    node->next=NULL;
    temp->next=node;
    node->prev=temp;
}
void insertatpos()
{
    struct DLINK *node=(struct DLINK*)malloc(sizeof(struct DLINK));
    struct DLINK *temp1=start;
    struct DLINK *temp2;
    int i=1;
    int pos;
    printf("insert the position u want to enter:");
    scanf("%d",&pos);
    while(i<pos&& temp1!=NULL)
    {   temp2=temp1;
        temp1=temp1->next;
        i++;
    }
    if(temp1==NULL|| pos<=0)
    {
        printf("INVALID LOCATION");
        exit(1);
    }
    if(temp1->next==NULL||pos==1)
    {
        printf("operation not allowed");
        exit(1);
    }
    printf("enter the value:");
    scanf("%d",&node->info);

    node->prev=temp2;
    node->next=temp1;
    temp1->prev=node;
    temp2->next=node;
}
void deleteatbegin()
{
    printf("deleting element at beginning...\n");
    struct DLINK* temp=start;

    start=start->next;
    start->prev=NULL;
    free(temp);
}
void deleteatend()
{
    printf("deleting element at end...\n");
    struct DLINK* temp1=start;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    struct DLINK* temp2=temp1->prev;
    temp2->next=NULL;
    free(temp1);
}
void deleteatpos()
{ int pos;
    printf("Enter the position u want to delete:");
    scanf("%d",&pos);

    int i=1;
     struct DLINK *temp1=start;
    struct DLINK *temp2;
    struct DLINK *node;
    while(i<pos&& temp1!=NULL)
    {   i++;
        temp2=temp1;
        temp1=temp1->next;
    }
     if(temp1==NULL|| pos<=0)
    {
        printf("INVALID LOCATION");
        exit(1);
    }
    if(temp1->next==NULL||pos==1)
    {
        printf("operation not allowed");
        exit(1);
    }
    node=temp1->next;
    temp2->next=node;
    node->prev=temp2;
    free(temp1);

}
