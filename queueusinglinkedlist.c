#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int info;
	struct queue *next;
};

struct queue *front;
struct queue *rear;
struct queue *prev;

void insert(int);
void display();
int Delete();

int main()
{
	int ch;
	int val;
	int res;
	while(1)
	{
		printf("\n 1. INSERT");
		printf("\n 2. DELETE");
		printf("\n 3. DISPLAY");
		printf("\n 4. EXIT");
		printf("\n Enter your chccccccccccccccccccccccccccccccccccccccccccccoice :");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
			{
				printf("\n Enter a value to insert :");
				scanf("%d",&val);
				insert(val);
				break;
			}

			case 2:
			{
				res=Delete();
				printf("\n deleted element is %d",res);
				break;
			}

			case 3:
			{
				display();
				break;
			}

			case 4:
			{
				exit(1);
				break;
			}


		}
	}
}

void insert(int val)
{
	if(rear==NULL)
	{
		rear=(struct queue*)malloc(sizeof(struct queue));
		if(rear==NULL)
		{
			printf("\n Out of memory");
			exit(1);
		}
		front =rear;
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
	rear->info=val;
	rear->next=NULL;
	prev=rear;

	printf("\n element inserted");
}
int Delete()
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


