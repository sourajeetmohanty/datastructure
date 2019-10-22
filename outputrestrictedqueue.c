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
	int val2;
	int res;
	while(1)
	{
		printf("\n 1. INSERT at front");
		printf("\n 2. INSERT at rear");
		printf("\n 3. DELETE");
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
                insertatfront(val);
                break;
            }
        case 2:
            {
                printf("\nEnter the value you wish to enter:");
                scanf("%d",&val2);
                insertatrear(val2);
                break;

            }
        case 3:
            {
                res=delete();
                printf("\n%d Deleted from the queue.",res);
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
void insertatrear(int x)
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

    printf("Element inserted at rear...");
}
void insertatfront(int x)
{  struct queue *input;
      input=(struct queue*)malloc(sizeof(struct queue));
        if(input==NULL)
		{
			printf("\n Out of memory");
			exit(1);
		}
    input->info=x;
    if(front==NULL)
    {
        front=input;
        front->next=NULL;
        rear=front;
        prev=rear;
    }
    else
    {
        input->next=front;
        front=input;
    }
   printf("Element inserted at front...");
}

int delete()
{
	int res;
	struct queue *temp;
	if(front==NULL)
	{
		printf("\n queue is empty");
		exit(1);
	}
	res=front->info;
	temp=front;
	front=front->next;
	free(temp);
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
