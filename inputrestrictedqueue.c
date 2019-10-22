#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int info;
    struct queue *next;
};
struct queue *prev;
struct queue *rear;
struct queue *front;

void main()
{
int ch;
	int val;
	int res;
	while(1)
	{
		printf("\n 1. INSERT");
		printf("\n 2. DELETE from front");
		printf("\n 3. DELETE from rear");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
        printf("\nEnter your choice:");
		scanf("%d", &ch);

		switch(ch)
		{
        case 1:
            {
                printf("\nEnter the value you wish to enter:");
                scanf("%d",&val);
                insert(val);
                break;
            }
        case 2:
            {
                res=deletefromfront();
                printf("\n%d Deleted from front",res);
                break;
            }
        case 3:
            {
                res=deletefromrear();
                printf("\n%d Deleted from rear.",res);
                break;
            }
        case 4:
            {
                display();
                break;
            }

        case 5:
			{
				exit(1);
				break;
			}

		}
     }


}
void insert(int x)
{
    if(front==NULL)
    {
        rear=(struct queue*)malloc(sizeof(struct queue));
        if(rear==NULL)
		{
			printf("\n Out of memory");
			exit(1);
		}
		front=rear;
    }
    else
    {
        rear=(struct queue*)malloc(sizeof(struct queue));
        if(rear==NULL)
		{
			printf("\n Out of memory");
			exit(1);
		}

		prev->next=rear;
    }
    rear->info=x;
    rear->next=NULL;
    prev=rear;

    printf("Element inserted.....");
}
int deletefromfront()
{   int res;
    struct queue* temp;
    if(front==NULL)
    {
        printf("Underflow..");
        exit(1);
    }
    temp=front;
    res=front->info;
    front=front->next;
    free(temp);
    return res;
}
int deletefromrear()
{
    int res;
    struct queue* temp1=front;
    struct queue* temp2;
    if(front==NULL)
    {
        printf("Underflow..");
        exit(1);
    }
    while(temp1->next!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
    }

    res=rear->info;
    rear=temp2;
    rear->next=NULL;
    free(temp1);
    prev=rear;
    return res;
}
void display()
{
  	int i;
	struct queue *temp;
	if(front==NULL)
	{
		printf("\nqueue is empty");
		exit(1);
	}
	temp=front;
	while(temp!=NULL)
	{
		printf("\n%d",temp->info);
		temp=temp->next;
	}
}
