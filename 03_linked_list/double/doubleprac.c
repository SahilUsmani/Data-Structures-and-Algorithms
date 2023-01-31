#include<stdio.h>
#include<stdlib.h>
void insert_at_beg(int);
void insert_at_end(int);
void insert_before(int, int);
void specific_position(int);
void forward_traverse(void);
void menu(void);

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *dll;
struct node *current;

void main()
{
	dll = NULL;
	menu();
}

void insert_at_beg(int ele)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));

	temp->data = ele;
	temp->prev = NULL;

	if(dll==NULL)
	{
		temp->next = NULL;
		dll = temp;
	}

	else
	{
		temp->next = dll;
		dll = temp;
	}
}

void insert_at_end(int ele)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));

	temp->data = ele;
	temp->next = NULL;

	if(dll==NULL)
	{
		temp->prev = NULL;
		dll = temp;
	}

	else
	{
		current = dll;
		while(current->next!=NULL)
		{
			current = current->next;
		}
		temp->prev = current;
		current->next = temp;
	}
}

void insert_before(int search, int ele)
{	if(dll==NULL)
	{
		printf("Element not found because the list doesn't exist\n");
	}
	else
	{	
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = ele;

		current = dll;
		while(current->next!=NULL && current->data!=search)
			current = current->next;
		if(current->data!=search)
			printf("Invalid input: Element not found\n");
		else{
			temp->next = current;
			temp->prev = current->prev;
			current->prev = temp;
			current->prev->next = temp;
		}
	}

}

void insert_after(int search, int ele)
{}

void specific_position(int ele)
{
	int pos;
	int i =1;
	printf("Enter the position you want to insert your data into: ");
	scanf("%d", &pos);
	
	current = dll;
	while(current!=NULL)
	{
		current = current->next;
		i++;
	}

	if(pos>i)
		printf("Invalid Position\n");
	else
	{
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));

		current = dll;
		while(pos-1>0){
			current = current->next;
			pos--;
		}
		temp->data = ele;
		temp->next = current;
		temp->prev = current->prev;
		current->prev->next = temp;
		current->prev = temp;
	}


}

delete_specific_position(int pos)
{
	int i = 1;
	struct node* temp;
	
	current = dll;
	while(current!=NULL)
	{
		current = current->next;
		i++;
	}





}

delete_specific_element()
{}

void forward_traverse(void)
{
	current = dll;
	if(dll!=NULL)
	{
		while(current!=NULL)
		{	
			printf("%d ", current->data);
			current = current->next;
		}	
	printf("\n");
	}

	else
		printf("The List is Empty\n");
}

void menu(void)
{
	int n;
	int element;
	int sele;
	while(1)
	{
		printf("Press 1 to insert at beg\n");
		printf("Press 2 to insert at end\n");
		printf("Press 3 to insert before an element\n");
		printf("Press 4 to insert in a specific position\n");
		printf("Press 5 to traverse forward\n");
		printf("Press 0 to exit from the program\n");
		scanf("%d", &n);

		switch(n)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d", &element);
				insert_at_beg(element);
				break;

			case 2:
				printf("Enter the element: ");
				scanf("%d", &element);
				insert_at_end(element);
				break;

			case 3:
				printf("Enter the element before you want to enter your data: ");
				scanf("%d", &sele);
				printf("Enter the data you want to insert: ");
				scanf("%d", &element);
				insert_before(sele, element);
				break;

			case 4:
				printf("Enter the element: ");
				scanf("%d", &element);
				specific_position(element);
				break;
			case 5:
				printf("The contents in forward direction: ");
				forward_traverse();
				break;

			case 0:
				exit(0);
				break;

			default: 
				break;
		}
	}

}
