#include<stdio.h>
#include<stdlib.h>
struct link
{
    int info;
    struct link *next;
};
int count=0;
struct link *start;
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
    count++;
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
        count++;
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
void bubblesort()
{    struct link *temp1;
     struct link *temp2;
     int i=0;
     int temp;
     while(i<count)
     {   int j=0;
         temp1=start;
         while(temp1->next!=NULL&&j<count-i-1)
         {
            temp2=temp1->next;
            if(temp1->info>temp2->info)
                {
                    temp=temp1->info;
                    temp1->info=temp2->info;
                    temp2->info=temp;
                }
            temp1=temp1->next;
            j++;
         }
         i++;
     }
}
void main()
{
    createList();
    display();
    bubblesort();
    display();
}
