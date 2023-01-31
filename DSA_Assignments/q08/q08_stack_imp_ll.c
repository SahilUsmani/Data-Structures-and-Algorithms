/* STACK IMPLEMENTATION (LIFO) USING LINKED LISTS */

#include<stdio.h>
#include<stdlib.h>
void push(int);
int pop(void);
int peek(void);
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

void push(int element)
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
	printf("The Pushed Element is %d\n\n", temp->data);
	return;
}

int pop()
{	
	int x = -1;

	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	
	if(list!=NULL)
	{
		if(list->next==NULL)
		{
			temp = list;
			x = temp->data;
			list = temp->next;
			free(temp);
		}

		else{
		
			tos = list;

			while(tos->next->next!=NULL)
				tos = tos->next;
			temp = tos->next;
			x = temp->data;
			tos->next = NULL;
			free(temp);
		}	
	return x;
	}
}

int peek(void)                                  // To Display the Top of Stack
{
	int x = -1;

	if(list!=NULL)
	{
		tos = list;

		while(tos->next!=NULL)
			tos = tos->next;
		x = tos->data;
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
		printf("Press 1 to Push the element\n");
		printf("Press 2 to Display the contents of the stack\n");
		printf("Press 3 to Pop the element\n");
		printf("Press 4 to see Top of Stack\n");
		printf("Press 0 to exit from the program\n");
		scanf("%d", &n);

		switch(n)
		{
			case 1:
				printf("\nEnter the element you want to Push:\n");
				scanf("%d",&ele);
				push(ele);
				break;

			case 2:
				printf("\nThe contents of the stack are:\n");
				Display();
				break;

			case 3:
				printf("\nThe Popped element is %d\n\n", pop());
				break;

			case 4:
				printf("\nThe Top of Stack is %d\n\n", peek());
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
