#include<stdio.h>
#include<stdlib.h>
struct link
{
    int info;
    struct link *next;
};
struct link *start;

void fun(struct link* x)
{
    if(x==NULL)
        return;
    fun(x->next);
    printf("%d",x->next);
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
void main()
{
    createList();
    fun(start);
}
