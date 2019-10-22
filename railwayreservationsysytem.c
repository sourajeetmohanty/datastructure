#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int slno;
    char name[20];
    int age;
    struct NODE *next;
};
struct NODE *start;
struct NODE *front;
struct NODE *rear;
int size=3;
int count=0;
int num=0;

struct NODE* deQueue();
void create();
int reserve();
int cancel(int);
void enQueue(struct NODE*);
void display();

void create()
{
    struct NODE *temp;
    temp=(struct NODE *)malloc(sizeof(struct NODE));

    temp->slno=1;
    printf("Name: ");
    scanf("%s",&temp->name);
    printf("Age: ");
    scanf("%d",&temp->age);
    temp->next=NULL;
    start=temp;
    num++;
}
int reserve()
{
    if(start==NULL)
    {
        create();
        return 1;
    }
    else
    {
        struct NODE *temp,*new_node;
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        new_node=(struct NODE*)malloc(sizeof(struct NODE));
        printf("Name: ");
        scanf("%s",&new_node->name);
        printf("Age:");
        scanf("%d",&new_node->age);
        new_node->next=NULL;
        if(num<size)
        {
            num++;
            new_node->slno=num;
            temp->next=new_node;
            return 1;
        }
        else
        {
            enQueue(new_node);
            return 0;
        }
    }
}
int cancel(int reg)
{
    struct NODE *ptr,*preptr,*new;
    ptr=start;
    preptr= NULL;
    if(start==NULL)
    {
        return -1;
    }
    if(ptr->next==NULL && ptr->slno==reg)
    {
        start=NULL;
        num--;
        free(ptr);
        return 1;
    }
    else
    {
       while(ptr->slno!=reg && ptr->next!=NULL)
       {
           preptr=ptr;
           ptr=ptr->next;
       }
       if(ptr==NULL && ptr->slno!=reg)
       {
           return -1;
       }
       else
       {
          if(preptr==NULL)
          {
              start=start->next;
              free(ptr);
              preptr=start;
          }
          else
          {
           preptr->next=ptr->next;
          free(ptr);
          }
          new=deQueue();
          new->slno=reg;
          while(preptr->next!=NULL)
          {
              preptr=preptr->next;
          }
          preptr->next=new;

          struct NODE *temp=front;
          while(temp!=NULL)
          {
              temp->slno--;
              temp=temp->next;
          }
          return 1;
       }
    }
}
void enQueue(struct NODE *new_node)
{
    count++;
    if(rear==NULL)
    {
        rear=new_node;
        rear->slno=count;
        rear->next=NULL;
        front=rear;
    }
    else
    {struct NODE *temp;
    temp=new_node;
    rear->next=temp;
    temp->slno=count;
    temp->next=NULL;
    rear=temp;
    }
}
struct NODE* deQueue()
{
    struct NODE *front1;
    front1=front;
    if(front==NULL)
    {
        return NULL;
    }
    else
    {
        count--;
        if(front->next!=NULL)
        {
            front=front->next;
            front1->next=NULL;
            return front1;
        }
        else
        {
            front=NULL;
            rear=NULL;
            return front1;
        }

    }
}
void display()
{
    struct NODE *temp;
    temp=start;
    while(temp!=NULL)
    {
     printf("\nTicket number:%d\n",temp->slno);
     printf("Name: %s ,Age: %d \n",temp->name,temp->age);
     temp=temp->next;
    }
    temp=front;
    while(temp!=NULL)
    {
        printf("\nWaiting Number:%d\n",temp->slno);
        printf("Name: %s ,Age: %d \n\n",temp->name,temp->age);
        temp=temp->next;
    }
}
void main()
{
    int choice,status=0,canc=0,reg=0;
    start=NULL;
    rear=NULL;
    front=NULL;
    printf("\t*** RAILWAY RESERVTION ****\t\n");
    int ch=0;
    while(ch!=4)
    {
        printf("\nDo you want to...");
        printf("\n 1. Reserve a ticket");
        printf("\n 2. Cancel Booking ");
        printf("\n 3. display passenger details");
        printf("\n 4.Exit\n\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            status=reserve();
            if(status==0)
            {
                printf("\nBOOKING full!!!\n you are added to waiting list.waiting list number %d",count);
            }
            else
            {
                printf("\n Booking Successfull!!!Enjoy your journey!ticket no is %d\n\n",num);
            }
            break;
        case 2:
            printf("\n Give the ticket number to be cancelled\n");
            scanf("%d",&reg);
            if(reg>num)
            {
                printf("Invlid!!!");
            }
            else
            {
                canc=cancel(reg);
                if(canc==-1)
                {
                    printf("\nTicket number invalid!!!\n");
                }
                else
                {
                    printf("\nTicket cancelled successfully\n");
                }
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        }
    }
}
