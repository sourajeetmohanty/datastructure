#include<stdio.h>
#include<stdlib.h>
struct link
{
    int info;
    struct link *next;
};
struct link *start;
void createList();
void display();
void insertatbegin();
void insertatend();
void insertatposition();
void deleteatbeginning();
void deleteatend();
void deleteatpos();

void main()
{

     createList();
     //insertatbegin();
    // insertatend();
    // insertatposition();
     display();
    // deleteatbeginning();
    // display();
     //deleteatend();
     deleteatpos();
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

void insertatbegin()
{
struct link *node=(struct link*)malloc(sizeof(struct link));
    if(node==NULL)
    {
        printf("unable to allocate memory");
        exit(1);
    }
    printf("Enter the value at beginning:");
    scanf("%d",&node->info);
    node->next=start;
    start=node;
}
void insertatend()
{
     struct link *temp=start;
     struct link *node=(struct link*)malloc(sizeof(struct link));
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("enter the value at end:");
    scanf("%d",&node->info);
    node->next=NULL;
    temp->next=node;
}
void insertatposition()
{
    struct link *node=(struct link*)malloc(sizeof(struct link));
    printf("enter value of new node:");
    scanf("%d",&node->info);
    int loc;
    printf("enter location:");
    scanf("%d",&loc);

    int i=1;
    struct link *temp1=start;
    struct link *temp2=NULL;
    while(i<loc && temp1!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
        i++;
    }
    if(temp1==NULL|| loc<=0)
    {
        printf("INVALID LOCATION");
        exit(1);
    }
    if(temp1->next==NULL||loc==1)
    {
        printf("operation not allowed");
        exit(1);
    }
    node->next=temp1;
    temp2->next=node;

}
void deleteatbeginning()
{
    struct link *temp=start;
    start=start->next;
    free(temp);
    printf("deleting first element");
}

void deleteatend()
{
    struct link *temp1=start;
    struct link *temp2;
    printf("deleting at end");
    while(temp1->next!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next=NULL;
    free(temp1);
}
void deleteatpos()
{
    struct link *temp1=start;
    struct link *temp2;
    int loc,i=1;
    printf("enter the location of deletion:");
    scanf("%d",&loc);

    while(i<loc&&temp1!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
        i++;
    }
     if(temp1==NULL|| loc<=0)
    {
        printf("INVALID LOCATION");
        exit(1);
    }
    if(temp1->next==NULL||loc==1)
    {
        printf("operation not allowed");
        exit(1);
    }
    temp2->next=temp1->next;
    free(temp1);
}
