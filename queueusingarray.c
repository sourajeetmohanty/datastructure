#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int items[10];
	int front;
	int rear;
};
struct queue q;
struct queue *p = &q;

void insert(int);
void Delete();
void display();

int main()
{
	p->front = 0;
	p->rear = -1;

	int val,ch;
	while(1)
	{
		printf("\n 1. INSERT");
		printf("\n 2. DELETE");
		printf("\n 3. DISPLAY");
		printf("\n 4. EXIT");
		printf("\n Enter your choice :");
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
				Delete();
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
void insert(int x)
{
	if(p->rear==9)
	{
		printf("\n QUEUE IS FULL");
		exit(1);
	}
	p->rear++;
	p->items[p->rear]=x;

	printf("element inserted");
}

void Delete()
{
	if(p->front>p->rear)
	{
		printf("\n QUEUE IS EMPTY");
		exit(1);
	}
	p->front++;
}

void display()
{
	if(p->front>p->rear)
	{
		printf("\n QUEUE IS EMPTY");
		exit(1);
	}
	int i;
	for(i=p->front;i<=p->rear;i++)
	{
		printf("\n %d",p->items[i]);
	}
}

