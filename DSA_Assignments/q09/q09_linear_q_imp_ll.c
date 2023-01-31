/* LINEAR QUEUE IMPLEMENTATION (FIFO) USING LINKED LISTS */

#include<stdio.h>
#include<stdlib.h>
void enque(int);
int dequeue(void);
int size(void);
void Display(void);
void menu(void);

struct node{
	int data;
	struct node *next;
};

struct node *tos;
struct node *list;

void main()
{
	list = NULL;
	menu();
	return;
}

void enque(int element)
{	
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = element;
	temp->next = NULL;

	if(list==NULL)
	{
		list = temp;
	}

	else
	{
		tos = list;

		while(tos->next!=NULL)
			tos = tos->next;
		tos->next = temp;
	}
	printf("The Enqueued Element is %d\n\n", temp->data);
	return;
}

int dequeue()
{	
	int x = -1;

	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(list!=NULL)
	{
	
			temp = list;
			x = temp->data;
			list = temp->next;
			free(temp);
	}	
	return x;
}

int size(void)                                  // To Display size of queue
{
	int x = 0;

	if(list!=NULL)
	{
		tos = list;

		while(tos!=NULL)
		{
			tos = tos->next;
			x++;
		}

	}
	return x;
}

/*int IsEmpty(void)
{
	if(sta.tos == -1)
		return 1;
	return 0;
}*/

/*int IsFull(void)
{
	if(sta.tos==(sta.size-1))
		return 1;
	return 0;
}*/

void Display(void)
{
	if(list!=NULL)
	{
		tos = list;

		while(tos!=0)
		{
			printf("%d ", tos->data);
			tos = tos->next;
		}
		printf("\n\n");
	}

	else
		printf("The Stack is Empty");
	return;
}

void menu(void)
{
	int n;
	int ele;
	while(1)
	{
		printf("Press 1 to Enqueue the element\n");
		printf("Press 2 to Display the contents of the queue\n");
		printf("Press 3 to Dequeue the element\n");
		printf("Press 4 to see the size\n");
		printf("Press 0 to exit from the program\n");
		scanf("%d", &n);

		switch(n)
		{
			case 1:
				printf("\nEnter the element you want to Enqueue:\n");
				scanf("%d",&ele);
				enque(ele);
				break;

			case 2:
				printf("\nThe contents of the stack are:\n");
				Display();
				break;

			case 3:
				printf("\nThe Dequeued element is %d\n\n", dequeue());
				break;

			case 4:
				printf("\nThe size of the queue is %d\n\n", size());
				break;

			case 0:
				exit(0);
				break;

			default:
				printf("\nYou have entered an Invalid Input\n");
				break;
		}
	}
	return;
}
